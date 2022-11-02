#include "fdf.h"

static void	ft_lines_draw(t_data *d, t_cord f, t_cord s)//, t_color c)
{
	t_cord	delta;
	t_cord	sign;
	t_cord	cur;
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
    ft_bzero(d->img.addr, d->img.line_len * HEIGHT);
    ft_matrix_rotate(d);
    ft_matrix_to_vector(d);
    ft_matrix_center(d);
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            t_cord cur = *(d->map_2d[xy_to_x(d, x, y)]);
            if (x + 1 != d->map_w)
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x + 1, y)]));
            if (y + 1 != d->map_h)
                ft_lines_draw(d, cur, *(d->map_2d[xy_to_x(d, x, y + 1)]));
        }
    }
}