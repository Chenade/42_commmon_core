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
    // ft_printf("%d\n", (*stack_name)->content);
    res = (*stack_name)->content;
		tmp = (*stack_name)->next;
    free(*stack_name);
		*stack_name = tmp;
	}
  return (res);
}

void	ft_stack_push(t_stack **stack_name, t_stack *new)
{
	if (*stack_name)
  {
    new->next = *stack_name;
    *stack_name = new;    
  }
	else
		*stack_name = new;
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
