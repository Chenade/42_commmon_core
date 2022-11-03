#include "fdf.h"

void img_pix_put(t_data *d, int x, int y, int color)
{
    char *pixel;
    if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
    {
        pixel = d->img.addr + (y * d->img.line_len + x * (d->img.bpp / 8));
        *(unsigned int *)pixel = color;
    }
}

int getpixelcolor(t_img *img, int x, int y)
{
    return (*(unsigned int *)(img->addr + x * (img->bpp / 8) + y * img->line_len));
}

int encode_rgb(t_color c)
{
    return (c.r << 16 | c.g << 8 | c.b);
}

int xy_to_x(t_data *d, int x, int y)
{
    return (y * d->map_w + x);
}

int init_vector(t_vector *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    return (0);
}