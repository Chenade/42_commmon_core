/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:16:42 by cmenasse          #+#    #+#             */
/*   Updated: 2022/08/15 09:05:52 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	char	*s;

// 	i = 0;
// 	s = (char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!s)
// 		return (NULL);
// 	while (s1 && *s1)
// 		s[i++] = *s1++;
// 	while (*s2)
// 		s[i++] = *s2++;
// 	s[i] = '\0';
// 	if (s1)
// 		free (s1);
// 	return (s);
// }


char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return (s1);
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