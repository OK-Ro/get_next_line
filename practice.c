#include "get_next_line_bonus.h"

static char extract_line(char **leftover)
{
	char *line;
	char *newposition;
	char *temp;

	if (!leftover || !**leftover == '\0')
		return (free(leftover), leftover = NULL, NULL);
	newposition =  ft_strchr(leftover, '\n');
	if (newposition)
	{
		line = ft_substr(*leftover, 0, newposition - *leftover + 1);
		if (!line)
			return (free(leftover), leftover = NULL, NULL);
		if (*(newposition + 1))
			temp = ft_strdup(*leftover);
		else
			temp = NULL;
	}
	line = ft_strdup(*leftover);
	free(*leftover);
	leftover = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char *leftover;
	char buffer[BUFFER_SIZE + 1];
	ssize_t read_byes;
	char temp;
	
	if (!fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_byes = 1;
	while (read_byes > 0 && (!leftover || !ft_strchr(leftover, '\n')))
	{
		read_byes = read(fd, buffer, BUFFER_SIZE);
		if (read_byes > 0)
		{
			buffer[read_byes] = '\0';
			temp = ft_strjoin(leftover, buffer);
			free(leftover);
			leftover = temp;
		}
	}
	if (read_byes < 0)
		return (free(leftover), leftover = NULL, NULL);
	if (!leftover || !*leftover == '\0')
		return (free(leftover), leftover = NULL, NULL);
	return (extract_line(&leftover));	
}