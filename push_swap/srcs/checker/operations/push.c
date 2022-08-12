/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:45:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/22 13:10:48 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_helper.h"

void	pa(t_data *data)
{
	if (data->b.top < 1)
		return ;
	push(&data->a, pop(&data->b));
}

void	pb(t_data *data)
{
	if (data->a.top < 1)
		return ;
	push(&data->b, pop(&data->a));
}
