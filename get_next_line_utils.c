/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:57 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/01 17:58:35 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
// find first occurrence of c in s
// return pointer to it or NULL if not found
char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	unsigned char *ps;
	ps = (unsigned char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return ((unsigned char*)ps);
		i++;
	}
	if (s[i] == '\0')
		return ((unsigned char*)ps);
	return (NULL);
}

// join s1 and s2 into a new string
// return the new combined string
char	*ft_strjoin(char const *s1, char const *s2);

// create a duplicate of s1
// return the new copied string
char	*ft_strdup(const char *s1);
