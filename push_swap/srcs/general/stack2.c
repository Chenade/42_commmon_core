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

#include "general.h"

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
	ft_printf("\n========================\n");
	ft_printf("stack a [len => %d]: ", ft_stack_len(stack_a));
	ft_stack_print(stack_a);
	ft_printf("stack b [len => %d]: ", ft_stack_len(stack_b));
	ft_stack_print(stack_b);
	ft_printf("========================\n");
}

void	ft_stack_reverse(t_stack **stack_ans, t_stack **stack_tmp2)
{
	t_stack	*head;

	head = *stack_tmp2;
	while ((*stack_tmp2))
	{
		ft_stack_push(stack_ans, ft_stack_new((*stack_tmp2)->content));
		(*stack_tmp2) = (*stack_tmp2)->next;
	}
	(*stack_tmp2) = head;
}

t_stack	**ft_stack_dup(t_stack **stack_a)
{
	t_stack	**stack_ans;
	t_stack	**stack_tmp2;
	t_stack	*head;

	head = *stack_a;
	stack_tmp2 = (t_stack **) malloc(ft_stack_len(stack_a) * sizeof(t_stack *));
	stack_ans = (t_stack **) malloc(ft_stack_len(stack_a) * sizeof(t_stack *));
	if (!stack_ans || !stack_tmp2)
		return (0);
	ft_bzero(stack_ans, (ft_stack_len(stack_a)) * sizeof(t_stack *));
	ft_bzero(stack_tmp2, (ft_stack_len(stack_a)) * sizeof(t_stack *));
	while ((*stack_a))
	{
		ft_stack_push(stack_tmp2, ft_stack_new((*stack_a)->content));
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
	ft_stack_reverse (stack_ans, stack_tmp2);
	ft_stack_free (stack_tmp2);
	return (stack_ans);
}

int	ft_stack_len(t_stack **stack_name)
{
	int		res;
	t_stack	*org;

	res = 0;
	if (!(*stack_name))
		return (res);
	org = (*stack_name);
	while ((*stack_name))
	{
		(*stack_name) = (*stack_name)->next;
		res += 1;
	}
	(*stack_name) = org;
	return (res);
}
