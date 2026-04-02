/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokuni <rokuni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:57 by rokuni            #+#    #+#             */
/*   Updated: 2026/04/02 12:12:50 by rokuni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

// char	*ft_strchr(const char *s, int c)
// {

// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*joined;
	int		i;
	int		j;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

int main()
{
	char *s1 = "Hello ";
	char *s2 = "World";
	char *result = ft_strjoin(s1, s2);
	printf("Result: %s\n", result);
	return 0;
}

// char	*ft_strdup(const char *s1)
// {
// 	char *duplicate;
// 	int	i;
	
// 	while (s1[i])
// 		i++;
// 	duplicate = malloc((i + 1) * sizeof(char));
// 	if (!duplicate)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		duplicate[i] = s1[i];
// 		i++;
// 	}
// 	duplicate[i] = '\0';
// 	return (duplicate);
// }
