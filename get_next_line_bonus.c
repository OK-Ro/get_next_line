/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:50:56 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/18 18:39:46 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **leftover)
{
	char	*new_position;
	char	*temp;
	char	*line;

	if (!*leftover || **leftover == '\0')
		return (free(*leftover), *leftover = NULL, NULL);
	new_position = ft_strchr(*leftover, '\n');
	if (new_position)
	{
		line = ft_substr(*leftover, 0, new_position - *leftover + 1);
		if (!line)
			return (free(*leftover), *leftover = NULL, NULL);
		if (*(new_position + 1))
			temp = ft_strdup(new_position + 1);
		else
			temp = NULL;
		return (free(*leftover), *leftover = temp, line);
	}
	line = ft_strdup(*leftover);
	free(*leftover);
	*leftover = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD];
	ssize_t		read_bytes;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && (!leftover[fd] || !ft_strchr(leftover[fd], '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			temp = ft_strjoin(leftover[fd], buffer);
			free(leftover[fd]);
			leftover[fd] = temp;
		}
	}
	if (read_bytes < 0)
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);
	if (!leftover[fd] || *leftover[fd] == '\0')
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);
	return (extract_line(&leftover[fd]));
}
