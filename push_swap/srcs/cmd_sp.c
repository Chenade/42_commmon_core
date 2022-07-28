/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:35:49 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:37:38 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int print, t_stack **stack_a)
{
	int	tmp;
	int	tmp2;

	if ((*stack_a))
	{
		tmp = ft_stack_pop(stack_a);
		if ((*stack_a))
		{
			tmp2 = ft_stack_pop(stack_a);
			ft_stack_push(stack_a, ft_stack_new(tmp));
			ft_stack_push(stack_a, ft_stack_new(tmp2));
		}
	}
	if (print)
		ft_printf("sa\n");
}

void	sb(int print, t_stack **stack_b)
{
	int	tmp;
	int	tmp2;

	tmp = ft_stack_pop(stack_b);
	tmp2 = ft_stack_pop(stack_b);
	ft_stack_push(stack_b, ft_stack_new(tmp));
	ft_stack_push(stack_b, ft_stack_new(tmp2));
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(0, stack_a);
	sb(0, stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp;

	if ((*stack_b))
	{
		tmp = ft_stack_pop(stack_b);
		ft_stack_push(stack_a, ft_stack_new(tmp));
	}
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp;

	if ((*stack_a))
	{
		tmp = ft_stack_pop(stack_a);
		ft_stack_push(stack_b, ft_stack_new(tmp));
	}
	ft_printf("pb\n");
}
