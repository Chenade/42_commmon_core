/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:33:16 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:34:01 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack **stack_name)
{
	t_stack	*org;
	t_stack	*tmp;

	if (!(*stack_name))
		return (NULL);
	org = (*stack_name);
	while ((*stack_name)->next)
	{
		(*stack_name) = (*stack_name)->next;
	}
	tmp = (*stack_name);
	(*stack_name) = org;
	return (tmp);
}

void	ft_stack_add_back(t_stack **stack_name, t_stack *node)
{
	t_stack	*tmp;

	if (*stack_name)
	{
		tmp = (*stack_name);
		ft_stack_last(stack_name)->next = node;
		(*stack_name) = tmp;
	}
	else
		*stack_name = node;
}

void	ra(int print, t_stack **stack_a)
{
	int	tmp;

	if (*stack_a)
	{
		tmp = ft_stack_pop(stack_a);
		ft_stack_add_back(stack_a, ft_stack_new(tmp));
	}
	if (print)
		ft_printf("ra\n");
}

void	rb(int print, t_stack **stack_b)
{
	int	tmp;

	if (*stack_b)
	{	
		tmp = ft_stack_pop(stack_b);
		ft_stack_add_back(stack_b, ft_stack_new(tmp));
	}
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(0, stack_a);
	rb(0, stack_b);
	ft_printf("rr\n");
}
