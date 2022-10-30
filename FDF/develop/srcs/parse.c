#include "fdf.h"

int init_var(t_data *d)
{
    int k;
    int max;

    k = -1;
    d->map_draw = (t_cord **) malloc((d->map_w * d->map_h) * sizeof(t_cord *));
    ft_bzero(d->map_draw, sizeof(t_cord *));
    while (++k < (d->map_h * d->map_w))
    {
        d->map_draw[k] = (t_cord *) malloc(sizeof(t_cord));
        ft_bzero(d->map_draw[k], sizeof(t_cord *));
    }
    max = sqrt((d->map_w * d->map_w) + (d->map_h * d->map_h));
    ft_printf("max: %d. \n", max / d->w);
    // d->line_length = 5;
    d->line_length = 10;
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
