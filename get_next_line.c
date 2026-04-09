/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/09 11:48:42 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **leftover)
{
	char	*line_found;
	char	*paragragh;
	char	*rest;
	
	if (!leftover || **leftover == '\0')
		return (free(*leftover), *leftover = NULL, NULL);
	line_found = ft_strchr(*leftover, '\n');
	if(line_found)
	{
		paragragh = ft_substr(*leftover, 0, line_found - *leftover + 1);
		if (!paragragh)
			return (free(*leftover), *leftover = NULL, NULL);
		if (*(line_found + 1))
			rest = ft_strdup(*leftover);
		else
			rest = 	NULL;
		return (free(*leftover), *leftover = rest, paragragh);
	}
	paragragh = ft_strdup(*leftover);
	free (*leftover);
	*leftover = NULL;
	return (paragragh);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	ssize_t read_bytes;
	char *temp;
	char buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && (!leftover || !ft_strchr(leftover, '\n')))
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
