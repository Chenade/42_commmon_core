/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:33:45 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/11 22:30:12 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	ans;
	int		i;

	ans = 0;
	i = -1;
	if (!s)
		return (ans);
	while (s[++i])
		ans += 1;
	return (ans);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		len;
	int		i;

	ans = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = (char *) malloc (sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	if (len == 0)
		ans[0] = '\0';
	else
	{
		i = -1;
		while (s1[++i])
			ans[i] = s1[i];
		i = -1;
		while (s2[++i])
			ans[ft_strlen(s1) + i] = s2[i];
		ans[ft_strlen(s1) + i] = '\0';
	}
	return (ans);
}

char	*ft_strjoin_vi(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return (s1);
//	if (ft_strchr(s2) > 0)
//		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strchr(s2) + 1));
//	else
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	while (s1 && s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2[j] != '\n')
		ret[i++] = s2[j++];
	if (s2[j] == '\n')
		ret[i++] = s2[j];
	ret[i] = 0;
	free(s1);
	return (ret);
}
