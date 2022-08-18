/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:05:03 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/15 09:05:05 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define INT_SIZE 32
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		ft_arrlen(char **av);

/* general.c */
int		ft_strcmp(char *s1, char *s2);
void	ft_print_err(t_stack **stack_a, t_stack **stack_b);
int		get_min(t_stack **stack, int val);
int		get_distance(t_stack **stack, int index, int type);
int		ft_stack_issort(t_stack **stack_name);

/* stack */
t_stack	*ft_stack_new(int content);
int		ft_stack_pop(t_stack **stack_name);
void	ft_stack_push(t_stack **stack_name, t_stack *node);
void	ft_stack_clear(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stack_last(t_stack **stack_name);
void	ft_stack_add_back(t_stack **stack_name, t_stack *node);
void	ft_stack_del_back(t_stack **stack_name);
void	ft_stack_print(t_stack **stack_name);
int		ft_stack_len(t_stack **stack_name);
t_stack	**ft_stack_dup(t_stack **stack_a);
void	ft_stack_free(t_stack **stack_name);
void	print_both_stack(t_stack **stack_a, t_stack **stack_b);

/* cmd */
void	sa(int print, t_stack **stack_a);
void	sb(int print, t_stack **stack_b);
void	ss(int print, t_stack **stack_a, t_stack **stack_b);
void	pa(int print, t_stack **stack_a, t_stack **stack_b);
void	pb(int print, t_stack **stack_a, t_stack **stack_b);
void	ra(int print, t_stack **stack_a);
void	rb(int print, t_stack **stack_b);
void	rr(int print, t_stack **stack_a, t_stack **stack_b);
void	rra(int print, t_stack **stack_a);
void	rrb(int print, t_stack **stack_b);
void	rrr(int print, t_stack **stack_a, t_stack **stack_b);

/* parsing */
int		check_valid(char **av, int index);
int		get_order(char **av, int index);
int		init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);

#endif