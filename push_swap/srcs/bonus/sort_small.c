#include "push_swap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b)
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
	return ;
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (ft_stack_issort(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(1, stack_a);
	else if (distance == 2)
	{
		ra(1, stack_a);
		ra(1, stack_a);
	}
	else if (distance == 3)
		rra(1, stack_a);
	if (ft_stack_issort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(1, stack_a);
	else if (distance == 2)
	{
		ra(1, stack_a);
		ra(1, stack_a);
	}
	else if (distance == 3)
	{
		rra(1, stack_a);
		rra(1, stack_a);
	}
	else if (distance == 4)
		rra(1, stack_a);
	if (ft_stack_issort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}