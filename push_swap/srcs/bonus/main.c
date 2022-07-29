/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo & cmenasse<marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:05:31 by ykuo              #+#    #+#             */
/*   Updated: 2022/06/14 17:54:56 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int status;
	t_stack  **stack_a;
	t_stack  **stack_b;

	if (argc == 1)
		ft_print_err(stack_a, stack_b);
	stack_a = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
	stack_b = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
	if(!stack_a || ! stack_b)
		ft_print_err(stack_a, stack_b);
	ft_bzero(stack_a, (argc - 1) * sizeof(t_stack *));
	ft_bzero(stack_b, (argc - 1) * sizeof(t_stack *));
	status = init_stack(argc, argv, stack_a, stack_b);
	if (!status)
	{
		status = push_swap(stack_a, stack_b);
		ft_stack_clear (stack_a, stack_b);
	}
	return (status);
}