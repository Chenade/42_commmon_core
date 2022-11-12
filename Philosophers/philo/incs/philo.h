#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define COLOR_BLACK 0x0000000
# define COLOR_RED 0x00FF0000
# define COLOR_WHITE 0x00FFFFFF
# define COLOR_TEXT 0xEAEAEA

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_data
{
	void		*win_ptr;
	void		*mlx_ptr;
	t_img		img;
	char		*buf;
	int			size;
	t_vector	*u;
	t_vector	*v;
	int			w;
	int			h;

	int			map_h;
	int			map_w;
	char		**map;
	t_vector	**map_3d;
	t_vector	**map_2d;
	int			line_length;
	int			height;
	int			height2;
	t_vector	*center;
	t_vector	*rotation;
	int			projection;
}	t_data;

#endif
