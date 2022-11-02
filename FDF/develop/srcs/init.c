#include "fdf.h"

int init_map(t_data *d)
{
    int k;

    k = -1;
    d->map_3d = (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
    d->map_2d = (t_vector **) malloc((d->map_w * d->map_h) * sizeof(t_vector *));
    ft_bzero(d->map_3d, sizeof(t_vector *));
    while (++k < (d->map_h * d->map_w))
    {
        d->map_3d[k] = (t_vector *) malloc(sizeof(t_vector));
        d->map_2d[k] = (t_vector *) malloc(sizeof(t_vector));
        ft_bzero(d->map_3d[k], sizeof(t_vector *));
        ft_bzero(d->map_2d[k], sizeof(t_vector *));
    }
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            d->map_3d[xy_to_x(d, x, y)]->x = x * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->y = y * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->z = atoi(d->map[xy_to_x(d, x, y)]) * d->height;
            d->map_2d[xy_to_x(d, x, y)]->x = 0;
            d->map_2d[xy_to_x(d, x, y)]->y = 0;
            d->map_2d[xy_to_x(d, x, y)]->z = 0;
        }
    }
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
