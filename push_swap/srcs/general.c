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

int convert_to_binary(int num, int *bin)
{
    int index;

    index = INT_SIZE - 1;
    while(index >= 0)
    {
        bin[index] = num & 1;
        index--;
        num >>= 1;
    }
    return (1);
}