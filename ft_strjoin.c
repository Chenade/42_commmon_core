/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:52:49 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/07 23:52:53 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		len;
	int		i;

	ans = NULL;
	if (!(s1) || !(s2))
		return (ans);
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = (char *) malloc (sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	i = -1;
	while (s1[++i])
		ans[i] = s1[i];
	i = -1;
	while (s2[++i])
		ans[ft_strlen(s1) + i] = s2[i];
	ans[ft_strlen(s1) + i] = '\0';
	return (ans);
}
