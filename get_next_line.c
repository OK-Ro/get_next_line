/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:48 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 16:57:46 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_until_newline(int fd, char *stash);

static	char *update_stash(char *stash);

char *get_next_line(int fd);

char	*get_next_line(int fd);
