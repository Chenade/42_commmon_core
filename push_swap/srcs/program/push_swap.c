/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:39:30 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/12 06:21:11 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	res;

	size = ft_stack_len(stack_a);
	res = 0;
	if (ft_stack_issort(stack_a))
		return (res);
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		res = sort_big(stack_a, stack_b);
	return (res);
}
