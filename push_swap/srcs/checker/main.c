/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:03:48 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/15 09:03:53 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		status;
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc > 1)
	{
		stack_a = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
		stack_b = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
		if (!stack_a || !stack_b)
			return (0);
		ft_bzero(stack_a, (argc - 1) * sizeof(t_stack *));
		ft_bzero(stack_b, (argc - 1) * sizeof(t_stack *));
		status = init_stack(argc, argv, stack_a, stack_b);
		if (!status)
			status = run_command(stack_a, stack_b);
		if (!status)
		{
			if (ft_stack_issort(stack_a))
				ft_printf (STR_OK);
			else
				ft_printf (STR_KO);
			ft_stack_clear (stack_a, stack_b);
		}
	}
	return (0);
}
