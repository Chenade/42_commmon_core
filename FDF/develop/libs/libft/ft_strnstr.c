/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:54:44 by cmenasse          #+#    #+#             */
/*   Updated: 2021/02/22 20:02:59 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	i;

	if (!*n)
		return ((char *)h);
	while (*h && l--)
	{
		i = 0;
		while (n[i] && h[i] == n[i] && i <= l)
			i++;
		if (!n[i])
			return ((char *)h);
		h++;
	}
	return (NULL);
}
