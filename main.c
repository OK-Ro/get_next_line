/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 18:37:06 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	main(void)
{
	int		fd1, fd2;
	char	*line;
	int		line_num;

	// Open file1
	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 < 0)
	{
		printf("Error opening file1.txt\n");
		return (1);
	}
	
	printf("\n========== FILE 1: file1.txt ==========\n");
	line_num = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file1: %d\n", line_num - 1);
	close(fd1);
	
	// Open file2
	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		printf("Error opening file2.txt\n");
		return (1);
	}
	
	printf("\n========== FILE 2: file2.txt ==========\n");
	line_num = 1;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file2: %d\n", line_num - 1);
	close(fd2);
	
	return (0);
}
