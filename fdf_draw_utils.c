

#include "fdf.h"

void	mod_p(pixel *p, int mode)
{
	if (mode == 0)
	{
		p->x = -1;
		p->count = 0;
	}
}

void	flip(int *one, int *two)
{
	int	temp;

	temp = *two;
	*two = *one;
	*one = temp;
}

static void	init_p(fdf_data_set *s)
{
	s->p.x_max = count_columns(ft_split(s->d.arr[0], ' '));
	s->p.y_max = count_rows(s->d.arr);
	s->p.x_translate = 750;
	s->p.y_translate = 250;
	s->p.y_offset = 500 / s->p.y_max;
	s->p.x_offset = 500 / s->p.x_max;
	s->p.count = 0;
	s->p.x = -1;
	s->p.y = -1;
}

void	init_graphics(fdf_data_set *s)
{
	init_p(s);
	s->d.img_blk = mlx_new_image(s->d.ptr, s->d.window_width, s->d.window_height);
	s->d.img = mlx_new_image(s->d.ptr, s->d.window_width, s->d.window_height);
	blk_image(s, s->d.img_blk, s->i.blk, -1, -1);
	blk_image(s, s->d.img, s->i.img, -1, -1);
	mlx_put_image_to_window(s->d.ptr, s->d.win, s->d.img_blk, 0, 0);
}