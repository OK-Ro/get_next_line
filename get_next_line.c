/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/06 14:42:29 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// static char	*split_line(char **leftover)
// {
// 	char	*line;
// 	char	*temp;
// 	char	*newline_pos;

// 	if (!*leftover || !**leftover)
// 		return (NULL);
// 	newline_pos = ft_strchr(*leftover, '\n');
// 	if (newline_pos)
// 	{
// 		line = ft_substr(*leftover, 0, newline_pos - *leftover + 1);
// 		temp = ft_strdup(newline_pos + 1);
// 		free(*leftover);
// 		*leftover = temp;
// 	}
// 	else
// 	{
// 		line = ft_strdup(*leftover);
// 		free(*leftover);
// 		*leftover = NULL;
// 	}
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*leftover[1024];
// 	char		buffer[BUFFER_SIZE + 1];
// 	ssize_t		bytes_read;
// 	char		*temp;

// 	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (!leftover[fd] || !ft_strchr(leftover[fd], '\n'))
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 		{
// 			if (bytes_read < 0)
// 			{
// 				free(leftover[fd]);
// 				leftover[fd] = NULL;
// 			}
// 			break ;
// 		}
// 		buffer[bytes_read] = '\0';
// 		temp = ft_strjoin(leftover[fd], buffer);
// 		free(leftover[fd]);
// 		leftover[fd] = temp;
// 	}
// 	return (split_line(&leftover[fd]));
// }
// 	while (!leftover[fd] || !ft_strchr(leftover[fd], '\n'))
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 		{
// 			if (bytes_read < 0)
// 			{
// 				free(leftover[fd]);
// 				leftover[fd] = NULL;
// 			}
// 			break ;
// 		}
// 		buffer[bytes_read] = '\0';
// 		temp = ft_strjoin(leftover[fd], buffer);
// 		free(leftover[fd]);
// 		leftover[fd] = temp;
// 	}
// 	return (split_line(&leftover[fd]));
// }
