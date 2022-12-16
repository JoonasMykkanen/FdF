
#include "fdf.h"

static void	draw(void *ptr, void *win, pixel p, char **arr)
{
	// draw to right
	if (p.count < p.x_max)
		draw_bresenhams_line(ptr, win, p, 'r');
	// draw to down
	if (p.y < p.y_max)
		draw_bresenhams_line(ptr, win, p, 'd');
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