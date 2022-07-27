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

void ft_print_err(char *msg, t_stack **stack_a, t_stack **stack_b)
{
    ft_printf(msg);
    ft_stack_clear(stack_a, stack_b);
}

void  print_both_stack(t_stack **stack_a, t_stack **stack_b)
{
  ft_printf("========================\n");
	ft_printf("stack a [len => %d]: ", ft_stack_len(stack_a));
	ft_stack_print(stack_a);
	ft_printf("stack b [len => %d]: ", ft_stack_len(stack_b));
	ft_stack_print(stack_b);
  ft_printf("========================\n");
}