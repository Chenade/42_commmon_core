/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:34:47 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:35:27 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_del_back(t_stack **stack_name)
{
	t_stack	*org;
	t_stack	*tmp;
	t_stack	*last;

	org = (*stack_name);
	while ((*stack_name)->next->next)
	{
		(*stack_name) = (*stack_name)->next;
	}
	tmp = (*stack_name);
	last = tmp->next;
	free(last);
	tmp->next = NULL;
	(*stack_name) = org;
}

void	rra(int print, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = ft_stack_last(stack_a);
		ft_stack_push(stack_a, ft_stack_new(tmp->content));
		ft_stack_del_back(stack_a);
	}
	if (print)
		ft_printf("rra\n");
}

void	rrb(int print, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = ft_stack_last(stack_b);
		ft_stack_push(stack_b, ft_stack_new(tmp->content));
		ft_stack_del_back(stack_b);
	}
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(0, stack_a);
	rrb(0, stack_b);
	ft_printf("rrr\n");
}
