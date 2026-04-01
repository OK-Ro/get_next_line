/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 16:30:08 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int get_next_line(int fd, char **line)
{
    static char buffer[1024];
    static int buffer_index = 0;
    static int bytes_read = 0;
    char *temp_line = NULL;
    int line_length = 0;

    if (fd < 0 || !line)
        return (-1);

    while (1)
    {
        if (buffer_index >= bytes_read)
        {
            bytes_read = read(fd, buffer, sizeof(buffer));
            buffer_index = 0;
            if (bytes_read <= 0)
                break;
        }

        char c = buffer[buffer_index++];
        temp_line = realloc(temp_line, line_length + 2);
        temp_line[line_length++] = c;
        temp_line[line_length] = '\0';

        if (c == '\n')
            break;
    }

    if (line_length == 0)
    {
        free(temp_line);
        return (0);
    }

    *line = temp_line;
    return (1);
}   

int main(void)
{
    int fd; 
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
        
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    free(line);
    close(fd);
    return (0);
}