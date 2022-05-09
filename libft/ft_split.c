/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:52:23 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/07 23:52:35 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

int	ft_lettercount(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_substr_split(const char *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
	{
		free(cpy);
		return (0);
	}
	while (i < len)
	{
		cpy[i] = s[start];
		start++;
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;

	i = 0;
	if (!s)
		return (0);
	ans = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!ans)
	{
		free(ans);
		return (0);
	}
	while (ft_wordcount(s, c))
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
			ans[i++] = ft_substr_split(s, 0, ft_lettercount(s, c));
		while (*s && *s != c)
			s++;
	}
	ans[i] = 0;
	return (ans);
}
