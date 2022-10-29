#include "fdf.h"

void img_pix_put(t_data *d, int x, int y, int color)
{
    char *pixel;
    if (y >= 0 && y < HEIGHT)
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

int find_end_x(t_data *d, t_cord pos)
{
    (void) d;
    (void) pos;
    return (1);
}

int draw_line_x(t_data *d, t_cord pos)
{
    (void) d;
    (void) pos;
    // for (int j = 0; j <= 20; j ++)
        // img_pix_put(d, (delta_x + j), (((j) * 0) + delta_y), COLOR_WHITE);
    return (1);
}

int draw_x(t_data *d)
{
    int delta_x;
    int delta_y;

    delta_x = 500;
    delta_y = 500;

    for (int y = 0; y < d->map_h; y++)
    {
        delta_x = 500 - (22 * y);
        delta_y = 200 + 22 * y;
        for (int x = 0; x < d->map_w; x++)
        {
            if (x + 1 != d->map_w)
                for (int j = 0; j <= 20; j ++)
                    img_pix_put(d, (delta_x + j), (((j) * tan(45)) + delta_y), COLOR_RED);
            if (y + 1 != d->map_h)
                for (int j = 0; j <= 20; j ++)
                    img_pix_put(d, (delta_x - j), (((j) * tan(45)) + delta_y), COLOR_WHITE);
            delta_x += 25;
            delta_y += 25;
        }
    }
    return (0);
}

void draw_all_img(t_data *d)
{
    ft_bzero(&d->curr_start, sizeof(t_cord));
    ft_bzero(&d->curr_end, sizeof(t_cord));
    draw_x(d);
}

int render_frame(t_data *d)
{
    if (d->win_ptr == NULL)
        return (1);
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.mlx_img, 0, 0);
    return (0);
}

int fdf(char *filename)
{
    t_data d;

    ft_bzero(&d, sizeof(d));
    init_mlx(&d, filename);
    if(read_file(&d, filename))
        return (1);
    ft_printf("map height: %d, map width: %d\n", d.map_h, d.map_w);
    draw_all_img(&d);
    mlx_loop_hook(d.mlx_ptr, render_frame, &d);
    mlx_hook(d.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &d);
    mlx_hook(d.win_ptr, ClientMessage,
             StructureNotifyMask, &handle_exit, &d);
    mlx_loop(d.mlx_ptr);
    free_data(&d);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    int status;

    if (argc != 2 || !check_filename(argv[1]))
    {
        ft_printf("Error: Usage: ./fdf {filename}.fdf\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0 || read(fd, 0, 0))
    {
        ft_printf("Error: Cannot open file.\n");
        return (1);
    }
    close (fd);
    status = fdf(argv[1]);
    return (status);
}