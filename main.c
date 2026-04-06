// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
// /*   Updated: 2026/04/03 13:14:18 by rokuni           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static char *extract_line(char **leftover)
{
	char *new_position;
	char *temp;
	char *line;

	if (!*leftover || **leftover == '\0')
	{
		free(leftover);
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

char *get_next_line(int fd)
{
	static char *leftover;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;
	char *temp;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		leftover = temp;

		if (ft_strchr(leftover, '\n'))
			break;
	}
	if (bytes_read == -1)      // ← here
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	return (extract_line(&leftover));
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // line already has '\n' if file has one
        free(line);         // always free after use
    }

    close(fd);
    return 0;
}

