

#include "fdf.h"

// Converts R G B values to one hex int value
int convert_rgb(int r, int g, int b)
{
	int	hex;

	hex = (r<<16) | (g<<8) | b;
    return (hex);
}

// Adding Z offset for Y coordinates
void	add_height(fdf_data_set *s)
{
	s->p.z = 0;
	if (s->p_1.z != 0)
	{
		s->p_1.y -= s->p_1.z - s->d.z_offset;
	}
	if (s->p_2.z != 0)
	{
		s->p_2.y -= s->p_2.z - s->d.z_offset;
	}
}

// modify values during loop in graphic_engine()
void	mod_p(pixel *p, int mode)
{
	if (mode == 0)
	{
		p->x = -1;
		p->count = 0;
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

// Starting values for pixel p. "p" is used in main loop in graphic_engine()
static void	init_p(fdf_data_set *s)
{
	s->p.x_max = count_columns(ft_split(s->d.arr[0], ' '));
	s->p.y_max = count_rows(s->d.arr);
	s->p.y_offset = 500 / s->p.y_max;
	s->p.x_offset = 500 / s->p.x_max;
	s->d.z_offset_og = s->d.z_offset;
	s->p.x_translate = 750;
	s->p.y_translate = 250;
	s->d.z_offset = 0;
	s->p.count = 0;
	s->p.x = -1;
	s->p.y = -1;
}

// Starting values for our draw functions, this will get called 
// every time a new point in arr is reached
void	init_graphics(fdf_data_set *s)
{
	init_p(s);
	find_top(s);
	s->d.img_blk = mlx_new_image(s->d.ptr, s->d.window_width, s->d.window_height);
	s->d.img = mlx_new_image(s->d.ptr, s->d.window_width, s->d.window_height);
	blk_image(s, s->d.img_blk, s->i.blk, -1, -1);
	blk_image(s, s->d.img, s->i.img, -1, -1);
	mlx_put_image_to_window(s->d.ptr, s->d.win, s->d.img_blk, 0, 0);
}