/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:43:43 by ykuo              #+#    #+#             */
/*   Updated: 2022/07/28 23:50:54 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INT_INF 10000

int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

int	*ft_lis_ans(int lis_length, int	*index, int *A, int n)
{
	int	i;
	int	tmp;
	int	*answer;

	answer = (int *) malloc((lis_length + 1) * sizeof(int));
	if (!answer)
		return (NULL);
	answer[lis_length] = '\0';
	i = n;
	tmp = lis_length;
	while (--i >= 0)
	{
		if (index[i] == tmp)
		{
			answer[tmp] = A[i];
			--tmp;
		}
	}
	free (index);
	return (answer);
}

int	*ft_lis(int *A, int n)
{
	int	i;
	int	lis_length;
	int	*lis;
	int	*index;

	lis_length = -1;
	lis = (int *) malloc((n + 1) * sizeof(int));
	index = (int *) malloc((n + 1) * sizeof(int));
	if (!lis || !index)
		return (NULL);
	lis[0] = A[0];
	ft_bzero(index, n);
	i = -1;
	while (++i < n)
		lis[i] = INT_INF;
	i = -1;
	while (++i < n)
	{
		index[i] = search_replace(lis, 0, i, A[i]);
		if (lis_length < index[i])
			lis_length = index[i];
	}
	free (lis);
	return (ft_lis_ans(lis_length, index, A, n));
}

// find the longest increasing seqence
int	*find_lis(t_stack **stack_a)
{
	int		idx;
	int		*arr;
	int		*lis;
	t_stack	*head;
	t_stack	**stack_ans;

	stack_ans = ft_stack_dup(stack_a);
	while ((*stack_ans)->content != 0)
		ra(0, stack_ans);
	arr = (int *) malloc((ft_stack_len(stack_a) + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	ft_bzero(arr, ft_stack_len(stack_a));
	idx = 0;
	head = *stack_ans;
	while ((*stack_ans))
	{
		arr[idx++] = (*stack_ans)->content;
		(*stack_ans) = (*stack_ans)->next;
	}
	lis = ft_lis(arr, ft_stack_len(stack_a));
	free(arr);
	(*stack_ans) = head;
	ft_stack_free (stack_ans);
	return (lis);
}

void	split_lis(t_stack **stack_a, t_stack **stack_b, int *lis)
{
	int		count;
	int		i;
	int		is_brk;
	int		size;
	t_stack	*head;

	count = ft_stack_len(stack_a);
	head = (*stack_a);
	size = ft_stack_len(stack_a);
	while (!ft_stack_issort(stack_a))
	{
		i = 0;
		is_brk = 0;
		while (lis[++i] && !is_brk)
			if (lis[i] == (*stack_a)->content)
				is_brk = 1;
		if (is_brk || (*stack_a)->content == 0)
			ra(1, stack_a);
		else
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->content > (size / 2) && ft_stack_len(stack_b) > 1)
				rb(1, stack_b);
		}
	}
}
