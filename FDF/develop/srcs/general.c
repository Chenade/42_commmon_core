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
        free(d->map[i]);
    free(d->map);
    free(d->images);
}

void print_err(const char *err_msg, t_data *d)
{
    ft_printf("%s\n", err_msg);
    free_data(d);
    exit(EXIT_FAILURE);
}

int check_filename(const char *name)
{

    int x = ft_strlen(name) - 3;
    if (ft_strncmp(name + x, "fdf", 3))
        return (0);
    return (1);
}

int    *map_width(t_data *d, char **line)
{
    int     i;
    char    **res;

    res = ft_split(*line, 32);
    i = -1;
    d->map_w = 0;
    while (res[++i])
    {
        d->map_w += 1;
        free(res[i]);
    }
    free (res);
    return (0);
}

int read_file(t_data *d, char *name)
{
    int fd;
    int x;
    char    *l;

    fd = open(name, O_RDONLY);
    while (42)
    {
        l = get_next_line (fd);
        if (!l)
            break ;
        x = -1;
        while(l[++x])
            if (l[x] == 10)
                l[x] = 32;
        map_width(d, &l);
        d->buf = ft_strjoin(d->buf, l);
        free (l);
        d->map_h += 1;
    }
    d->map = ft_split(d->buf, 32);
    close(fd);
    return (0);
}

   