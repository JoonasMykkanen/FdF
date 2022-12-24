
#include "fdf.h"

void	update_image(fdf_data_set s)
{
	mlx_put_image_to_window(s.d.ptr, s.d.win, s.d.img_blk, 0, 0);
	blk_image(&s, s.d.img, s.i.img, -1, -1);
	s.p.count = 0;
	s.p.y = -1;
	s.p.x = -1;
	while (++s.p.y < s.p.y_max)
	{
		while (s.p.count < s.p.x_max)
		{
			if (s.d.arr[s.p.y][++s.p.x] != ' ')
			{
				draw(s);
				while (s.d.arr[s.p.y][s.p.x] != ' ' && s.p.x != '\0')
					s.p.x++;
				s.p.x += s.p.x_offset - 1;
				s.p.count++;
			}
		}
		mod_p(&s.p, 0);
	}
	mlx_put_image_to_window(s.d.ptr, s.d.win, s.d.img, 0, 0);
}

// Will create ALL BLACK image
void	blk_image(fdf_data_set *s, void *image, int *data, int x, int y)
{
	int endian;
	int pixel_bits;
	int line_pixels;

	data = (int *)mlx_get_data_addr(image, &pixel_bits, &line_pixels, &endian);
	line_pixels /= 4;
	while (++y < s->d.window_height)
	{
		while (++x < s->d.window_width)
		{
			data[(y * line_pixels) + x] = 0x000000;
		}
		x = -1;
	}
}

// Will draw pixel to actual window coordinates based on x, y input
void	draw_pixel(fdf_data_set *s, int x, int y)
{
	int endian;
	int pixel_bits;
	int line_pixels;

	if ((x < s->d.window_width && y < s->d.window_height) && (x > 0 && y > 0))
	{
		get_pixel_color(s);
		s->i.img = (int *)mlx_get_data_addr(s->d.img, &pixel_bits, &line_pixels, &endian);
		line_pixels /= 4;
		s->i.img[(y * line_pixels) + x] = s->p.color;
	}
}