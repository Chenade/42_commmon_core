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
int		get_distance(t_stack **stack, int index);

void	sort_3(t_stack **stack_a, t_stack **stack_b);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
int		sort_redix(t_stack **stack_a, t_stack **stack_b);
int		sort_big(t_stack **stack_a, t_stack **stack_b);

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