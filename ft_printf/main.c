#include "ft_printf.h"

int main(int argc, char *argv[])
{
    int a;

   printf("\nEnter value of a in decimal format:");
    scanf("%i", &a);

    printf("printf: %%d -> %d\n", a);
    ft_printf("ft_printf: %%d -> %d\n\n", a);
    printf("printf: %%i -> %i\n", a);
    ft_printf("ft_printf: %%i -> %i\n\n", a);
    printf("printf: %%u -> %u\n", a);
    ft_printf("ft_printf: %%u -> %u\n\n", a);
    printf("printf: %%x -> %x\n", a);
    ft_printf("ft_printf: %%x -> %x\n\n", a);
    printf("printf: %%X -> %X\n", a);
    ft_printf("ft_printf: %%X -> %X\n\n", a);
    printf("printf: %%i -> %i\n", a);
    ft_printf("ft_printf: %%i -> %i\n\n", a);

	char	*t;
	t = 0;
    printf("##printf: %%p -> %p\n", t);
    ft_printf("##ft_printf: %%p -> %p\n\n", t);

	char *s = NULL;
    printf("printf: %%s -> %s\n", s);
    ft_printf("printf: %%s (null) -> %s \n\n", s);
    return 0;
}
