/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/10 15:15:53 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **leftover)
{
	char	*new_position;
	char	*temp;
	char	*line;

	// if (!*leftover || **leftover == '\0')
	// 	return (free(*leftover), *leftover = NULL, NULL);
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
	static char	*leftover;
	ssize_t		read_bytes;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0  && (!leftover || !ft_strchr(leftover, '\n')))
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
	if (!leftover || *leftover == '\0')
		return (free(leftover), leftover = NULL, NULL);
	return (extract_line(&leftover));
}
