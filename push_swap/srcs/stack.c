#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

int	ft_stack_pop(t_stack **stack_name)
{
	t_stack *tmp;
	int     res;

	res = 0;
	if (*stack_name)
	{
		res = (*stack_name)->content;
		tmp = (*stack_name)->next;
		free(*stack_name);
		*stack_name = tmp;
	}
	return (res);
}

void	ft_stack_push(t_stack **stack_name, t_stack *node)
{
	if (*stack_name)
	{
		node->next = *stack_name;
		*stack_name = node;    
	}
	else
		*stack_name = node;
}

void  ft_stack_clear(t_stack **stack_name)
{
	t_stack	*tmp;

	while (*stack_name)
	{
		tmp = (*stack_name)->next;
    	free(*stack_name);
		*stack_name = tmp;
	}
	free(stack_name);
}

void  ft_stack_print(t_stack **stack_name)
{
	t_stack	*tmp;

	tmp = *stack_name;
	while ((*stack_name))
	{
		ft_printf("%d, ", (*stack_name)->content);
		(*stack_name) = (*stack_name)->next;
	}
	(*stack_name) = tmp;
	ft_printf("\n");
}
