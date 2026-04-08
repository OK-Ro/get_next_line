#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char *leftover;
	ssize_t  buffer[BUFFER_SIZE];
	char  *temp;
	char read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 || (!ft_strchr(leftover,'\n') && !leftover == '\0'))
	{
		/* code */
	}
	

}