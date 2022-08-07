/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:45:01 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:46:04 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

int	ft_stack_pop(t_stack **stack_name)
{
	t_stack	*tmp;
	int		res;

	res = 0;
	if (*stack_name)
	{
		res = (*stack_name)->content;
		tmp = (*stack_name)->next;
		free(*stack_name);
		*stack_name = tmp;
	}
	return (res);
}

void	ft_stack_push(t_stack **stack_name, t_stack *node)
{
	if (*stack_name)
	{
		node->next = *stack_name;
		*stack_name = node;
	}
	else
		*stack_name = node;
}

void	ft_stack_free(t_stack **stack_name)
{
	t_stack	*tmp;

	while (*stack_name)
	{
		tmp = (*stack_name)->next;
		free(*stack_name);
		*stack_name = tmp;
	}
	free(stack_name);
}

void	ft_stack_clear(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
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
