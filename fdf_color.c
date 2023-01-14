/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:10:02 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:10:06 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	convert_rgb(int r, int g, int b)
{
	int	hex;

	hex = (r << 16) | (g << 8) | b;
	return (hex);
}

static void	red_gradient(t_fdf_data_set *s)
{
	int	alpha;

	if (s->p_1.z != 0 && s->p_2.z != 0)
		s->p.color = convert_rgb(255, 0, 0);
	else if (s->p_1.z != 0 || s->p_2.z != 0)
	{
		if (s->p_1.z < s->p_2.z)
		{
			alpha = (s->p.z * 255 / (s->p_2.y - s->p_1.y));
			s->p.color = convert_rgb(255, (255 - alpha), (255 - alpha));
		}
		else
		{
			alpha = (s->p.z * 255 / (s->p_2.y - s->p_1.y));
			if (alpha < 0)
			{
				alpha = alpha * -1;
				s->p.color = convert_rgb(255, (255 - alpha), (255 - alpha));
			}
			else
				s->p.color = convert_rgb(255, alpha, alpha);
		}
	}
	else
		s->p.color = 0xffffff;
}

static void	blue_gradient(t_fdf_data_set *s)
{
	int	alpha;

	if (s->p_1.z != 0 && s->p_2.z != 0)
		s->p.color = convert_rgb(0, 0, 255);
	else if (s->p_1.z != 0 || s->p_2.z != 0)
	{
		if (s->p_1.z < s->p_2.z)
		{
			alpha = (s->p.z * 255 / (s->p_2.y - s->p_1.y));
			s->p.color = convert_rgb((255 - alpha), (255 - alpha), 255);
		}
		else
		{
			alpha = (s->p.z * 255 / (s->p_2.y - s->p_1.y));
			if (alpha < 0)
			{
				alpha = alpha * -1;
				s->p.color = convert_rgb((255 - alpha), (255 - alpha), 255);
			}
			else
				s->p.color = convert_rgb(alpha, alpha, 255);
		}
	}
	else
		s->p.color = 0xffffff;
}

void	get_pixel_color(t_fdf_data_set *s)
{
	if (s->p_2.y - s->p_1.y == 0)
	{
		s->p_2.y++;
	}
	if (s->d.z_offset_og - s->d.z_offset + s->d.z_max == 0)
	{
		s->p.color = 0xffffff;
	}
	else if (s->d.z_offset > s->d.z_offset_og)
	{
		blue_gradient(s);
	}
	else
	{
		red_gradient(s);
	}
}
