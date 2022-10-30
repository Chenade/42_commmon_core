#include "fdf.h"

int draw_y(t_data *d, int x, int y)
{
    int j;
    t_cord *start;

    j = 0;
    start = d->map_draw[xy_to_x(d, x, y)];
    while (j++ <= d->line_length)
        img_pix_put(d, (start->x - j), (((j) * tan(82)) + start->y), COLOR_WHITE);
    d->map_draw[xy_to_x(d, x, y + 1)]->x = (d->map_draw[xy_to_x(d, x, y)]->x - (d->line_length));
    d->map_draw[xy_to_x(d, x, y + 1)]->y = (((d->line_length) * tan(82)) + d->map_draw[xy_to_x(d, x, y)]->y);
    d->map_draw[xy_to_x(d, x + 1, y)]->z = ft_atoi(d->map[xy_to_x(d, x, y + 1)]);
    return (0);
}

int find_end_x(t_data *d, t_cord pos)
{
    (void) d;
    (void) pos;
    return (1);
}

int draw_x(t_data *d, int x, int y)
{
    int j;
    t_cord *start;

    j = 0;
    start = d->map_draw[xy_to_x(d, x, y)];
    while (j++ <= d->line_length)
        img_pix_put(d, (start->x + j), (((j) * tan(120)) + start->y), COLOR_RED);
    d->map_draw[xy_to_x(d, x + 1, y)]->x = (d->map_draw[xy_to_x(d, x, y)]->x + d->line_length);
    d->map_draw[xy_to_x(d, x + 1, y)]->y = (((d->line_length) * tan(120)) + d->map_draw[xy_to_x(d, x, y)]->y);
    d->map_draw[xy_to_x(d, x + 1, y)]->z = ft_atoi(d->map[xy_to_x(d, x + 1, y)]);
    return (0);
}

void draw_maps(t_data *d)
{
    d->map_draw[0]->x = 700;
    d->map_draw[0]->y = 10;
    d->map_draw[0]->z = ft_atoi(d->map[0]);
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            if (x + 1 != d->map_w)
                draw_x(d, x ,y);
            if (y + 1 != d->map_h)
                draw_y(d, x ,y);
        }
    }
    // print_map(d);
}