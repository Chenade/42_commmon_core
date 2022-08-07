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

int search_replace(int *lis, int left, int right, int key) 
{
	int mid;

	for (mid = (left+right)/2; left <= right; mid = (left+right)/2) {
		if (lis[mid] > key) 
				right = mid - 1;
		else if (lis[mid] == key)
				return mid;
		else if (mid+1 <= right && lis[mid+1] >= key)
		{
			lis[mid+1] = key;
			return mid+1;
		} else 
			left = mid + 1;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return mid;
	}
	lis[mid+1] = key;
	return (mid+1);
}

int *ft_lis(int *A, int n)
{
	return (NULL);
	int i, tmp, lis_length = -1; 
	int *answer;
	// int LIS[n], index[n];
	// LIS[0] = A[0];
	// ft_bzero(index, n);
	answer = NULL;
	// for (i = 1; i < n; ++i) {
	// 	LIS[i] = INT_INF;
	// }
	// for (i = 1; i < n; ++i) {
	// 	index[i] = search_replace(LIS, 0, i, A[i]);
	// 	if (lis_length < index[i]) {
	// 			lis_length = index[i];
	// 	}
	// }
	// answer = (int *) malloc((lis_length + 1) * sizeof(int));
	// ft_bzero(answer, lis_length + 2);
	// for (i = n-1, tmp = lis_length; i >= 0; --i) {
	// 	if (index[i] == tmp) {
	// 		answer[tmp] = A[i];
	// 		--tmp;
	// 	}
	// }
	return (answer);
}

// find the longest increasing seqence
int	*find_lis(t_stack **stack_a)
{
	int		idx;
	int		*arr;
	int		*lis;
	t_stack	**stack_ans;

	stack_ans = ft_stack_dup(stack_a);
	while ((*stack_ans)->content != 0)
		ra(0, stack_ans);
	// arr = (int *) malloc((ft_stack_len(stack_a) + 1) * sizeof(int));
	// if (!arr)
	// 	return (NULL);
	// ft_bzero(arr, ft_stack_len(stack_a));
	// idx = 0;
	// while ((*stack_ans))
	// {
	// 	arr[idx] = (*stack_ans)->content;
	// 	idx += 1;
	// 	(*stack_ans) = (*stack_ans)->next;
	// }
	// lis = ft_lis(arr, ft_stack_len(stack_a));
	// free(arr);
	ft_stack_free (stack_ans);
	return (NULL);
}

int	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	*lis;

	print_both_stack(stack_a, stack_b);
	lis = find_lis(stack_a);
	// int x = 0;
	// ft_printf("{%d}, ", lis[x++]);
	// while (lis && lis[x])
	// {
	// 	ft_printf("{%d}, ", lis[x]);
	// 	x += 1;
	// }
	print_both_stack(stack_a, stack_b);
	// free (lis);
	return (1);
}
