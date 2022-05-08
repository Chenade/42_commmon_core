/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 00:05:39 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/08 00:06:26 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_charset(const char *charset, const char c)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	ft_count_len(const char *s1, char const *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1) - 1;
	while (len && (in_charset(s2, s1[len])))
		len -= 1;
	i = 0;
	while (in_charset(s2, s1[i]) && len)
	{
		i += 1;
		len -= 1;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	int		j;
	int		len;

	len = ft_count_len(s1, s2) + 1;
	ans = (char *) malloc ((len + 1) * sizeof (char));
	if (!ans)
		return (NULL);
	i = 0;
	j = 0;
	while (in_charset(s2, s1[i]))
		i += 1;
	while (j < len)
	{
		ans[j] = s1[i + j];
		j += 1;
	}
	ans[j] = 0;
	return (ans);
}
