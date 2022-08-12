/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:41:56 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/22 13:11:26 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These two inline function are only here to comply with the norms. */

static inline void	swap_a(t_data *data, t_element *last_val, t_element *saved,
																	t_index *i)
{
	*saved = data->a.content[*i];
	data->a.content[*i] = *last_val;
	*last_val = *saved;
	(*i)++;
}

static inline void	swap_b(t_data *data, t_element *last_val, t_element *saved,
																	t_index *i)
{
	*saved = data->b.content[*i];
	data->b.content[*i] = *last_val;
	*last_val = *saved;
	(*i)++;
}

/* Rotate the stack a. Shift up all elements by 1. The first element becomes
 * the last one. */

void	ra(t_data *data)
{
	t_index		i;
	t_element	last_val;
	t_element	saved;

	if (data->a.top < 2)
		return ;
	last_val = data->a.content[0];
	i = 1;
	while (i < data->a.top)
		swap_a(data, &last_val, &saved, &i);
	data->a.content[0] = last_val;
}

/* Rotate the stack b. Shift up all elements by 1. The first element becomes
 * the last one. */

void	rb(t_data *data)
{
	t_index		i;
	t_element	last_val;
	t_element	saved;

	if (data->b.top < 2)
		return ;
	last_val = data->b.content[0];
	i = 1;
	while (i < data->b.top)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[0] = last_val;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
