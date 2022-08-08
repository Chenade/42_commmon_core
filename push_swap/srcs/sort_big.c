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
	int	*lis;

	print_both_stack(stack_a, stack_b);
	lis = find_lis(stack_a);
	int x = 0;
	ft_printf("{%d}, ", lis[x++]);
	while (lis && lis[x])
	{
		ft_printf("{%d}, ", lis[x]);
		x += 1;
	}
	print_both_stack(stack_a, stack_b);
	free (lis);
	return (1);
}
