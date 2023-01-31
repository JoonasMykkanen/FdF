/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:10:20 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:10:23 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_next_points(t_fdf_data_set *s, char dir)
{
	char	**x_values;
	char	**y_values;

	if (dir == 'r')
	{
		if (s->p.c < s->p.x_max - 1)
		{
			x_values = ft_split(s->d.arr[s->p.y], ' ');
			s->p_1.z = ft_atoi(x_values[s->p.c]);
			s->p_2.z = ft_atoi(x_values[s->p.c + 1]);
			ft_free(x_values);
		}
	}
	if (dir == 'd')
	{
		if (s->p.y < s->p.y_max - 1)
		{
			y_values = ft_split(s->d.arr[s->p.y], ' ');
			s->p_1.z = ft_atoi(y_values[s->p.c]);
			ft_free(y_values);
			y_values = ft_split(s->d.arr[s->p.y + 1], ' ');
			s->p_2.z = ft_atoi(y_values[s->p.c]);
			ft_free(y_values);
		}
	}
}

void	draw(t_fdf_data_set s)
{
	s.p_1.x = (s.p.c * s.p.x_of) - (s.p.y * s.p.y_of) + s.p.x_t;
	s.p_1.y = (((s.p.c * s.p.x_of) + (s.p.y * s.p.y_of)) / 2) + s.p.y_t;
	if (s.p.c < s.p.x_max - 1)
	{
		get_next_points(&s, 'r');
		s.p_2.x = ((s.p.c + 1) * s.p.x_of) - (s.p.y * s.p.y_of) + s.p.x_t;
		s.p_2.y = ((((s.p.c + 1) * s.p.x_of) + (s.p.y * s.p.y_of)) / 2);
		s.p_2.y += s.p.y_t;
		draw_line(s);
	}
	if (s.p.y < s.p.y_max - 1)
	{
		get_next_points(&s, 'd');
		s.p_2.x = (s.p.c * s.p.x_of) - ((s.p.y + 1) * s.p.y_of) + s.p.x_t;
		s.p_2.y = (((s.p.c * s.p.x_of) + ((s.p.y + 1) * s.p.y_of)) / 2);
		s.p_2.y += s.p.y_t;
		draw_line(s);
	}
}

void	graphic_engine(t_fdf_data_set s)
{	
	init_graphics(&s);
	while (++s.p.y < s.p.y_max)
	{
		while (s.p.c < s.p.x_max)
		{
			if (s.d.arr[s.p.y][++s.p.x] != ' ')
			{
				draw(s);
				while (s.d.arr[s.p.y][s.p.x] != ' ' && s.p.x != '\0')
					s.p.x++;
				s.p.x += s.p.x_of - 1;
				s.p.c++;
			}
		}
		mod_p(&s.p, 0);
	}
	mlx_put_image_to_window(s.d.ptr, s.d.win, s.d.img, 0, 0);
	hook_engine(&s);
}
