/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:37:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/22 13:11:13 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These two inline function are only here to comply with the norms. */

static inline void	swap_a(t_data *data, t_element *last_val, t_element *saved,
																	t_sindex *i)
{
	*saved = data->a.content[*i];
	data->a.content[*i] = *last_val;
	*last_val = *saved;
	(*i)--;
}

static inline void	swap_b(t_data *data, t_element *last_val, t_element *saved,
																	t_sindex *i)
{
	*saved = data->b.content[*i];
	data->b.content[*i] = *last_val;
	*last_val = *saved;
	(*i)--;
}

/* Reverse rotate the stack a. Shift down all elements by 1. The last element
 * becomes the first one. */

void	rra(t_data *data)
{
	t_sindex	i;
	t_element	last_val;
	t_element	saved;

	if (data->a.top < 2)
		return ;
	last_val = data->a.content[data->a.top - 1];
	i = data->a.top - 2;
	while (i >= 0)
		swap_a(data, &last_val, &saved, &i);
	data->a.content[data->a.top - 1] = last_val;
}

/* Reverse rotate the stack b. Shift down all elements by 1. The last element
 * becomes the first one. */

void	rrb(t_data *data)
{
	t_sindex	i;
	t_element	last_val;
	t_element	saved;

	if (data->b.top < 2)
		return ;
	last_val = data->b.content[data->b.top - 1];
	i = data->b.top - 2;
	while (i >= 0)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[data->b.top - 1] = last_val;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
