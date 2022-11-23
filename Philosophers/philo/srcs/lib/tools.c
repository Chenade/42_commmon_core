/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:26:35 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/23 20:26:37 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = (char) 0;
		i += 1;
	}
}

int	is_digits(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] <= '0' || s[i] >= '9')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		ans;
	int		sign;

	i = 0;
	ans = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i += 1;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		sign = 44 - nptr[i];
		i += 1;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		ans *= 10;
		ans = ans + nptr[i] - 48;
		i += 1;
	}
	return (ans * sign);
}
