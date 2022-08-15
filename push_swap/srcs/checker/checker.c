/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:04:06 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/15 09:04:08 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	str_to_cmd(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str, STR_SA) == 0)
		sa(0, stack_a);
	else if (ft_strcmp(str, STR_SB) == 0)
		sa(0, stack_b);
	else if (ft_strcmp(str, STR_SS) == 0)
		ss(0, stack_a, stack_b);
	else if (ft_strcmp(str, STR_PA) == 0)
		pa(0, stack_a, stack_b);
	else if (ft_strcmp(str, STR_PB) == 0)
		pb(0, stack_a, stack_b);
	else if (ft_strcmp(str, STR_RA) == 0)
		ra(0, stack_a);
	else if (ft_strcmp(str, STR_RB) == 0)
		rb(0, stack_b);
	else if (ft_strcmp(str, STR_RR) == 0)
		rr(0, stack_a, stack_b);
	else if (ft_strcmp(str, STR_RRA) == 0)
		rra(0, stack_a);
	else if (ft_strcmp(str, STR_RRB) == 0)
		rrb(0, stack_b);
	else if (ft_strcmp(str, STR_RRR) == 0)
		rrr(0, stack_a, stack_b);
	else
		return (-1);
	return (0);
}

static char	*get_line(char **line)
{
	*line = get_next_line(0);
	return (*line);
}

int	run_command(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		status;

	while (get_line(&line))
	{
		if (ft_strcmp(line, "\n") == 0)
		{
			free (line);
			break ;
		}
		status = str_to_cmd(line, stack_a, stack_b);
		free (line);
		if (status < 0)
		{
			ft_print_err(stack_a, stack_b);
			break ;
		}
	}
	return (status);
}
