#include "fdf.h"

int ft_linear(t_data *d, t_vector delta, int pos)
{
	(void) d;
	(void) delta;
	(void) pos;
	if (ft_atoi(d->map[pos]) == 0)
    	return (COLOR_WHITE);
    return (COLOR_RED);
}

void	ft_lines_draw(t_data *d, t_vector f, t_vector s, int pos)
{
	t_vector	delta;
	t_vector	sign;
	t_vector	cur;
	int			error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		img_pix_put(d, cur.x, cur.y, ft_linear(d, delta, pos));
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

void	draw_maps(t_data *d)
{
	int	x;
	int	y;

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
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x + 1, y)]), xy_to_x(d, x + 1, y));
            if (y + 1 != d->map_h)
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x, y + 1)]), xy_to_x(d, x, y + 1));
        }
    }
}

void	projection_isometric(t_data *d)
{
    init_vector(d->rotation, 21, 16, -3);
	draw_maps(d);
}

void	projection_first_angel(t_data *d)
{
	init_vector(d->rotation, 0, 0, 0);
	draw_maps(d);
}
