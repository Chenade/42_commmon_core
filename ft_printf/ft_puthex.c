#include "ft_printf.h"

void	ft_puthex (unsigned int n, char *base, int *len)
{
	if (n >15)
		ft_puthex(n / 16, base, len);
	ft_putchar(base[n % 16], len);
}

void	ft_puthex_pointer (unsigned long long n, char *base, int *len)
{
	if (n >15)
		ft_puthex_pointer (n / 16, base, len);
	ft_putchar(base[n % 16], len);
}

void	func_p (unsigned long long n, char *base, int *len)
{
	if (n == 0)
		ft_putstr ("(nil)", len);
	else
	{
		ft_putstr ("0x", len);
		ft_puthex_pointer (n, base, len);
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
