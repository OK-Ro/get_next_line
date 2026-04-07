/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:50:56 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/07 11:18:44 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *leftover;
    ssize_t read_bytes;
    char *temp;
    char buffer[BUFFER_SIZE + 1];

    read_bytes = 1;
    while (!ft_strchr(leftover, '\n') && read_bytes > 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes < 0)
        {
            free(leftover);
            leftover = NULL;
            return (NULL);
        }
        buffer[read_bytes] = '\0';

        temp = ft_strjoin(leftover, buffer);
        if (!temp)
        {
            free(leftover);
            leftover = NULL;
            return (NULL);
        }
        free(leftover);
        leftover = temp;
    }
    return (extract_line(&leftover));
}
