
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
	
}

static void	draw(void *ptr, void *win, pixel p, char **arr)
{
	int i;
	int	x_axis;
	int	y_axis;

	i = -1;
	x_axis = calc_pos(p, 'x') + 150;
	y_axis = calc_pos(p, 'y') + 150;
	mlx_string_put(ptr, win, x_axis, y_axis, p.color, "X");
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
				calc_z(arr, &p);
				choose_color(&p, arr);
				draw(ptr, win, p, arr);
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