/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 18:36:49 by rokuni           ###   ########.fr       */
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
	char	*line1, *line2;
	int		line_num1, line_num2;
	int		active1, active2;

	// Open two files
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	
	if (fd1 < 0 || fd2 < 0)
	{
		printf("Error opening files\n");
		printf("Make sure file1.txt and file2.txt exist\n");
		return (1);
	}
	
	line_num1 = 1;
	line_num2 = 1;
	active1 = 1;
	active2 = 1;
	
	printf("=== Reading interleaved from two files ===\n");
	printf("File 1: file1.txt (long story)\n");
	printf("File 2: file2.txt (numbered lines)\n\n");
	
	while (active1 || active2)
	{
		if (active1)
		{
			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("[file1.txt line %2d] %s", line_num1++, line1);
				free(line1);
			}
			else
				active1 = 0;
		}
		
		if (active2)
		{
			line2 = get_next_line(fd2);
			if (line2)
			{
				printf("[file2.txt line %2d] %s", line_num2++, line2);
				free(line2);
			}
			else
				active2 = 0;
		}
	}
	
	printf("\n=== Done ===\n");
	printf("file1.txt: %d lines total\n", line_num1 - 1);
	printf("file2.txt: %d lines total\n", line_num2 - 1);
	
	close(fd1);
	close(fd2);
	return (0);
}
