
#include "fdf.h"

static int	calc_pos(pixel p, char c)
{
	int	pos;

	if (c == 'x')
		pos =  p.count * p.x_offset;
	else
		pos = p.y * p.y_offset;
	return (pos);
}

static void	lines(void *ptr, void *win, pixel p)
{
	int i;
	int x;
	int y;

	i = -1;
	x = p.x;
	y = p.y;

}

static void	draw(void *ptr, void *win, pixel p)
{
	int i;
	int	x_axis;
	int	y_axis;

	i = -1;
	x_axis = calc_pos(p, 'x') + 150;
	y_axis = calc_pos(p, 'y') + 150;
	while (++i < p.x_offset)
	{
		if (p.count < p.x_max - 1)
			mlx_pixel_put(ptr, win, x_axis++, y_axis, p.color);
	}
	if (p.count != p.x_max - 1)
		x_axis -= p.x_offset;
	i = -1;
	while (++i < p.y_offset)
	{
		if (p.y < p.y_max - 1)
			mlx_pixel_put(ptr, win, x_axis, y_axis++, p.color);	
	}
}

void	graphic_engine(void *ptr, void *win, char **arr)
{
	pixel	p;
	
	init_p(&p, arr);
	while (++p.y < p.y_max)
	{
		while (p.count < p.x_max)
		{
			if (arr[p.y][++p.x] != ' ')
			{
				choose_color(&p, arr);
				calc_z(arr, &p);
				draw(ptr, win, p);
				while (arr[p.y][p.x] != ' ' && p.x != '\0')
					p.x++;
				p.x += p.x_offset - 1;
				p.count++;
			}
		}
		mod_p(&p, 0);
	}
	mlx_loop(ptr);
}