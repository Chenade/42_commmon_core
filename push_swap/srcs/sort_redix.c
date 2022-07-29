/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_redix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:43 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:56:08 by ykuo             ###   ########.fr       */
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
