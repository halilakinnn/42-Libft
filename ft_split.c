/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakin <hakin@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:15 by hakin             #+#    #+#             */
/*   Updated: 2022/10/12 12:26:43 by hakin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_count(char const *s, char c)
{
	char	pre_c;
	size_t	i;

	i = 0;
	pre_c = c;
	while (*s)
	{
		if (pre_c == c && *s != c)
			i++;
		pre_c = *s;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	next;
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		next = ft_str(s, c);
		if (next)
		{
			strs[i] = ft_substr(s, 0, next);
			s += next;
			i++;
		}
		else
			s++;
	}
	strs[i] = 0;
	return (strs);
}
