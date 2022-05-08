/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:26:25 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/07 23:42:12 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ans;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	ans = 0;
	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n && !(ans))
	{
		ans = (int) str1[i] - (int) str2[i];
		if (str1[i] == 0 && str2[i] == 0)
			break ;
		i += 1;
	}
	return (ans);
}
