#include "fdf.h"

int draw_y(t_data *d, int x, int y)
{
    int j;

    j = 0;
    while (j++ <= 25)
        img_pix_put(d, (d->map_draw[xy_to_x(d, x, y)]->x - j), (((j) * tan(60)) + d->map_draw[xy_to_x(d, x, y)]->y), COLOR_WHITE);
    d->map_draw[xy_to_x(d, x, y + 1)]->x = (d->map_draw[xy_to_x(d, x, y)]->x - (j - 1));
    d->map_draw[xy_to_x(d, x, y + 1)]->y = (((j - 1) * tan(60)) + d->map_draw[xy_to_x(d, x, y)]->y);
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

    j = 0;
    while (j++ <= 25)
        img_pix_put(d, (d->map_draw[xy_to_x(d, x, y)]->x + j), (((j) * tan(120)) + d->map_draw[xy_to_x(d, x, y)]->y), COLOR_RED);
    d->map_draw[xy_to_x(d, x + 1, y)]->x = (d->map_draw[xy_to_x(d, x, y)]->x + j - 1);
    d->map_draw[xy_to_x(d, x + 1, y)]->y = (((j - 1) * tan(120)) + d->map_draw[xy_to_x(d, x, y)]->y);
    return (0);
}

void draw_maps(t_data *d)
{
    d->map_draw[0]->x = 500;
    d->map_draw[0]->y = 500;
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
}