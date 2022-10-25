/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenasse <cmenasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:13:55 by cmenasse          #+#    #+#             */
/*   Updated: 2021/02/22 19:04:05 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	char	*str;
	int		nbrlen;
	long	n;

	n = nbr;
	nbrlen = (nbr == 0);
	while (nbr && ++nbrlen)
		nbr /= 10;
	if (n < 0 && nbrlen++ && !nbr++)
		n = -n;
	str = (char *)malloc(sizeof(*str) * (nbrlen + 1));
	if (!str)
		return (NULL);
	str[nbrlen] = '\0';
	while (nbrlen > nbr)
	{
		str[nbrlen-- - 1] = '0' + n % 10;
		n /= 10;
	}
	if (nbr > 0)
		str[0] = '-';
	return (str);
}
