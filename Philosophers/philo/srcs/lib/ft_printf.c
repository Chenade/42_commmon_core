/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:27:29 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/23 20:27:32 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdarg.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (0);
}

int	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return (0);
}

int	ft_printf_func(char c, va_list lst)
{
	if (c == 'd')
		ft_putnbr(va_arg(lst, int));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	lst;

	if (!(*s))
		return (0);
	va_start(lst, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (!s[++i])
				break ;
			ft_printf_func(s[i], lst);
		}
		else
			ft_putchar(s[i]);
	}
	va_end(lst);
	return (0);
}
