#include "fdf.h"
#include "keyboard.h"

int init_mlx(t_data *d, char *name)
{
    d->size = print_info(name);
    d->buf = (char *)malloc(d->size);
    bzero(d->buf, d->size);

    d->w = WIDTH;
    d->h = HEIGHT;

    {
        d->mlx_ptr = mlx_init();
        d->win_ptr = mlx_new_window(d->mlx_ptr, d->w, d->h, "fdf");
        if (!d->win_ptr)
            print_err("Failed to launch window.", d);
        d->img.mlx_img = mlx_new_image(d->mlx_ptr, d->w, d->h);
        if (!d->img.mlx_img)
            print_err("mlx new image error", d);
        d->img.addr = mlx_get_data_addr(d->img.mlx_img, &d->img.bpp,
                                       &d->img.line_len, &d->img.endian);
    }
    return (0);
}

int render_frame(t_data *d)
{
    if (d->win_ptr == NULL)
        return (1);
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.mlx_img, 0, 0);
    return (0);
}

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    else
    {
        // ft_printf("|%d|\n", keysym);
        if (keysym == NUM_PAD_7)
            data->rotation->x ++;
        else if (keysym == NUM_PAD_4)
            data->rotation->x --;
        else if (keysym == NUM_PAD_8)
            data->rotation->y ++;
        else if (keysym == NUM_PAD_5)
            data->rotation->y --;
        else if (keysym == NUM_PAD_9)
            data->rotation->z ++;
        else if (keysym == NUM_PAD_6)
            data->rotation->z --;
        else if (keysym == XK_Right)
            data->center->x += 10;
        else if (keysym == XK_Left)
            data->center->x -= 10;
        else if (keysym == XK_Up)
            data->center->y += 10;
        else if (keysym == XK_Down)
            data->center->y -= 10;
        else if (keysym == NUM_PAD_1)
            data->line_length --;
        else if (keysym == NUM_PAD_3)
            data->line_length ++;
        else if (keysym == NUM_PAD_2)
            data->height ++;
        else if (keysym == NUM_PAD_0)
            data->height --;
        draw_maps(data);
    }
    // else if (keysym == XK_Right)
    return (0);
}

int handle_exit(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    data->win_ptr = NULL;
    return (0);
}
