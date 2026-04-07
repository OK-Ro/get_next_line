/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:50:56 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 16:10:52 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **leftover)
{
	char	*new_position;
	char	*temp;
	char	*line;

	if (!*leftover || **leftover == '\0')
	{
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
	new_position = ft_strchr(*leftover, '\n');
	if (new_position)
	{
		line = ft_substr(*leftover, 0, new_position - *leftover + 1);
		temp = ft_strdup(new_position + 1);
		free(*leftover);
		*leftover = temp;
		return (line);
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
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(leftover[fd], buffer);
		free(leftover[fd]);
		leftover[fd] = temp;
		if (ft_strchr(leftover[fd], '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&leftover[fd]));
}
