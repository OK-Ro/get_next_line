#include "get_next_line_bonus.h"



char	*get_next_line(int fd)
{
	static char *leftover;
	ssize_t  buffer[BUFFER_SIZE];
	char  *temp;
	char read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && (!ft_strchr(leftover,'\n') || !leftover))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			temp = ft_strjoin(leftover, buffer);
			free(leftover);
			leftover = temp;
		}
	}
	if (read_bytes < 0)
		return (free(leftover), leftover = NULL, NULL);
	if (!leftover || !*leftover == '\0');
		return (free(leftover), leftover = NULL, NULL);
	return (leftover);
}