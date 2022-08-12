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

# include <time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# include "../libft/libft.h"

# define INT_SIZE 32
# define INT_MAX 2147483647

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

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		ft_arrlen(char **av);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_err(t_stack **stack_a, t_stack **stack_b);
void	print_both_stack(t_stack **stack_a, t_stack **stack_b);
int		get_min(t_stack **stack, int val);
int		get_distance(t_stack **stack, int index, int type);

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

t_stack	*ft_stack_new(int content);
int		ft_stack_pop(t_stack **stack_name);
void	ft_stack_push(t_stack **stack_name, t_stack *node);
void	ft_stack_clear(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stack_last(t_stack **stack_name);
void	ft_stack_add_back(t_stack **stack_name, t_stack *node);
void	ft_stack_del_back(t_stack **stack_name);
void	ft_stack_print(t_stack **stack_name);
int		ft_stack_len(t_stack **stack_name);
int		ft_stack_issort(t_stack **stack_name);
t_stack	**ft_stack_dup(t_stack **stack_a);
void	ft_stack_free(t_stack **stack_name);

void	sa(int print, t_stack **stack_a);
void	sb(int print, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(int print, t_stack **stack_a);
void	rb(int print, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(int print, t_stack **stack_a);
void	rrb(int print, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif