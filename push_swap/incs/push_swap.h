/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:54:39 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:55:22 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./general.h"

typedef struct s_move
{
	int	num_a;
	int	num_b;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	count;
}	t_move;

int		ft_arrlen(char **av);

void	sort_3(t_stack **stack_a, t_stack **stack_b);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
int		sort_redix(t_stack **stack_a, t_stack **stack_b);
int		sort_big(t_stack **stack_a, t_stack **stack_b);

int		search_replace(int *lis, int left, int right, int key);
int		*ft_lis_ans(int lis_length, int	*index, int *A, int n);
int		*ft_lis(int *A, int n);
int		*find_lis(t_stack **stack_a);
void	split_lis(t_stack **stack_a, t_stack **stack_b, int *lis);

void	init_move(t_move **move, t_move **org, int init);
void	ft_totop(t_stack **stack_name, int val, t_move **move, int name);
int		get_min_stack(t_stack **stack_a, t_stack **stack_b);
t_move	*ft_minmove(t_stack **stack_a, t_stack **stack_b);
void	ft_move(t_stack **stack_a, t_stack **stack_b, t_move *move);

int		check_valid(char **av, int index);
int		get_order(char **av, int index);
int		init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);
int		push_swap(t_stack **stack_a, t_stack **stack_b);

#endif