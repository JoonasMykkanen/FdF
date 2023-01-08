/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:10:45 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:10:53 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_height(t_fdf_data_set *s)
{
	s->p.z = 0;
	if (s->p_1.z != 0)
	{
		s->p_1.y -= ((s->p_1.z * s->d.z_offset) / 3) * -1;
	}
	if (s->p_2.z != 0)
	{
		s->p_2.y -= ((s->p_2.z * s->d.z_offset) / 3) * -1;
	}
}

void	mod_p(t_pixel *p, int mode)
{
	if (mode == 0)
	{
		p->x = -1;
		p->c = 0;
	}
}

// Flip two integers
void	flip(int *one, int *two)
{
	int	temp;

	temp = *two;
	*two = *one;
	*one = temp;
}

static void	init_p(t_fdf_data_set *s)
{
	char	**count;

	count = ft_split(s->d.arr[0], ' ');
	s->p.x_max = count_columns(count);
	ft_free(count);
	s->p.y_max = count_rows(s->d.arr);
	s->p.y_of = (s->d.win_height * 0.6) / s->p.y_max;
	s->p.x_of = (s->d.win_width * 0.6) / s->p.x_max;
	s->d.z_offset = s->p.y_of * -1;
	s->d.z_offset_og = s->d.z_max;
	s->p.x_t = 600;
	s->p.y_t = 100;
	s->p.c = 0;
	s->p.x = -1;
	s->p.y = -1;
}

void	init_graphics(t_fdf_data_set *s)
{
	init_p(s);
	find_top(s);
	s->d.img_blk = mlx_new_image(s->d.ptr, s->d.win_width, s->d.win_height);
	s->d.img = mlx_new_image(s->d.ptr, s->d.win_width, s->d.win_height);
	blk_image(s, s->d.img_blk, s->i.blk);
	blk_image(s, s->d.img, s->i.img);
	mlx_put_image_to_window(s->d.ptr, s->d.win, s->d.img_blk, 0, 0);
}
