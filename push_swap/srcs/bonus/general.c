#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	t[2];
	int	ans;

	i = 0;
	ans = 0;
	while (!ans)
	{
		if (s1[i])
			t[0] = (int) s1[i];
		else
			t[0] = 0;
		if (s2[i])
			t[1] = (int) s2[i];
		else
			t[1] = 0;
		ans = t[0] - t[1];
		if (t[0] == 0 && t[1] == 0)
			break ;
		i += 1;
	}
	return (ans);
}

void	ft_print_err(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	ft_stack_clear(stack_a, stack_b);
	exit(1);
}

int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = (*stack);
	min = head->content;
	while (head->next)
	{
		head = head->next;
		if ((head->content < min) && head->content != val)
			min = head->content;
	}
	return (min);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->content == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
