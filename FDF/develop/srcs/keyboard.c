#include "fdf.h"
#include "keyboard.h"

int	key_trigger(t_data *d, int keysym)
{
	if (keysym == NUM_PAD_7)
		d->rotation->x ++;
	else if (keysym == NUM_PAD_4)
		d->rotation->x --;
	else if (keysym == NUM_PAD_8)
		d->rotation->y ++;
	else if (keysym == NUM_PAD_5)
		d->rotation->y --;
	else if (keysym == NUM_PAD_9)
		d->rotation->z ++;
	else if (keysym == NUM_PAD_6)
		d->rotation->z --;
	else if (keysym == NUM_PAD_2)
		d->height ++;
	else if (keysym == NUM_PAD_0)
		d->height --;
	if (keysym == NUM_PAD_7 || keysym == NUM_PAD_4 || keysym == NUM_PAD_8
		|| keysym == NUM_PAD_5 || keysym == NUM_PAD_9 || keysym == NUM_PAD_6
		|| keysym == NUM_PAD_2 || keysym == NUM_PAD_0)
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
	else if (keysym == NUM_PAD_1)
		d->line_length --;
	else if (keysym == NUM_PAD_3)
		d->line_length ++;
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up
		|| keysym == XK_Down || keysym == NUM_PAD_1 || keysym == NUM_PAD_3)
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
			d->line_length = (WIDTH / d->map_w) * 0.7;
			init_vector(d->rotation, 21, 16, -3);
			init_vector(d->center, 200, 0, 0);
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
