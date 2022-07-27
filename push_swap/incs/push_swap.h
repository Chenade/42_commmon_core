#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# include "../libft/libft.h"

# define INT_SIZE sizeof(int) * 8 /* Size of int in bits */
# define INT_MAX 2147483647

typedef struct s_stack
{
    int content;
	struct s_stack *next;
} t_stack;

int	    ft_strcmp(char *s1, char *s2);
void    ft_print_err(char *msg, t_stack **stack_a, t_stack **stack_b);
void    print_both_stack(t_stack **stack_a, t_stack **stack_b);

int     sort_redix(t_stack **stack_a, t_stack **stack_b);
int     sort_3(t_stack **stack_a, t_stack **stack_b);
int     push_swap(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_stack_new(int content);
int	    ft_stack_pop(t_stack **stack_name);
void	ft_stack_push(t_stack **stack_name, t_stack *node);
void    ft_stack_clear(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stack_last(t_stack **stack_name);
void	ft_stack_add_back(t_stack **stack_name, t_stack *node);
void	ft_stack_del_back(t_stack **stack_name);
void    ft_stack_print(t_stack **stack_name);
int	    ft_stack_len(t_stack **stack_name);
int	    ft_stack_isSort(t_stack **stack_name);

void    sa(int print, t_stack **stack_a);
void    sb(int print, t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(int print, t_stack **stack_a);
void    rb(int print, t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(int print, t_stack **stack_a);
void    rrb(int print, t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);


#endif