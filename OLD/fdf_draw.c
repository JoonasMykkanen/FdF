
#include "fdf.h"

static void	draw_point(void *ptr, void *win, pixel p, char **arr)
{
	line_args	l;

	calc_z(arr, &p);
	if (p.count < p.x_max - 1 && p.y < p.y_max - 1)
		get_next_args(&p, arr);
	if (p.count < p.x_max - 1)
	{
		init_line_args(&l, &p, 'r');
		draw_bresenhams_line(ptr, win, p, l);
	}
	if (p.y < p.y_max)
	{
		init_line_args(&l, &p, 'd');
		draw_bresenhams_line(ptr, win, p, l);
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
				draw_point(ptr, win, p, arr);
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