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

int	ft_strcmp(char *s1, char *s2);
void ft_print_err(char *msg, t_stack **stack_a, t_stack **stack_b);
char *convert_to_binary(int num);
void ft_push(char element, char stack[], int *top, int stackSize);
void ft_pop(char stack[], int *top, int stackSize);
t_stack	*ft_stack_new(int content);
void  ft_stack_clear(t_stack **stack_name);
int	ft_stack_pop(t_stack **stack_name);
void	ft_stack_push(t_stack **stack_name, t_stack *new);


#endif