#include "push_swap.h"

int	sort_redix(t_stack **stack_a, t_stack **stack_b)
{
	int size = ft_stack_len(stack_a);
	int i = 0;

	while (!ft_stack_issort(stack_a))
	{
		for(int j = 0 ; j < size ; ++j)
		{
            if(!(*stack_a))
                break;
            int num = (*stack_a)->content;
            if (((num >> i)&1) == 1) 
                ra(1, stack_a); 
            else
                pb(stack_a, stack_b);
		}
		while (ft_stack_len(stack_b))
            pa(stack_a, stack_b);
		i += 1;
	}
	return (0);
}

int sort_big(t_stack **stack_a, t_stack **stack_b)
{
    print_both_stack(stack_a, stack_b);

    int head_a;

    head_a = (*stack_a)->content;
    ra (1, stack_a);
    while (!ft_stack_issort(stack_a))
	{
		if (((*stack_a)->content - head_a) == 1)
        {
            ra (1, stack_a);
            head_a += 1;
        }
        else
            pb (stack_a, stack_b);
	}

    print_both_stack(stack_a, stack_b);

    return (1);
}
