#include "fdf.h"

int	key_trigger(t_data *d, int keysym)
{
	if (keysym == XK_q)
		d->rotation->x ++;
	else if (keysym == XK_a)
		d->rotation->x --;
	else if (keysym == XK_w)
		d->rotation->y ++;
	else if (keysym == XK_s)
		d->rotation->y --;
	else if (keysym == XK_e)
		d->rotation->z ++;
	else if (keysym == XK_d)
		d->rotation->z --;
	else if (keysym == XK_r)
		d->height ++;
	else if (keysym == XK_f)
		d->height --;
	if (keysym == XK_q || keysym == XK_a || keysym == XK_w
		|| keysym == XK_s || keysym == XK_e || keysym == XK_d
		|| keysym == XK_r || keysym == XK_f)
		return (1);
	return (0);
}

int	key_trigger_move(t_data *d, int keysym)
{
	if (keysym == XK_Right)
		d->center->x += 10;
	else if (keysym == XK_Left)
		d->center->x -= 10;
	else if (keysym == XK_Up)
		d->center->y += 10;
	else if (keysym == XK_Down)
		d->center->y -= 10;
	else if (keysym == XK_j)
		d->line_length --;
	else if (keysym == XK_k)
		d->line_length ++;
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up
		|| keysym == XK_Down || keysym == XK_j || keysym == XK_k)
		return (1);
	return (0);
}

int	key_trigger_projection(t_data *d, int keysym)
{
	if (keysym == XK_p)
	{
		d->projection *= -1;
		ft_swap(&d->height, &d->height2);
		if (d->projection > 0)
		{
			d->line_length = (WIDTH / d->map_w) * 0.5;
			init_vector(d->rotation, 21, 16, -3);
			init_vector(d->center, 150, 0, 0);
		}
		else
			d->line_length = (WIDTH / d->map_w) * 0.4;
		return (1);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
		d->win_ptr = NULL;
	}
	else
	{
		if (d->projection > 0)
		{
			if (key_trigger(d, keysym))
				draw_imgs(d);
			else if (key_trigger_move(d, keysym))
				draw_imgs(d);
		}
		if (key_trigger_projection(d, keysym))
			draw_imgs(d);
	}
	return (0);
}
