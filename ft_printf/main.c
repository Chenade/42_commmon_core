/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:34:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/10 12:37:23 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

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

	if (!(*s))
		ft_putstr ("(null)", len);
	i = -1;
	while (s[++i])
		ft_putchar (s[i], len);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', len);
			n *= -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
		else
			ft_putchar(n + 48, len);
	}
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

void func_x (int n, int *len, int is_cap)
{
	char *base;

	base = "0123456789abcdef";
	if (is_cap)
		base = "0123456789ABCDEF";
	printf ("[%s]", base);
	ft_putstr (base, len);
} 

void	ft_printf_func(const char s, va_list lst, int *len)
{
	if (s == 'c')
		ft_putchar (va_arg (lst,  int), len);
	else if (s == 's')
		ft_putstr (va_arg (lst, char *), len);
	else if (s == 'd')
		ft_putnbr (va_arg (lst, int), len);
	else if (s == 'u')
		func_u (va_arg (lst, unsigned int), len);
	else if (s == 'x')
		func_x (va_arg (lst, int), len, 0);
	else if (s == 'X')
		func_x (va_arg (lst, int), len , 1);
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
    int a, b, c;

//	a = ft_printf (argv[1], -5, 'c', "string", 13, 14, 15, 16, 17, 18, 19, 20);
//	printf (" | return: %d", a);

    printf("\nEnter value of a in decimal format:");
    scanf("%i", &a);
    printf("%%d -> %d\n", a);
    printf("%%i -> %i\n", a);
    printf("%%u -> %u\n", a);
    printf("%%x -> %x\n", a);
    printf("%%X -> %X\n", a);
    //printf("%%i -> %i\n", a);
    //printf("%%i -> %i\n", a);

/*    printf("\nEnter value of b in octal format: ");
    scanf("%i", &b);
    printf("%%d -> %d\n", b);
    printf("%%i -> %i\n", b);
 
    printf("\nEnter value of c in hexadecimal format: ");
    scanf("%i", &c);
    printf("%%d -> %d\n", c);
    printf("%%i -> %i\n", c);

    printf("\n\n Variadic functions: \n");
    printf("\n 1 + 2 = %d ",AddNumbers(2, 1, 2));
    printf("\n 3 + 4 + 5 = %d ", AddNumbers(3, 3, 4, 5));
    printf("\n 6 + 7 + 8 + 9 = %d ", AddNumbers(4, 6, 7, 8, 9)); 
    printf("rer%q", 2);*/
    return 0;
}
