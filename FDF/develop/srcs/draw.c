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

int ft_matrix_rotate(t_data *d)
{
    free_cord_map(d);
    init_map(d);
    // rotate x
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            t_cord tmp;
            tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
            tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
            d->map_3d[xy_to_x(d, x, y)]->x = d->map_3d[xy_to_x(d, x, y)]->x;
            d->map_3d[xy_to_x(d, x, y)]->y = tmp.y * cos(d->rotation->x) + tmp.z * sin(d->rotation->x);
            d->map_3d[xy_to_x(d, x, y)]->z = tmp.y * sin(d->rotation->x) * -1 + tmp.z * cos(d->rotation->x);
        }
    }
    // // rotate y
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            t_cord tmp;
            tmp.x = d->map_3d[xy_to_x(d, x, y)]->x;
            tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
            tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
            d->map_3d[xy_to_x(d, x, y)]->x = tmp.x * cos(d->rotation->y) + tmp.z * sin(d->rotation->y);
            d->map_3d[xy_to_x(d, x, y)]->y = tmp.y;
            d->map_3d[xy_to_x(d, x, y)]->z = tmp.x * sin(d->rotation->y) * -1 + tmp.z * cos(d->rotation->y);
        }
    }
    // rotate z
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            t_cord tmp;
            tmp.x = d->map_3d[xy_to_x(d, x, y)]->x;
            tmp.y = d->map_3d[xy_to_x(d, x, y)]->y;
            tmp.z = d->map_3d[xy_to_x(d, x, y)]->z;
            d->map_3d[xy_to_x(d, x, y)]->x = tmp.x * cos(d->rotation->z) - tmp.y * sin(d->rotation->z);
            d->map_3d[xy_to_x(d, x, y)]->y = tmp.x * cos(d->rotation->z) + tmp.y * sin(d->rotation->z);
            d->map_3d[xy_to_x(d, x, y)]->z = tmp.z;
        }
    }
    ft_printf("rotate -> (%d, %d, %d)\n", d->rotation->x, d->rotation->y, d->rotation->z);
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
            _2d->x = (_3d->x * d->u->x + _3d->y * d->u->y +_3d->z * d->u->z);
            _2d->y = (_3d->x * d->v->x + _3d->y * d->v->y +_3d->z * d->v->z);
        }
    }
    return (0);
}

int ft_matrix_move(t_data *d, t_cord min, t_cord max)
{
    int size;

    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            size = (max.x - min.x) / 2;
            d->map_2d[xy_to_x(d, x, y)]->x += ft_abs(min.x) + WIDTH / 2 - size + d->center->x;
            size = (max.y - min.y) / 2;
            d->map_2d[xy_to_x(d, x, y)]->y += ft_abs(min.y) + HEIGHT / 2 - size - d->center->y;
        }
    }
    ft_printf("move -> (%d, %d)\n", d->center->x, d->center->y);
    return (0);
}

int ft_matrix_center(t_data *d)
{
    t_cord  min;
    t_cord  max;

    min.x = d->map_2d[0]->x;
    min.y = d->map_2d[0]->y;
    max.x = d->map_2d[0]->x;
    max.y = d->map_2d[0]->y;
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            if (min.x > d->map_2d[xy_to_x(d, x, y)]->x)
                min.x = d->map_2d[xy_to_x(d, x, y)]->x;
            if (min.y > d->map_2d[xy_to_x(d, x, y)]->y)
                min.y = d->map_2d[xy_to_x(d, x, y)]->y;
            if (max.x < d->map_2d[xy_to_x(d, x, y)]->x)
                max.x = d->map_2d[xy_to_x(d, x, y)]->x;
            if (max.y < d->map_2d[xy_to_x(d, x, y)]->y)
                max.y = d->map_2d[xy_to_x(d, x, y)]->y;
        }
    }
    ft_matrix_move(d, min, max);
    return (0);
}

void draw_maps(t_data *d)
{
    ft_bzero(d->img.addr, d->img.line_len * HEIGHT);
    // ft_matrix_zoom(d);
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