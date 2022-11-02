#include "fdf.h"

int init_vector(t_vector *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
    return (0);
}


int init_map3d(t_data *d)
{
    int x;
    int y;

    y = -1;
    d->map_3d = (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
    ft_bzero(d->map_3d, sizeof(t_vector *));
    while (++y < (d->map_h * d->map_w))
    {
        d->map_3d[y] = (t_vector *) malloc(sizeof(t_vector));
        ft_bzero(d->map_3d[y], sizeof(t_vector *));
    }
    y = -1;
    while (++y < d->map_h)
    {
        x = -1;
        while (++x < d->map_w)
        {
            d->map_3d[xy_to_x(d, x, y)]->x = x * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->y = y * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->z = atoi(d->map[xy_to_x(d, x, y)]) * d->height;
        }
    }
    return (0);
}


int init_map(t_data *d)
{
    int x;
    int y;

    y = -1;
    d->map_2d = (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
    ft_bzero(d->map_2d, sizeof(t_vector *));
    while (++y < (d->map_h * d->map_w))
    {
        d->map_2d[y] = (t_vector *) malloc(sizeof(t_vector));
        ft_bzero(d->map_2d[y], sizeof(t_vector *));
    }
    y = -1;
    while (++y < d->map_h)
    {
        x = -1;
        while (++x < d->map_w)
            init_vector(d->map_2d[xy_to_x(d, x, y)]);
    }
    init_map3d(d);
    return (0);
}

int init_setup(t_data *d)
{
    d->u = (t_vector *) malloc(sizeof(t_vector));
    ft_bzero(d->u, sizeof(t_vector *));
    d->u->x = 1;
    d->u->y = 0;
    d->u->z = 0;
    d->v = (t_vector *) malloc(sizeof(t_vector));
    ft_bzero(d->v, sizeof(t_vector *));
    d->v->x = 0;
    d->v->y = 0;
    d->v->z = 1;
    d->rotation = (t_vector *) malloc(sizeof(t_vector));
    ft_bzero(d->rotation, sizeof(t_vector *));
    d->rotation->x = 13;
    d->rotation->y = 16;
    d->rotation->z = 3;
    d->center = (t_vector *) malloc(sizeof(t_vector));
    ft_bzero(d->center, sizeof(t_vector *));
    d->center->x = 0;
    d->center->y = 0;
    d->center->z = 0;
    return (0);
}

int init_var(t_data *d)
{
    // int max;

    d->line_length = 40;
    d->height = 5;
    init_map(d);
    init_setup(d);
    // max = sqrt((d->map_w * d->map_w) + (d->map_h * d->map_h));
    // ft_printf("max: %d. \n", max / d->w);
    // d->line_length = 5;
    return (0);
}
