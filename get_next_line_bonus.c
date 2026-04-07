/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:50:56 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 11:18:58 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		read_bytes;
	
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		leftover = temp;
		if (leftover = ft_strchr(leftover, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_bytes < 0)
	{
		leftover = NULL;
		free(leftover);
		return (NULL);
	}
	
	return (leftover);
}
