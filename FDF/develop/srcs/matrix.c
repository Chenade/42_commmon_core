/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:13:13 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/13 16:13:14 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_matrix_rotate_x(t_data *d)
{
	int			x;
	int			y;
	t_vector	tmp;

	if (d->rotation->x != 0)
	{
		y = -1;
		while (++y < d->map_h)
		{
			x = -1;
			while (++x < d->map_w)
			{
				tmp.x = d->map_3d[xy_to_x(d, x, y)]->x;
				tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
				tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
				d->map_3d[xy_to_x(d, x, y)]->x = d->map_3d[xy_to_x(d, x, y)]->x;
				d->map_3d[xy_to_x(d, x, y)]->y
					= tmp.y * cos(d->rotation->x) + tmp.z * sin(d->rotation->x);
				d->map_3d[xy_to_x(d, x, y)]->z = tmp.y
					* sin(d->rotation->x) * -1 + tmp.z * cos(d->rotation->x);
			}
		}
	}
	ft_matrix_rotate_y(d);
	return (0);
}

int	ft_matrix_rotate_y(t_data *d)
{
	int			x;
	int			y;
	t_vector	tmp;

	if (d->rotation->y != 0)
	{
		y = -1;
		while (++y < d->map_h)
		{
			x = -1;
			while (++x < d->map_w)
			{
				tmp.x = d->map_3d[xy_to_x(d, x, y)]->x;
				tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
				tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
				d->map_3d[xy_to_x(d, x, y)]->x
					= tmp.x * cos(d->rotation->y) + tmp.z * sin(d->rotation->y);
				d->map_3d[xy_to_x(d, x, y)]->y = tmp.y;
				d->map_3d[xy_to_x(d, x, y)]->z = tmp.x
					* sin(d->rotation->y) * -1 + tmp.z * cos(d->rotation->y);
			}
		}
	}
	ft_matrix_rotate_z(d);
	return (0);
}

int	ft_matrix_rotate_z(t_data *d)
{
	int			x;
	int			y;
	t_vector	tmp;

	if (d->rotation->z != 0)
	{
		y = -1;
		while (++y < d->map_h)
		{
			x = -1;
			while (++x < d->map_w)
			{
				tmp.x = d->map_3d[xy_to_x(d, x, y)]->x;
				tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
				tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
				d->map_3d[xy_to_x(d, x, y)]->x
					= tmp.x * cos(d->rotation->z) - tmp.y * sin(d->rotation->z);
				d->map_3d[xy_to_x(d, x, y)]->y = tmp.x
					* cos(d->rotation->z) + tmp.y * sin(d->rotation->z);
				d->map_3d[xy_to_x(d, x, y)]->z = tmp.z;
			}
		}
	}
	return (0);
}

int	ft_matrix_move(t_data *d, t_vector min, t_vector max)
{
	int	x;
	int	y;
	int	size;

	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			size = (max.x - min.x) / 2;
			d->map_2d[xy_to_x(d, x, y)]->x
				+= ft_abs(min.x) + WIDTH / 2 - size + d->center->x;
			size = (max.y - min.y) / 2;
			d->map_2d[xy_to_x(d, x, y)]->y
				+= ft_abs(min.y) + HEIGHT / 2 - size - d->center->y;
		}
	}
	return (0);
}

int	ft_matrix_center(t_data *d)
{
	int			x;
	int			y;
	t_vector	min;
	t_vector	max;

	min.x = d->map_2d[0]->x;
	min.y = d->map_2d[0]->y;
	max.x = d->map_2d[0]->x;
	max.y = d->map_2d[0]->y;
	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			min.x = ft_min(min.x, d->map_2d[xy_to_x(d, x, y)]->x);
			min.y = ft_min(min.y, d->map_2d[xy_to_x(d, x, y)]->y);
			max.x = ft_max(max.x, d->map_2d[xy_to_x(d, x, y)]->x);
			max.y = ft_max(max.y, d->map_2d[xy_to_x(d, x, y)]->y);
		}
	}
	ft_matrix_move(d, min, max);
	return (0);
}
