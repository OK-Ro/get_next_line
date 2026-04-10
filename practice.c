#include "get_next_line_bonus.h"

// static char extract_line(char **leftover)
// {
// 	char *newposition;
// 	char *temp;
// 	char *line;

// 	if (!leftover || **leftover == '\0')
// 		return (free(leftover), leftover = NULL, NULL);
// 	newposition = ft_strchr(leftover,'\n');
// 	if (newposition)
// 	{
// 		line = ft_substr(*leftover, 0, newposition - *leftover + 1);
// 		if (!line)
// 			return (free(*leftover), *leftover = NULL, NULL);
// 		if (*(newposition + 1))
// 			temp = ft_strdup(newposition + 	1);
// 		else
// 			temp = NULL;
// 		return (free(*leftover), *leftover = temp, line);
// 	}
// 	line = ft_strdup(*leftover);
// 	free(*leftover);
// 	*leftover = NULL;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char *leftover;
// 	ssize_t bytes_read;
// 	char *temp;
// 	char buffer[BUFFER_SIZE + 1];

// if (fd < 0 || BUFFER_SIZE < 0)
// 	return (NULL);
// bytes_read = 1;
// if (bytes_read > 0 && (!leftover || !ft_strchr(leftover, '\n')))
// {
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		temp = ft_strjoin(leftover, buffer);
// 		free(leftover);
// 		leftover = temp;
// 	}
// }
// 	if(bytes_read < 0)
// 		return (free(leftover), leftover = NULL, NULL);
// 	if (!leftover || *leftover == '\0')
// 		return (free(leftover), leftover = NULL, NULL);
// 	return (extract_line(&leftover));
// }