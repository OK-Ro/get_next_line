/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/09 11:51:17 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **leftover)
{
	char	*line_found;
	char	*paragragh;
	char	*rest;
	
	if (!leftover || !**)
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	ssize_t read_bytes;
	char *temp;
	char buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read_bytes > 0 && (!leftover || !ft_strchr(leftover, '\n')))
	{
		
	}
	return (extract_line(&leftover));
}
