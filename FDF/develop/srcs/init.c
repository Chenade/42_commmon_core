#include "fdf.h"

int	init_map3d(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	d->map_3d
		= (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
	if (!d->map_3d)
		print_err("Error: Memory allocate failed", d);
	ft_bzero(d->map_3d, sizeof(t_vector *));
	while (++y < (d->map_h * d->map_w))
		d->map_3d[y] = (t_vector *) ft_malloc(d, sizeof(t_vector));
	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			d->map_3d[xy_to_x(d, x, y)]->x = x * d->line_length;
			d->map_3d[xy_to_x(d, x, y)]->y = y * d->line_length;
			d->map_3d[xy_to_x(d, x, y)]->z
				= ft_atoi(d->map[xy_to_x(d, x, y)]) * -d->height;
		}
	}
	return (0);
}

int	init_map(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	d->map_2d
		= (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
	if (!d->map_2d)
		print_err("Error: Memory allocate failed", d);
	ft_bzero(d->map_2d, sizeof(t_vector *));
	while (++y < (d->map_h * d->map_w))
		d->map_2d[y] = (t_vector *) ft_malloc(d, sizeof(t_vector));
	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
			init_vector(d->map_2d[xy_to_x(d, x, y)], 0, 0, 0);
	}
	init_map3d(d);
	return (0);
}

int	init_var(t_data *d)
{
	int	i;
	int	max;

	init_map(d);
	d->u = (t_vector *) ft_malloc(d, sizeof(t_vector));
	init_vector(d->u, 1, 0, 0);
	d->v = (t_vector *) ft_malloc(d, sizeof(t_vector));
	init_vector(d->v, 0, 0, 1);
	d->rotation = (t_vector *) ft_malloc(d, sizeof(t_vector));
	init_vector(d->rotation, 21, 16, -3);
	d->center = (t_vector *) ft_malloc(d, sizeof(t_vector));
	init_vector(d->center, 200, 0, 0);
	d->line_length = (WIDTH / d->map_w) * 0.7;
	i = -1;
	max = 0;
	while (d->map[++i])
		max = ft_max(max, ft_abs(ft_atoi(d->map[i])));
	d->height = (HEIGHT / 3) / max;
	d->height2 = d->height / 2;
	d->projection = 1;
	return (0);
}
