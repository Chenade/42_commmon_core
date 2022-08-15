/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:04:28 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/15 09:04:30 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	check_valid(char **av, int index)
{
	int	i;

	i = -1;
	while (av[index][++i])
	{
		if (!ft_isdigit(av[index][i]) &&
			!(av[index][i] == '-' && i == 0 && av[index][i + 1]))
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
