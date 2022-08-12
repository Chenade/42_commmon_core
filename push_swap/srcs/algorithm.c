/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:38:21 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/12 06:38:34 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_redix(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	j;
	int	num;

	size = ft_stack_len(stack_a);
	i = 0;
	while (!ft_stack_issort(stack_a))
	{
		j = 0;
		while (++j <= size)
		{
			if (!(*stack_a))
				break ;
			num = (*stack_a)->content;
			if (((num >> i) & 1) == 1)
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

int	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int		*lis;
	t_move	*min_move;

	lis = find_lis(stack_a);
	split_lis(stack_a, stack_b, lis);
	while (ft_stack_len(stack_b))
	{
		min_move = ft_minmove(stack_a, stack_b);
		ft_move(stack_a, stack_b, min_move);
		free (min_move);
	}
	while ((*stack_a)->content != 0)
		ra(1, stack_a);
	free (lis);
	return (1);
}

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
	distance = get_distance(stack_a, get_min(stack_a, -1), 0);
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

	distance = get_distance(stack_a, get_min(stack_a, -1), 0);
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
