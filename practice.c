#include "get_next_line_bonus.h"

static char extract_line(char **leftover)
{
	char *newposition;
	char *temp;
	char *line;

	if (!leftover || !**leftover == '\0')
		return (NULL);
	newposition = ft_strchr(*leftover, '\n');
	if (newposition)
	{
		line = ft_substr(*leftover, 0, newposition - *leftover + 1);
		if (!line)
			return (free(*leftover), *leftover = NULL, NULL);
		if (*(newposition + 1))
			temp = ft_strdup(leftover);
		else
			temp = NULL;
		return (free(*leftover), *leftover = temp, line);
	}
	line = ft_strdup(leftover);
	free(leftover);
	leftover = NULL;
	return (line);
}

