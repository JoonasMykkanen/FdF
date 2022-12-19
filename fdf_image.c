
#include "fdf.h"

// Will create ALL BLACK image
void	blk_image(fdf_data_set *s, void *image, int *data, int x, int y)
{
	int endian;
	int pixel_bits;
	int line_pixels;

	data = (int *)malloc(sizeof(int *));
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

	s->i.img = (int *)mlx_get_data_addr(s->d.img, &pixel_bits, &line_pixels, &endian);
	line_pixels /= 4;
	s->i.img[(y * line_pixels) + x] = 0xffffff;
}