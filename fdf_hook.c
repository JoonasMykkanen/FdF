

#include "fdf.h"

static int	mouse_hook(int keycode, fdf_data_set *s)
{
	if (keycode == 4)
	{
		ft_printf("inside mous hook\n");
	}
	else if (keycode == 5)
	{
		ft_printf("inside mous hook\n");
	}
	return (0);
}

static int	key_hook(int keycode, fdf_data_set *s)
{
	if (keycode == 53)
		ft_close(s);
	else if (keycode == 126)
		translate(s, 'u');
	else if (keycode == 125)
		translate(s, 'd');
	else if (keycode == 124)
		translate(s, 'r');
	else if (keycode == 123)
		translate(s, 'l');
	else if (keycode == 24)
		zoom(s, '+');
	else if (keycode == 27)
		zoom(s, '-');
	return (0);
}

void	hook_engine(fdf_data_set *s)
{
	ft_printf("at hook engine: %d\n", s->d.z_offset);
	mlx_loop_hook(s->d.ptr, &handle_no_event, s);
	// mlx_mouse_hook(s->d.win, &mouse_hook, s);
	// mlx_hook(s->d.win, 4, 0, &mouse_hook, s);
	mlx_key_hook(s->d.win, &key_hook, s);
	mlx_loop(s->d.ptr);
}