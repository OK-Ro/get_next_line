/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 17:50:54 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_num;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_num, line);
		free(line);
		line_num++;
	}
	close(fd);
	return (0);
}
