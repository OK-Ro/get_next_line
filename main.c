/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 17:50:16 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	test_file(const char *filename)
{
	int		fd;
	char	*line;
	int		line_num;

	printf("\n========== Testing: %s ==========\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d] %s", line_num, line);
		free(line);
		line_num++;
	}
	printf("\n[Total lines: %d]\n", line_num - 1);
	close(fd);
}

void	test_multiple_fds(void)
{
	int		fd1, fd2, fd3;
	char	*line1, *line2, *line3;
	int		active;

	printf("\n========== Testing Multiple FDs ==========\n");
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("open");
		return ;
	}
	active = 1;
	while (active)
	{
		active = 0;
		line1 = get_next_line(fd1);
		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
			active = 1;
		}
		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("FD2: %s", line2);
			free(line2);
			active = 1;
		}
		line3 = get_next_line(fd3);
		if (line3)
		{
			printf("FD3: %s", line3);
			free(line3);
			active = 1;
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
}

void	test_stdin(void)
{
	char	*line;
	int		line_num;

	printf("\n========== Testing STDIN (Ctrl+D to stop) ==========\n");
	line_num = 1;
	while ((line = get_next_line(0)) != NULL)
	{
		printf("[%d] %s", line_num, line);
		free(line);
		line_num++;
	}
	printf("\n[Total lines from stdin: %d]\n", line_num - 1);
}

void	test_invalid_fd(void)
{
	char	*line;

	printf("\n========== Testing Invalid FD ==========\n");
	line = get_next_line(-1);
	if (line == NULL)
		printf("OK: Invalid FD returns NULL\n");
	else
		printf("KO: Invalid FD returned something\n");
	free(line);
	line = get_next_line(999);
	if (line == NULL)
		printf("OK: Non-existent FD returns NULL\n");
	else
		printf("KO: Non-existent FD returned something\n");
	free(line);
}

void	test_bad_buffer(void)
{
	// This test requires recompiling with different BUFFER_SIZE values
	printf("\n========== Testing Different BUFFER_SIZES ==========\n");
	printf("Current BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf("Test with: gcc -D BUFFER_SIZE=1 ...\n");
	printf("         gcc -D BUFFER_SIZE=42 ...\n");
	printf("         gcc -D BUFFER_SIZE=1000000 ...\n");
}

int	main(int ac, char **av)
{
	printf("=== GET_NEXT_LINE TESTER ===\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	
	// Test individual files if provided as arguments
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			test_file(av[i]);
	}
	else
	{
		// Default tests
		test_file("test.txt");

		test_multiple_fds();
		test_stdin();
		test_invalid_fd();
		test_bad_buffer();
	}
	
	printf("\n=== ALL TESTS COMPLETED ===\n");
	return (0);
}