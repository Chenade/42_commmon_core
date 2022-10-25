/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:52:23 by cmenasse          #+#    #+#             */
/*   Updated: 2021/02/22 19:38:10 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (++len));
	if (!s2)
		return (NULL);
	while (len--)
		s2[len] = s1[len];
	return (s2);
}
