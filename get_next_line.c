/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/02 13:31:36 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


static char *split_line(char **leftover)
{
	char *line;
	char *new_leftover;
	char *newline_pos;

	if (!*leftover)
		return (NULL);
	newline_pos = ft_strchr(*leftover, '\n');
	if (newline_pos)
	{
		line = ft_substr(*leftover, 0, newline_pos - *leftover + 1);
		new_leftover = ft_strdup(newline_pos + 1);
		free(*leftover);
		*leftover = new_leftover;
	}
	else
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char *get_next_line(int fd)
{
    static char *leftover;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *nl;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (!(nl = ft_strchr(leftover, '\n')))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        tmp = ft_strjoin(leftover, buffer);
        free(leftover);
        leftover = tmp;
        if (!leftover)
            return NULL;
    }
    if (!leftover || *leftover == '\0')
    {
        free(leftover);
        leftover = NULL;
        return NULL;
    }
    return split_line(&leftover);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file");
		return 1;
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
