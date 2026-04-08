# Get Next Line

*This project has been created as part of the 42 curriculum by rokuni.*

## Description

This project implements the `get_next_line` function, which reads a line from a file descriptor. The function returns one line at a time from the file descriptor, handling buffering efficiently using static variables. It's designed to work with any file descriptor, including standard input, and manages memory properly to avoid leaks.

The goal is to create a reusable function that simplifies reading lines from files or streams, teaching concepts like static variables, buffer management, and dynamic memory allocation in C.

---

## Instructions

### Compilation

Compile the source files with the required flags and define `BUFFER_SIZE` (default 42 if not specified):


```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

To test with different buffer sizes (e.g., 1, 1024, or 10000000):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

### Execution

Run the test program:

```bash
./gnl_test
```

The test reads from `test.txt` and prints each line.

### Example Usage

```c
int main(void)
{
    int fd;
    char *line;
    int line_num;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        return (1);
    }

    printf("\n========== FILE: test.txt ====================================\n");
    line_num = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %2d: %s", line_num++, line);
        free(line);
    }
    printf("Total lines: [%d]\n", line_num - 1);
    close(fd);

    return (0);
}
```

---

## Algorithm Explanation

The `get_next_line` function uses a static variable to store leftover data between calls, allowing it to handle partial reads efficiently. The algorithm works as follows:

1. **Buffering Loop**: Read data in chunks of `BUFFER_SIZE` into a buffer until a newline is found or EOF is reached. Each chunk is joined to the static `leftover` string.

2. **Line Extraction**: Once a newline is detected in `leftover`, extract the line (including the newline) and update `leftover` to contain only the remaining data.

3. **Edge Cases**: Handle cases where the file doesn't end with a newline, read errors, or empty files. Memory is freed appropriately to prevent leaks.

This approach minimizes reads by stopping as soon as a newline is found, rather than reading the entire file at once. The use of a static variable ensures state persistence across function calls for the same file descriptor.

---

## Bonus Part

### Overview

The bonus part extends `get_next_line` with two enhancements:

- **One static variable only** — the entire per-fd state is stored in a single `static char *leftover[MAX_FD]` array declaration.
- **Multiple file descriptor support** — the function can interleave reads across different fds (e.g., fd 3, 4, 5) without losing track of any read state.

### Files

| File | Description |
|------|-------------|
| `get_next_line_bonus.c` | Main function and `extract_line` helper |
| `get_next_line_bonus.h` | Header with prototype and `MAX_FD` define |
| `get_next_line_utils_bonus.c` | Same helper functions as mandatory, `_bonus` suffix |

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### How It Works

The key change is replacing the single `static char *leftover` with an array indexed by fd:

```c
static char *leftover[MAX_FD];
```

This is still **one static variable**. Each index maps to a separate fd's read state:

```
leftover[3] → state for fd 3
leftover[4] → state for fd 4
leftover[5] → state for fd 5
```

Every call to `get_next_line(fd)` only touches `leftover[fd]`, so fds never interfere with each other. `MAX_FD` is defined as `1024`, matching the typical Unix per-process file descriptor limit.

### Example Usage

```c
int	main(void)
{
	int		fd1, fd2;
	char	*line;
	int		line_num;

	// Open file1
	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 < 0)
	{
		printf("Error opening file1.txt\n");
		return (1);
	}
	
	printf("\n========== FILE 1: file1.txt ==========\n");
	line_num = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file1: %d\n", line_num - 1);
	close(fd1);
	
	// Open file2
	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		printf("Error opening file2.txt\n");
		return (1);
	}
	
	printf("\n========== FILE 2: file2.txt ==========\n");
	line_num = 1;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file2: %d\n", line_num - 1);
	close(fd2);
	
	return (0);
}
```

### Validation

An invalid fd (negative or >= `MAX_FD`) returns `NULL` immediately:

```c
if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
    return (NULL);
```

---

## Resources

- [42 Get Next Line Subject](https://cdn.intra.42.fr/pdf/pdf/118977/en.subject.pdf) - Official project description
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Explanation of static variables
- [File Descriptors in Unix](https://www.gnu.org/software/libc/manual/html_node/File-Descriptors.html) - Understanding file descriptors