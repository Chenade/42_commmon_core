/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:43 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/12 06:21:55 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_move(t_move **move, t_move **org, int init)
{
	if (init)
	{
		(*move)->num_a = 0;
		(*move)->num_b = 0;
		(*move)->ra = 0;
		(*move)->rb = 0;
		(*move)->rr = 0;
		(*move)->rra = 0;
		(*move)->rrb = 0;
		(*move)->rrr = 0;
		(*move)->count = 0;
	}
	else
	{
		(*move)->num_a = (*org)->num_a;
		(*move)->num_b = (*org)->num_b;
		(*move)->ra = (*org)->ra;
		(*move)->rb = (*org)->rb;
		(*move)->rr = (*org)->rr;
		(*move)->rra = (*org)->rra;
		(*move)->rrb = (*org)->rrb;
		(*move)->rrr = (*org)->rrr;
		(*move)->count = (*org)->count;
	}
}

void	ft_totop(t_stack **stack_name, int val, t_move **move, int name)
{
	int		distance;

	distance = get_distance(stack_name, val, 0);
	if (!name)
		(*move)->num_a = (*stack_name)->content;
	else
		(*move)->num_b = val;
	if ((ft_stack_len(stack_name) - distance) < distance)
	{
		distance = ft_stack_len(stack_name) - distance;
		if (!name)
			(*move)->rra += distance;
		else
			(*move)->rrb += distance;
	}
	else
	{
		if (!name)
			(*move)->ra += distance;
		else
			(*move)->rb += distance;
	}
	(*move)->count += distance;
}

int	get_min_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*head_a;

	head_a = (*stack_a);
	min = 1000;
	while ((*stack_a))
	{
		if ((*stack_a)->content > (*stack_b)->content \
				&& min > (*stack_a)->content)
				min = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head_a;
	return (min);
}

t_move	*ft_minmove(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;
	t_move	*move;
	int		min;
	t_move	*min_move;

	head_b = (*stack_b);
	move = NULL;
	move = malloc(sizeof(t_move));
	min_move = malloc(sizeof(t_move));
	init_move(&min_move, &move, 1);
	min_move->count = ft_stack_len(stack_a) + ft_stack_len(stack_b);
	while ((*stack_b))
	{
		init_move(&move, &move, 1);
		min = get_min_stack(stack_a, stack_b);
		ft_totop(stack_a, min, &move, 0);
		ft_totop(&head_b, (*stack_b)->content, &move, 1);
		if (min_move->count > move->count)
			init_move(&min_move, &move, 0);
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = head_b;
	free (move);
	return (min_move);
}

void	ft_move(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	t_move	*head;

	head = move;
	while ((move->ra)--)
		ra(1, stack_a);
	while ((move->rb)--)
		rb(1, stack_b);
	while ((move->rra)--)
		rra(1, stack_a);
	while ((move->rrb)--)
		rrb(1, stack_b);
	pa (stack_a, stack_b);
	move = head;
}
