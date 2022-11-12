#include "fdf.h"

void	free_cord_map(t_data *d)
{
	int	i;

	i = -1;
	while (d->map && d->map[++i])
	{
		if (d->map_2d[i])
			free(d->map_2d[i]);
		if (d->map_3d[i])
			free(d->map_3d[i]);
	}
	free(d->map_2d);
	free(d->map_3d);
}

void	free_data(t_data *d)
{
	int	i;

	if (d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	if (d->img.mlx_img)
		mlx_destroy_image(d->mlx_ptr, d->img.mlx_img);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	free(d->buf);
	free(d->u);
	free(d->v);
	free(d->rotation);
	free(d->center);
	i = -1;
	free_cord_map(d);
	while (d->map && d->map[++i])
		free(d->map[i]);
	free(d->map);
}

void	print_err(const char *err_msg, t_data *d)
{
	ft_printf("%s\n", err_msg);
	free_data(d);
	exit(EXIT_FAILURE);
}

int	check_filename(const char *name, const char *ext)
{
	int	x;

	x = ft_strlen(name) - 3;
	if (ft_strncmp(name + x, ext, 3))
		return (0);
	return (1);
}

int	ft_matrix_to_vector(t_data *d)
{
	int			x;
	int			y;
	t_vector	*_2d;
	t_vector	*_3d;

	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			_2d = d->map_2d[xy_to_x(d, x, y)];
			_3d = d->map_3d[xy_to_x(d, x, y)];
			_2d->x = (_3d->x * d->u->x + _3d->y * d->u->y + _3d->z * d->u->z);
			_2d->y = (_3d->x * d->v->x + _3d->y * d->v->y + _3d->z * d->v->z);
		}
	}
	return (0);
}
