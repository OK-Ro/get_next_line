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
	}
	return (leftover);
}

int	main(void)
{
	int		fd;
	char	*line;
	char *one_line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	one_line = get_next_line(fd);
	printf("%s\n", one_line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
