/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:43 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:50:54 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	head_a;

	print_both_stack(stack_a, stack_b);
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
