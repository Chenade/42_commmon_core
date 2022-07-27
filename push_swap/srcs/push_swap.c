#include "push_swap.h"

int	sort_redix(t_stack **stack_a, t_stack **stack_b)
{
	int size = ft_stack_len(stack_a);
	int max_num = size - 1;
	int max_bits = 0;
	while ((max_num >> max_bits) != 0) 
	++max_bits;
	// int i = 0;
	// while (!ft_stack_isSort(stack_a))
	  for (int i = 0 ; i < max_bits ; ++i)
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
		// print_both_stack(stack_a, stack_b);
		}
		while (ft_stack_len(stack_b)) pa(stack_a, stack_b);
		// print_both_stack(stack_a, stack_b);
		// i += 1;
	}
	// print_both_stack(stack_a, stack_b);
	return (0);
}

int	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	int	top;
	int	middle;
	int	bottom;

	(void) stack_b;
	top = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	bottom = (*stack_a)->next->next->content;
	if (top > middle && bottom > middle && top < bottom)
		sa(1, stack_a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(1, stack_a);
		rra(1, stack_a);
	}
	else if (top > middle && bottom > middle && top > bottom)
		ra(1, stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(1, stack_a);
		ra(1, stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(1, stack_a);
	return (0);
}

int  push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	res;

	size = ft_stack_len(stack_a);
	res = 0;
	if (size == 3)
		res = sort_3(stack_a, stack_b);
	else
		res = sort_redix(stack_a, stack_b);
	return (res);
}