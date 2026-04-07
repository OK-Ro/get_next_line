/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 17:46:08 by rokuni           ###   ########.fr       */
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

	// Test 1: Read from file
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: cannot open test.txt\n");
		return (1);
	}
	
	printf("=== Reading test.txt ===\n");
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_num, line);
		free(line);
		line_num++;
	}
	close(fd);
	
	// Test 2: Test only_nl.txt (your segfault case)
	printf("\n=== Reading only_nl.txt ===\n");
	fd = open("only_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: cannot open only_nl.txt\n");
		return (1);
	}
	
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: [%s]", line_num, line);
		free(line);
		line_num++;
	}
	printf("Total lines read: %d\n", line_num - 1);
	close(fd);
	
	return (0);
}