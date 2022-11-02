#include "fdf.h"

static void	ft_lines_draw(t_data *d, t_vector f, t_vector s)//, t_color c)
{
	t_vector	delta;
	t_vector	sign;
	t_vector	cur;
	int		error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		img_pix_put(d, cur.x, cur.y, COLOR_RED);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

int draw_gui(t_data *d)
{
    (void) d;
    return (0);
}

int draw_second_projecion(t_data *d)
{
    (void) d;
    return (0);
}

void draw_maps(t_data *d)
{
	int	x;
	int	y;

    ft_bzero(d->img.addr, d->img.line_len * HEIGHT);
    ft_matrix_rotate_x(d);
    ft_matrix_to_vector(d);
    ft_matrix_center(d);
	y = -1;
    while (++y < d->map_h)
    {
        x = -1;
        while (++x < d->map_w)
        {
            t_vector cur = *(d->map_2d[xy_to_x(d, x, y)]);
            if (x + 1 != d->map_w)
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x + 1, y)]));
            if (y + 1 != d->map_h)
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x, y + 1)]));
        }
    }
}

int ft_matrix_to_vector(t_data *d)
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
            _2d->x = (_3d->x * d->u->x + _3d->y * d->u->y +_3d->z * d->u->z);
            _2d->y = (_3d->x * d->v->x + _3d->y * d->v->y +_3d->z * d->v->z);
        }
    }
    return (0);
}