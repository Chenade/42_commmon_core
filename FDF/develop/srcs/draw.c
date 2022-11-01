#include "fdf.h"

int FT_ABS(int num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

static void	ft_lines_draw(t_data *d, t_cord f, t_cord s)//, t_color c)
{
	t_cord	delta;
	t_cord	sign;
	t_cord	cur;
	int		error[2];

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
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

int ft_matrix_rotate(t_data *d, int dx, int dy, int dz)
{
    (void) dx;
    (void) dy;
    (void) dz;
    free_cord_map(d);
    init_map(d);
    // rotate x
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            d->map_3d[xy_to_x(d, x, y)]->x = d->map_3d[xy_to_x(d, x, y)]->x;
            d->map_3d[xy_to_x(d, x, y)]->y = d->map_3d[xy_to_x(d, x, y)]->y * cos(d->rotation->x) + d->map_3d[xy_to_x(d, x, y)]->z * sin(d->rotation->x);
            d->map_3d[xy_to_x(d, x, y)]->z = d->map_3d[xy_to_x(d, x, y)]->y * sin(d->rotation->x) * -1 + d->map_3d[xy_to_x(d, x, y)]->z * cos(d->rotation->x);
        }
    }
    // // rotate y
    // for (int y = 0; y < d->map_h; y++)
    // {
    //     for (int x = 0; x < d->map_w; x++)
    //     {
    //         d->map_3d[xy_to_x(d, x, y)]->x = d->map_3d[xy_to_x(d, x, y)]->x * cos(dy) + d->map_3d[xy_to_x(d, x, y)]->z * sin(dy);
    //         d->map_3d[xy_to_x(d, x, y)]->y = d->map_3d[xy_to_x(d, x, y)]->y;
    //         d->map_3d[xy_to_x(d, x, y)]->z = d->map_3d[xy_to_x(d, x, y)]->x * sin(dy) * -1 + d->map_3d[xy_to_x(d, x, y)]->z * cos(dy);
    //     }
    // }
    // // rotate z
    // for (int y = 0; y < d->map_h; y++)
    // {
    //     for (int x = 0; x < d->map_w; x++)
    //     {
    //         d->map_3d[xy_to_x(d, x, y)]->x = d->map_3d[xy_to_x(d, x, y)]->x * cos(dz) - d->map_3d[xy_to_x(d, x, y)]->y * sin(dz);
    //         d->map_3d[xy_to_x(d, x, y)]->y = d->map_3d[xy_to_x(d, x, y)]->x * cos(dz) + d->map_3d[xy_to_x(d, x, y)]->y * sin(dz);
    //         d->map_3d[xy_to_x(d, x, y)]->z = d->map_3d[xy_to_x(d, x, y)]->z;
    //     }
    // }
    return (0);
}

int ft_matrix_to_vector(t_data *d)
{
    t_cord  *_2d;
    t_cord  *_3d;
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            _2d = d->map_2d[xy_to_x(d, x, y)];
            _3d = d->map_3d[xy_to_x(d, x, y)];
            _2d->x = (_3d->x * d->u->x + _3d->y * d->u->y +_3d->z * d->u->z) + 500;
            _2d->y = (_3d->x * d->v->x + _3d->y * d->v->y +_3d->z * d->v->z) + 500;
        }
    }
    return (0);
}

void draw_maps(t_data *d)
{
    ft_bzero(d->img.addr, d->img.line_len * 0.6 * HEIGHT);
    ft_matrix_to_vector(d);
    // ft_matrix_rotate(d, 45, 0, 0);
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
    // ft_printf("rotate: %d\n", d->rotation->x);
}