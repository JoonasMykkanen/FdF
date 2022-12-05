
#include "fdf.h"

static int	calc_pos(pixel p, char c)
{
	int	pos;

	if (c == 'x')
		pos =  p.count * p.offset;
	else
		pos = p.y * p.offset;
	return (pos);
}

static void	draw(void *ptr, void *win, pixel p)
{
	int	x_axis;
	int	y_axis;

	x_axis = calc_pos(p, 'x');
	y_axis = calc_pos(p, 'y');
	ft_printf("Printing X to %d,%d\n", x_axis, y_axis);
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
				choose_color(&p, arr);
				calc_z(arr, &p);
				draw(ptr, win, p);
				while (arr[p.y][p.x] != ' ' && p.x != '\0')
					p.x++;
				p.x += p.offset - 1;
				p.count++;
			}
		}
		mod_p(&p, 0);
	}
	mlx_loop(ptr);
}