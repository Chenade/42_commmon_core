#include "philo.h"

// int	fdf(char *filename)
// {
// 	t_data	d;

// 	ft_bzero(&d, sizeof(d));
// 	init_mlx(&d, filename);
// 	ft_printf("mlx init successfully\n");
// 	if (read_file(&d, filename))
// 		return (1);
// 	ft_printf("map height: %d, map width: %d\n", d.map_h, d.map_w);
// 	draw_imgs(&d);
// 	mlx_loop_hook(d.mlx_ptr, render_frame, &d);
// 	mlx_hook(d.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &d);
// 	mlx_hook(d.win_ptr, ClientMessage, StructureNotifyMask, &handle_exit, &d);
// 	mlx_loop(d.mlx_ptr);
// 	free_data(&d);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	// int	fd;
	// int	status;

	// fd = open(argv[1], O_RDONLY);
	// status = 1;
	if (argc != 2)
		printf("Error: Usage: ./fdf {filename}.fdf\n");
	// else if (fd < 0 || read(fd, 0, 0))
	// 	ft_printf("Error: Cannot open file.\n");
	// else
	// 	status = fdf(argv[1]);
	// close (fd);
	printf("Error: Cannot open file.\n");
	return (0);
}