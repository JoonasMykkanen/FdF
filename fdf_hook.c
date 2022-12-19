

#include "fdf.h"

static int handle_no_event(fdf_data_set *s)
{
	return (0);
}

static int	mouse_hook(int keycode, fdf_data_set *s)
{
	if (keycode == 4)
	{
		// s->d.mult += 0.1;
		ft_printf("up!\n");
	}
	if (keycode == 5)
	{
		// s->d.mult -= 0.1;
		ft_printf("down!\n");
	}
	return (0);
}

static int	key_hook(int keycode, fdf_data_set *s)
{
	if (keycode == 53)
		ft_close(s);
	else if (keycode == 126)
		ft_printf("up arrow pressed\n");
	else if (keycode == 125)
		ft_printf("down arrow pressed\n");
	else if (keycode == 124)
		ft_printf("right arrow pressed\n");
	else if (keycode == 123)
		ft_printf("left arrow pressed\n");
	else if (keycode == 24)
		ft_printf("plus pressed\n");
	else if (keycode == 27)
			ft_printf("minus pressed\n");
	return (0);
}

void	hook_engine(fdf_data_set *s)
{
	mlx_loop_hook(s->d.ptr, &handle_no_event, &s);
	mlx_key_hook(s->d.win, key_hook, &s);
	mlx_mouse_hook(s->d.win, mouse_hook, &s);
	mlx_loop(s->d.ptr);
}