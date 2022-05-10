/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:34:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/10 16:01:41 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	*len += 1;
}

void	ft_print_int(int n, int *len)
{
	char	tmp;

	tmp = (n % 10) + 48;
	ft_putchar(tmp, len);
}


void	ft_putstr(char *s, int *len)
{
	int	i;

	if (!(s))
		ft_putstr ("(null)", len);
	else
	{
		i = -1;
		while (s[++i])
			ft_putchar (s[i], len);
	}
}

void	ft_putnbr(int nbr, int *len)
{
	long int	n;

	n = (long) nbr;
	if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar( (n % 10) + 48, len);
}

void	func_u(unsigned int n, int *len)
{
	if (n > 9)
	{
		func_u (n / 10, len);
		func_u (n % 10, len);
	}
	else
		ft_putchar (n + 48, len);
}

void func_x (unsigned int n, char *base, int *len)
{
	if (n > 15)
		func_x (n / 16, base, len);
	ft_putchar (base[n % 16], len);
} 

void	ft_printf_func(const char s, va_list lst, int *len)
{
	if (s == 'c')
		ft_putchar (va_arg (lst,  int), len);
	else if (s == 's')
		ft_putstr (va_arg (lst, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr (va_arg (lst, int), len);
	else if (s == 'u')
		func_u (va_arg (lst, unsigned int), len);
	else if (s == 'x')
		func_x (va_arg (lst, int), "0123456789abcdef", len);
	else if (s == 'X')
		func_x (va_arg (lst, int), "0123456789ABCDEF", len);
	else if (s == '%')
		ft_putchar (37, len);
}

int	ft_printf (const char *s, ...)
{
	int		len;
	int		i;
	va_list	lst;

	if (!(*s))
		return (0);
	va_start (lst, s);
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i += 1;
			if (s[i])
				ft_printf_func (s[i], lst, &len);
		}
		else
			ft_putchar (s[i], &len);
	}
	va_end (lst);
	return (len);
}
 
int main(int argc, char *argv[])
{
    int a;

    printf("\nEnter value of a in decimal format:");
    scanf("%i", &a);

    printf("printf: %%d -> %d | ", a);
    ft_printf("ft_printf: %%d -> %d\n", a);
    printf("printf: %%i -> %i | ", a);
    ft_printf("ft_printf: %%i -> %i\n", a);
    printf("printf: %%u -> %u | ", a);
    ft_printf("ft_printf: %%u -> %u\n", a);
    printf("printf: %%x -> %x | ", a);
    ft_printf("ft_printf: %%x -> %x\n", a);
    printf("printf: %%X -> %X | ", a);
    ft_printf("ft_printf: %%X -> %X\n", a);
    printf("printf: %%i -> %i | ", a);
    ft_printf("ft_printf: %%i -> %i\n", a);

	char *s = NULL;
    printf("printf: %%s -> %s | ", s);
    ft_printf("printf: %%s (null) -> %s \n", s);
    return 0;
}
