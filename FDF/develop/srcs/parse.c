#include "fdf.h"

int init_map(t_data *d)
{
    int k;

    k = -1;
    d->map_3d = (t_cord **) malloc((d->map_w * d->map_h) * sizeof(t_cord *));
    d->map_2d = (t_cord **) malloc((d->map_w * d->map_h) * sizeof(t_cord *));
    ft_bzero(d->map_3d, sizeof(t_cord *));
    while (++k < (d->map_h * d->map_w))
    {
        d->map_3d[k] = (t_cord *) malloc(sizeof(t_cord));
        d->map_2d[k] = (t_cord *) malloc(sizeof(t_cord));
        ft_bzero(d->map_3d[k], sizeof(t_cord *));
        ft_bzero(d->map_2d[k], sizeof(t_cord *));
    }
    for (int y = 0; y < d->map_h; y++)
    {
        for (int x = 0; x < d->map_w; x++)
        {
            d->map_3d[xy_to_x(d, x, y)]->x = x * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->y = y * d->line_length;
            d->map_3d[xy_to_x(d, x, y)]->z = atoi(d->map[xy_to_x(d, x, y)]) * 5;
            d->map_2d[xy_to_x(d, x, y)]->x = 0;
            d->map_2d[xy_to_x(d, x, y)]->y = 0;
            d->map_2d[xy_to_x(d, x, y)]->z = 0;
        }
    }
    return (0);
}

int init_setup(t_data *d)
{
    d->u = (t_cord *) malloc(sizeof(t_cord));
    ft_bzero(d->u, sizeof(t_cord *));
    d->u->x = 1;
    d->u->y = 0;
    d->u->z = 0;
    d->v = (t_cord *) malloc(sizeof(t_cord));
    ft_bzero(d->v, sizeof(t_cord *));
    d->v->x = 0;
    d->v->y = 0;
    d->v->z = 1;
    d->rotation = (t_cord *) malloc(sizeof(t_cord));
    ft_bzero(d->rotation, sizeof(t_cord *));
    d->rotation->x = 13;
    d->rotation->y = 16;
    d->rotation->z = 3;
    return (0);
}

int init_var(t_data *d)
{
    // int max;

    d->line_length = 40;
    init_map(d);
    init_setup(d);
    // max = sqrt((d->map_w * d->map_w) + (d->map_h * d->map_h));
    // ft_printf("max: %d. \n", max / d->w);
    // d->line_length = 5;
    return (0);
}

int map_width(t_data *d, char **line)
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
    init_var(d);
    return (0);
}
