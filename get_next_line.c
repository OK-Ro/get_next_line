/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 16:29:39 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (!line)
			return (NULL);
		temp = ft_strdup(new_position + 1);
		if (!temp)
			return (free(line), NULL);
		free(*leftover);
		*leftover = temp;
		return (line);
	}
	line = ft_strdup(*leftover);
	if (!line)
		return (NULL);
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
	char		*str;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (!temp)
			return (NULL);
		free(leftover);
		leftover = temp;
		if (ft_strchr(leftover, '\n'))
			break ;	
		free(leftover);
		leftover = NULL;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	str = extract_line(&leftover);
	if (!str)
	{
		free(leftover);
		leftover = NULL;
		return(NULL);
	}
	return (str);
}
