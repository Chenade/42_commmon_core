/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:46:17 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:46:53 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_print(t_stack **stack_name)
{
	t_stack	*tmp;

	tmp = *stack_name;
	while ((*stack_name))
	{
		ft_printf("%d, ", (*stack_name)->content);
		(*stack_name) = (*stack_name)->next;
	}
	(*stack_name) = tmp;
	ft_printf("\n");
}

void	print_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("========================\n");
	ft_printf("stack a [len => %d]: ", ft_stack_len(stack_a));
	ft_stack_print(stack_a);
	ft_printf("stack b [len => %d]: ", ft_stack_len(stack_b));
	ft_stack_print(stack_b);
	ft_printf("========================\n");
}
