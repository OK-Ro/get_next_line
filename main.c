/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 14:36:11 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(void)
{
    int fd = open("new.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }

    char *buffer = malloc(100);
    int bytes_read;
	int i = 1;

	while ((bytes_read = read(fd, buffer, 10)) > 0)
	{
    	printf("Call #%d: read %d bytes → \"", i++, bytes_read);
   	 	write(1, buffer, bytes_read);
    	printf("\"\n");
	}
    close(fd);
    return (0);
}

