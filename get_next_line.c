/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 14:26:42 by rokuni           ###   ########.fr       */
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
	static char	*leftover;
	ssize_t		read_bytes;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		leftover = temp;
		if (ft_strchr(leftover, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	return (extract_line(&leftover));
}

/*
nvalid fd          : 1.OK 2.OK 3.OK 4_LEAKS.OK 5_NULL_CHECK.OK 
empty.txt           : 1.OK 2.OK 3_LEAKS.OK 4_NULL_CHECK.OK 
1char.txt           : 1.OK 2.OK 3_LEAKS.OK 4_NULL_CHECK.OK 
one_line_no_nl.txt  : 1.OK 2.OK 3_LEAKS.OK 4_NULL_CHECK.OK 
only_nl.txt         : 1.OK 2.OK 3_LEAKS.OK 4_NULL_CHECK.KO 
*/ 