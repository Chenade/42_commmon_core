/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:56:57 by cmenasse          #+#    #+#             */
/*   Updated: 2021/02/22 20:03:42 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s) + 1;
	while (l--)
		if (s[l] == (char)c)
			return ((char *)s + l);
	return (NULL);
}
