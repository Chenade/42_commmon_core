#include "fdf.h"

int init_mlx(t_data *d, char *name)
{
    d->size = print_info(name);
    d->buf = (char *)malloc(d->size);
    bzero(d->buf, d->size);

    d->w = WIDTH;
    d->h = HEIGHT;

    {
        d->mlx_ptr = mlx_init();
        d->win_ptr = mlx_new_window(d->mlx_ptr, d->w, d->h, "retromfa");
        if (!d->win_ptr)
            print_err("Failed to launch window.", d);
        d->img.mlx_img = mlx_new_image(d->mlx_ptr, d->w, d->h);
        if (!d->img.mlx_img)
            print_err("mlx new image error", d);
        d->img.addr = mlx_get_data_addr(d->img.mlx_img, &d->img.bpp,
                                       &d->img.line_len, &d->img.endian);
    }
    d->curr_img.p = d->buf;
    return (0);
}

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    // else if (keysym == XK_Right)
    //     data->w++;
    // else if (keysym == XK_Left)
    //     data->w--;
    else if (keysym == XK_Up)
    {
        // data->h++;
        data->h_off += 10;
        bzero(data->img.addr, data->img.line_len * HEIGHT);
        draw_all_img(data);
    }
    else if (keysym == XK_Down)
    {
        // data->h--;
        data->h_off -= 10;
        bzero(data->img.addr, data->img.line_len * HEIGHT);
        draw_all_img(data);
    }
    // else if (keysym == XK_a)
    // {
    //     data->byte_off--;
    // }
    // else if (keysym == XK_d)
    // {
    //     data->byte_off++;
    // }
    // else if (keysym == XK_p)
    // {
    //     if (!getNextImg(data))
    //         return (mlx_loop_end(data->mlx_ptr));
    // }
    return (0);
}

int handle_exit(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    data->win_ptr = NULL;
    return (0);
}
