/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:11:41 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/22 13:02:47 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "../libft/libft.h"

# define STR_ERROR "Error\n"

# define STR_OK "OK\n"
# define STR_KO "KO\n"

// # define STR_RA "ra\n"
// # define STR_RB "rb\n"
// # define STR_RR "rr\n"

// # define STR_RRA "rra\n"
// # define STR_RRB "rrb\n"
// # define STR_RRR "rrr\n"

// # define STR_PA "pa\n"
// # define STR_PB "pb\n"

// # define STR_SA "sa\n"
// # define STR_SB "sb\n"
// # define STR_SS "ss\n"

// typedef struct s_element
// {
// 	int		value;
// 	t_index	sort_idx;
// }				t_element;

// typedef struct s_stack
// {
// 	t_element	*content;
// 	t_index		top;
// }				t_stack;

// typedef struct s_data
// {
// 	t_stack	a;
// 	t_stack	b;
// 	t_list	*insts;
// }				t_data;

// typedef void	(*t_inst)(t_data *);

// typedef struct s_move
// {
// 	t_inst	stack_a_inst;
// 	size_t	stack_a_inst_rpt;
// 	t_inst	stack_b_inst;
// 	size_t	stack_b_inst_rpt;
// 	t_bool	do_inst_after_push;
// }				t_move;

// /* main.c */

// int		throw_error(t_data *data);

// /* stack.c */

// t_stack	*alloc_stack(t_stack *stack, size_t stack_size);
// int		check_stack_duplicate(t_stack stack, int nbr);
// t_bool	is_stack_sorted(t_stack stack);
// void	free_stacks(t_data *data);

// /* sort/sort_helper.c */

// void	sort_three_elem_stack(t_data *data);
// void	sort_small_stack(t_data *data, int argc);
// void	do_op(t_data *data, t_inst inst, size_t rpt);

// /* sort/sort_init.c */

// void	index_stack(t_stack *stack);
// void	init_stacks(t_data *data);

// /* sort/sort_utils.c */

// t_index	find_biggest_in_stack(t_stack stack);
// t_index	find_smallest_in_stack(t_stack stack);
// t_bool	is_biggest(t_stack stack, t_element to_push);
// t_bool	is_in_between(int range_a, int range_b, int nbr);

// /* sort/sort_element.c */

// void	move_element_to_stack_a_top(t_data *data, t_move *move, t_index idx);
// void	move_element_to_stack_b_top(t_data *data, t_move *move, t_index idx);
// void	move_element_to_stack_a_bottom(t_data *data, t_move *move, t_index idx);

// /* sort/sort_algorithm.c */

// void	do_sort(t_data *data);

// /* rotate.c */

// void	rb(t_data *data);
// void	ra(t_data *data);
// void	rr(t_data *data);

// /* reverse_rotate.c */

// void	rra(t_data *data);
// void	rrb(t_data *data);
// void	rrr(t_data *data);

// /* push.c */

// void	pa(t_data *data);
// void	pb(t_data *data);

// /* swap.c */

// void	sa(t_data *data);
// void	sb(t_data *data);
// void	ss(t_data *data);

// /* debug_tools.c */

// void	show_stacks(t_data data);

// /* parsing.c */

// int		fill_stack_from_args(t_stack *stack, int argc, char **argv);

// /* instructions.c */

// void	print_instructions(t_data *data);
// t_list	*add_instruction(t_data *data, t_inst inst);

#endif
