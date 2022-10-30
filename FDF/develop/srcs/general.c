#include "fdf.h"

void free_data(t_data *d)
{
    int i;

    if (d->win_ptr)
        mlx_destroy_window(d->mlx_ptr, d->win_ptr);
    if (d->img.mlx_img)
        mlx_destroy_image(d->mlx_ptr, d->img.mlx_img);
    mlx_destroy_display(d->mlx_ptr);
    free(d->mlx_ptr);
    free(d->buf);
    i = -1;
    while(d->map[++i])
    {
        free(d->map[i]);
        free(d->map_draw[i]);
    }
    free(d->map);
    free(d->map_draw);
}

void print_err(const char *err_msg, t_data *d)
{
    ft_printf("%s\n", err_msg);
    free_data(d);
    exit(EXIT_FAILURE);
}

int check_filename(const char *name, const char *ext)
{

    int x = ft_strlen(name) - 3;
    if (ft_strncmp(name + x, ext, 3))
        return (0);
    return (1);
}
