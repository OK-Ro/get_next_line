/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 14:47:02 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// add next line to compile with C17 standard
int main(void)
{
    int fd;
    char buffer[100];

    // Open the file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read from the file
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return EXIT_FAILURE;
    }

    // Null-terminate the buffer
    buffer[bytesRead] = '\0';

    // Print the contents of the file
    printf("File contents:\n%s\n", buffer);

    // Close the file descriptor
    close(fd);
    
    return EXIT_SUCCESS;
}

