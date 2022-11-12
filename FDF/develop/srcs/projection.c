#include "fdf.h"

void	projection_isometric(t_data *d)
{
	free_cord_map(d);
	init_map(d);
	draw_maps(d);
}

void	projection_first_angel(t_data *d)
{
	free_cord_map(d);
	init_map(d);
	init_vector(d->rotation, 0, 0, 0);
	init_vector(d->center, 400, -300, 0);
	draw_maps(d);
	free_cord_map(d);
	init_map(d);
	init_vector(d->rotation, 11, 0, 0);
	init_vector(d->center, 400, 200, 0);
	draw_maps(d);
	free_cord_map(d);
	init_map(d);
	init_vector(d->rotation, 11, 0, 11);
	init_vector(d->center, -200, 200, 0);
	draw_maps(d);
}
