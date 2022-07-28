/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:39:30 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:43:21 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid(char **av, int index)
{
	int	i;

	i = -1;
	while (av[index][++i])
	{
		if (!ft_isdigit(av[index][i]) && !(av[index][i] == '-' &&
			i == 0 && av[index][i + 1]))
			return (0);
	}
	if (av[index][0] == '-' && ft_atoi(av[index]) > 0)
		return (0);
	if (av[index][0] != '-' && ft_atoi(av[index]) < 0)
		return (0);
	i = 0;
	while (av[++i])
	{
		if (index != i && !ft_strcmp(av[index], av[i]))
			return (0);
	}
	return (1);
}

int	get_order(char **av, int index)
{
	int	num;
	int	order;
	int	i;

	num = ft_atoi(av[index]);
	order = 0;
	i = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i]) < num)
			order += 1;
		else if (ft_atoi(av[i]) == num && i != index)
			return (-1);
	}
	return (order);
}

int	init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	valid;
	int	tmp;

	count = argc;
	while (--count > 0)
	{
		valid = check_valid(argv, count);
		if (!valid)
			ft_print_err(stack_a, stack_b);
		tmp = get_order(argv, count);
		if (tmp > -1)
			ft_stack_push(stack_a, ft_stack_new(get_order(argv, count)));
		else
			ft_print_err(stack_a, stack_b);
	}
	return (0);
}

int	ft_stack_issort(t_stack **stack_name)
{
	int		res;
	int		last;
	t_stack	*org;

	if (!(*stack_name))
		return (0);
	res = 1;
	org = (*stack_name);
	last = (*stack_name)->content;
	if (!(*stack_name))
		return (res);
	while ((*stack_name))
	{
		(*stack_name) = (*stack_name)->next;
		if ((*stack_name) && last >= (*stack_name)->content)
		{
			res = 0;
			break ;
		}
		if ((*stack_name))
			last = (*stack_name)->content;
	}
	(*stack_name) = org;
	return (res);
}

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
		res = sort_redix(stack_a, stack_b);
	return (res);
}
