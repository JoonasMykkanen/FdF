/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:40 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:11:42 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_image(t_fdf_data_set s)
{
	mlx_put_image_to_window(s.d.ptr, s.d.win, s.d.img_blk, 0, 0);
	blk_image(&s, s.d.img, s.i.img);
	s.p.c = 0;
	s.p.y = -1;
	s.p.x = -1;
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
}

// Will create ALL BLACK image
void	blk_image(t_fdf_data_set *s, void *image, int *data)
{
	int	x;
	int	y;
	int	end;
	int	p_bits;
	int	line_p;

	x = -1;
	y = -1;
	data = (int *)mlx_get_data_addr(image, &p_bits, &line_p, &end);
	line_p /= 4;
	while (++y < s->d.win_height)
	{
		while (++x < s->d.win_width)
		{
			data[(y * line_p) + x] = 0x000000;
		}
		x = -1;
	}
}

// Will draw pixel to actual window coordinates based on x, y input
void	draw_pixel(t_fdf_data_set *s, int x, int y)
{
	int	end;
	int	p_bits;
	int	line_p;

	if ((x < s->d.win_width && y < s->d.win_height) && (x > 0 && y > 0))
	{
		get_pixel_color(s);
		s->i.img = (int *)mlx_get_data_addr(s->d.img, &p_bits, &line_p, &end);
		line_p /= 4;
		s->i.img[(y * line_p) + x] = s->p.color;
	}
}
