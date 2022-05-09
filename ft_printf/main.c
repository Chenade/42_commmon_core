/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:34:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/09 18:46:03 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar_fd(char c, int fd);

int	ft_valid (const char c)
{
	char	*charset;
	int		i;

	charset = "cspdiuxX";
	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (i);
	}
	return (0);
}

int	ft_count (const char *s)
{
	int	ans;
	int	i;

	ans = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			if (s[i + 1] == '%')
				i += 1;
			else if (ft_valid (s[i + 1]))
				ans += 1;
		}
	}
	return (ans);
} 

int	ft_printf (const char *s, ...)
{
	int		word_count;
	int		i;
	va_list	lst;

	if (!(*s))
		return (0);
	word_count = ft_count (s);
	va_start (lst, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (word_count)
			{			
				printf("%d", va_arg (lst, int));
				word_count -= 1;
				i += 1;
			}
		}
		else
			ft_putchar_fd (s[i], 1);
	}
	va_end (lst);
	return (word_count);
}
 
int main(int argc, char *argv[])
{
    int a, b, c;

	a = ft_printf (argv[1], 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
 /*
    printf("\nEnter value of a in decimal format:");
    scanf("%i", &a);
    printf("%%d -> %d\n", a);
    printf("%%i -> %i\n", a);
    printf("%%x -> %x\n", a);
    printf("%%X -> %X\n", a);
    //printf("%%i -> %i\n", a);
    //printf("%%i -> %i\n", a);

    printf("\nEnter value of b in octal format: ");
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
