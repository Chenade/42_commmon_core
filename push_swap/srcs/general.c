#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	t[2];
	int	ans;

	i = 0;
	ans = 0;
	while (!ans)
	{
		if (s1[i])
			t[0] = (int) s1[i];
		else
			t[0] = 0;
		if (s2[i])
			t[1] = (int) s2[i];
		else
			t[1] = 0;
		ans = t[0] - t[1];
		if (t[0] == 0 && t[1] == 0)
			break ;
		i += 1;
	}
	return (ans);
}


void ft_print_err(char *msg)
{
  ft_printf(msg);
}


void	ft_bzero_char(void *s, size_t n)
{
	while (n--)
		((char *)s)[n] = '0';
}


char *convert_to_binary(int num)
{
    ft_printf("===convert_to_binary(%d)===\n", num);
    char *res;
    int index;

    index = INT_SIZE - 1;
    res = (char *) malloc(INT_SIZE * sizeof(char));
    if(!res)
        return NULL;
    ft_bzero_char(res, INT_SIZE);
    // ft_printf("%s\n", res);
    while(index >= 0)
    {
        ft_printf("%s", num & 1);
        ft_printf("\n");
        if (num & 1)
            res[index] = num & 1;
        index--;
        num >>= 1;
    }
    res[INT_SIZE] = 0;
    return (res);
}