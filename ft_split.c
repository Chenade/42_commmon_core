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

void	ft_split_func(char const *s, char c, char **ans)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i += 1;
		k = 0;
		while (s[i] && c != s[i])
		{
			ans[j][k] = s[i];
			i += 1;
			k += 1;
		}
		ans[j][k] = '\0';
		if (*ans[j] != '\0')
			j++;
	}
	ans[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	i;

	ans = (char **) malloc ((ft_strlen(s) + 1) * sizeof(char *));
	if (!ans)
		return (0);
	i = -1;
	while (++i < ft_strlen(s))
	{
		ans[i] = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
		if (!ans[i])
			return (0);
	}
	ft_split_func(s, c, ans);
	return (ans);
}
