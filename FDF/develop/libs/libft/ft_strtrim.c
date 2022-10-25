/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:19:50 by cmenasse          #+#    #+#             */
/*   Updated: 2021/02/22 20:05:23 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	while (j + 1 > i && ft_strchr(set, s[j]))
		j--;
	return (ft_substr(s, (unsigned int)i, j - i + 1));
}
