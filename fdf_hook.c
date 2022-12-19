

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
	ft_printf("at hook engine: %d\n", s->d.z_offset);
	mlx_loop_hook(s->d.ptr, &handle_no_event, s);
	// mlx_mouse_hook(s->d.win, &mouse_hook, s);
	// mlx_hook(s->d.win, 4, 0, &mouse_hook, s);
	mlx_key_hook(s->d.win, &key_hook, s);
	mlx_loop(s->d.ptr);
}