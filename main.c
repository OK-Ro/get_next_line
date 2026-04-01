/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 12:33:55 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    // Step 1: Understanding file descriptors and basic reading
    // Let's start by reading from a file character by character

    int fd = open("test.txt", O_RDONLY);
	
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
	
    char buffer[1];
    int bytes_read;

    printf("Reading file character by character:\n");
    while ((bytes_read = read(fd, buffer, 1)) > 0)
    {
        printf("%c", buffer[1]);
    }

    close(fd);
    printf("\n\nNow you understand basic file reading!\n");
    printf("Key concepts:\n");
    printf("- File descriptors (fd) are integers that represent open files\n");
    printf("- read() returns number of bytes read, 0 at EOF, -1 on error\n");
    printf("- We need to close files when done\n");

    return (0);
}

