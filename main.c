/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:50:09 by rokuni            #+#    #+#             */
/*   Updated: 2026/03/31 20:07:05 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

char *get_next_line(int fd)
{
static char *stash; // NULL at program start (automatically)
// ...
// Call 1: stash is NULL, we read, stash becomes 'Hello\nWo'
// We return 'Hello\n', stash becomes 'Wo'
// Call 2: stash is 'Wo' (still here!)
// We keep reading, stash becomes 'World\n'
// We return 'World\n', stash becomes ''
// ...
}