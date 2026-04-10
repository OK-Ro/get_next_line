/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:10:17 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/10 15:35:54 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



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