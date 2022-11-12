#include "fdf.h"

int	map_width(t_data *d, char **line)
{
	int		i;
	char	**res;

	res = ft_split(*line, 32);
	i = -1;
	while (res[++i])
		free(res[i]);
	free (res);
	if (d->map_h != 0 && d->map_w != i)
		return (1);
	d->map_w = i;
	return (0);
}

// ft_printf("read line %d successfully\n", d->map_h);
int	process_file(t_data *d, int fd)
{
	char	*l;

	while (42)
	{
		l = get_next_line (fd);
		if (!l)
			break ;
		if (map_width(d, &l))
		{
			free (l);
			print_err("Error: Invalid Map.", d);
		}
		d->buf = ft_strjoin(d->buf, l);
		d->map_h += 1;
		free (l);
	}
	return (0);
}

int	read_file(t_data *d, char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	process_file (d, fd);
	close(fd);
	if (d->map_h == 0)
		print_err("Error: Empty Map.", d);
	d->map = ft_split(d->buf, 32);
	init_var(d);
	return (0);
}
