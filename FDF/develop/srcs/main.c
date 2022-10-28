#include "fdf.h"
const t_pattern patterns[NB_PATTERN] = {(t_pattern){{0, 6, 16, 0}, 2}, (t_pattern){{0, 4, 16, 0}, 3}};

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

int draw_x(t_data *d)
{
    int i;
    int x;
    int y;
    int rat_x = 1;
    int rat_y = 1;

    i = -1;
    x = 200;
    y = 200;
    while(d->map[++i])
    {
        if (i % d->map_w == 0)
        {
            x = 200;
            y += 25;
        }
        else
        {
            for (int j = 0; j <= 20; j ++)
                img_pix_put(d, (x + j), ((x + j) * rat_x / rat_y), COLOR_WHITE);
            x += 25;
        }
    }
    return (0);
}

int draw_y(t_data *d)
{
    int i;
    int x;
    int y;

    i = -1;
    x = 200;
    y = 200;
    while(d->map[++i])
    {
        if (i % d->map_w == 0)
        {
            x = 200;
            y += 25;
        }
        if (i / d->map_w != d->map_h - 1)
        {
            for (int j = 0; j <= 20; j ++)
                img_pix_put(d, x, (y + j), COLOR_WHITE);
            x += 25;
        }
    }
    return (0);
}

void draw_all_img(t_data *d)
{
    draw_x(d);
    draw_y(d);
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