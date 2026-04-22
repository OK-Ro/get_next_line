
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD]; // persists between calls, one slot per fd
	                               // static = survives after function returns,
	                               // so next call picks up where we left off
	ssize_t		read_bytes;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1]; // +1 because read() fills BUFFER_SIZE bytes
	                                 // but C strings need a '\0' at the end,
	                                 // read() does NOT add it — we must reserve the space

	// 1) guard: reject invalid fd or misconfigured BUFFER_SIZE
	//    fd < 0      → no such file descriptor exists
	//    fd >= MAX_FD → would write outside our leftover array (buffer overflow)
	//    BUFFER_SIZE <= 0 → nonsensical config, read() would behave undefined
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);

	// 2) bootstrap read_bytes to 1 so the while condition is true on first entry
	//    without this, read_bytes is uninitialized (undefined behavior in C)
	//    and the loop might never execute, returning nothing even on a valid fd
	read_bytes = 1;

	// 3) keep reading until a '\n' is found in leftover or fd is exhausted
	//    !leftover[fd]                → nothing buffered yet, must read
	//    !ft_strchr(leftover[fd],'\n')→ have data but no newline yet, must read more
	//    both conditions together mean: "we don't have a complete line yet"
	while (read_bytes > 0 && (!leftover[fd] || !ft_strchr(leftover[fd], '\n')))
	{
		// 4) ask the OS for up to BUFFER_SIZE raw bytes from fd
		//    returns: >0 = how many bytes actually arrived
		//             0  = EOF, nothing left to read
		//            -1  = something went wrong (permissions, broken pipe, etc.)
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			// 5) null-terminate the buffer
			//    read() fills buffer with raw bytes — it does NOT add '\0'
			//    example: BUFFER_SIZE=5, file contains "hello world"
			//    after read(): buffer = ['h','e','l','l','o', ???]
			//                                                  ^ slot 5, garbage
			//    after buffer[5] = '\0': buffer = "hello"
			//    without this, ft_strjoin/strchr would read past the real data
			//    into garbage memory → undefined behavior, likely a crash or wrong output
			buffer[read_bytes] = '\0';

			// 6) glue what we just read onto the end of whatever was buffered before
			//    example: leftover[fd] = "hello"  buffer = " wor"
			//    result:  temp        = "hello wor"
			//    first call: leftover[fd] is NULL, ft_strjoin treats that as ""
			//    so temp = "" + "hello" = "hello"
			temp = ft_strjoin(leftover[fd], buffer);

			// 7) ft_strjoin allocated a brand new string for temp
			//    the old leftover[fd] is now orphaned — free it or we leak memory
			//    every call through this loop would leak the previous chunk
			free(leftover[fd]);

			// 8) point leftover[fd] at the freshly joined string
			//    this is our running accumulator — grows each iteration
			//    until a '\n' is found or fd runs dry
			leftover[fd] = temp;
		}
	}

	// 9) read() returned -1: a real OS-level error occurred
	//    we can't trust leftover[fd] anymore — free it to avoid a memory leak
	//    NULL leftover[fd] so the next call starts clean, not from corrupted data
	if (read_bytes < 0)
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);

	// 10) leftover is NULL or empty string: we hit EOF with nothing buffered
	//     this is the normal "no more lines" signal to the caller
	//     free + NULL so the next call doesn't trip over a stale empty string
	if (!leftover[fd] || *leftover[fd] == '\0')
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);

	// 11) we have data in leftover[fd] that contains a '\n' (or is the last chunk)
	//     extract_line cuts the string at '\n', returns everything up to and including it,
	//     and puts whatever came after '\n' back into leftover[fd]
	//     so the NEXT call to get_next_line starts from the remainder, not from scratch
	return (extract_line(&leftover[fd]));
}