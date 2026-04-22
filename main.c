/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/22 12:13:55 by rokuni           ###   ########.fr       */
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
	
	printf("\n========== FILE 1: file1.txt ====================================\n");
	line_num = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file1: [%d]\n", line_num - 1);
	close(fd1);
	
	// Open file2
	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		printf("Error opening file2.txt\n");
		return (1);
	}
	
	printf("\n========== FILE 2: test.txt ====================================\n");
	line_num = 1;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %2d: %s", line_num++, line);
		free(line);
	}
	printf("Total lines in file2: [%d]\n", line_num - 1);
	close(fd2);
	
	return (0);
}
// int main(void)
// {
//     int fd;
//     char *line;
//     int line_num;

//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }

//     printf("\n========== FILE: test.txt ====================================\n");
//     line_num = 1;
//     while ((line = get_next_line(fd)) != NULL)
//     {
// int main(void)
// {
//     int fd;
//     char *line;
//     int line_num;

//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }

//     printf("\n========== FILE: test.txt ====================================\n");
//     line_num = 1;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line %2d: %s", line_num++, line);
//         free(line);
//     }
//     printf("Total lines: [%d]\n", line_num - 1);
//     close(fd);

//     return (0);
// }
//         printf("Line %2d: %s", line_num++, line);
//         free(line);
//     }
//     printf("Total lines: [%d]\n", line_num - 1);
//     close(fd);

//     return (0);
// }

// int main(void)
// {
//     int fd;
//     ssize_t read_bytes;
//     char buffer[42];
    
//     fd = open("test.txt", O_RDONLY);
//     while (read_bytes = read(fd, buffer, 42) > 0)
//     {
//         printf("%s", buffer);
//     }
//     close(fd);
//     return (0);
// }