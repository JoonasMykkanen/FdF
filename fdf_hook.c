/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:10 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:11:15 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_no_event(void)
{
	return (0);
}

static int	key_hook(int keycode, t_fdf_data_set *s)
{
	if (keycode == 53)
		ft_close();
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
	else if (keycode == 19)
		adjust_z(s, 'i');
	else if (keycode == 18)
		adjust_z(s, 'd');
	else if (keycode == 13)
		rotate(s, 'w');
	else if (keycode == 1)
		rotate(s, 's');
	return (0);
}

void	hook_engine(t_fdf_data_set *s)
{
	mlx_loop_hook(s->d.ptr, &handle_no_event, s);
	mlx_hook(s->d.win, 17, 0, ft_close, s);
	mlx_key_hook(s->d.win, &key_hook, s);
	mlx_loop(s->d.ptr);
}
