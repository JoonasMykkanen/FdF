
#include "fdf.h"

void	draw_bresenhams_line(void *ptr, void *win, pixel p, line_args l)
{

	// if (p.z == 0)
	// 	mlx_string_put(ptr, win, l.x_1, l.y_1, 0xffffff, "X");
	// else
	// 	mlx_string_put(ptr, win, l.x_1, l.y_1 + p.z, 0xff0000, "X");

	ft_printf("x1: %d, y1: %d\n", l.x_1, l.y_1);
	ft_printf("x2: %d, y2: %d\n", l.x_2, l.y_2);

	if (l.run == 0)
	{
		if (l.y_2 < l.y_1)
			flip(&l.y_2, &l.y_1);
		l.y = l.y_1 - 1;
		while (++l.y <= l.y_2)
		{
			mlx_pixel_put(ptr, win, l.x, l.y, 0xffffff);
		}
	}
	else
	{
		l.m = (float)l.rise / l.run;
		if (l.m >= 0)
			l.adjust = 1;
		else
			l.adjust = -1;
		l.offset = 0;
		if (l.m <= 1 && l.m >= -1)
		{
			l.delta = abs(l.rise) * 2;
			l.threshold = abs(l.run);
			l.threshold_inc = abs(l.run) * 2;
			l.y = l.y_1;
			if (l.x_2 < l.x_1)
			{
				flip(&l.x_2, &l.x_1);
				l.y = l.y_2;
			}
			l.x = l.x_1;
			while (l.x <= l.x_2)
			{
				mlx_pixel_put(ptr, win, l.x, l.y, 0xffffff);
				l.offset += l.delta;
				if (l.offset >= l.threshold)
				{
					l.y += l.adjust;
					l.threshold += l.threshold_inc;
				}
				l.x++;
			}
		}
		else
		{
			l.delta = abs(l.run)  * 2;
			l.threshold = abs(l.rise);
			l.threshold_inc = abs(l.rise) * 2;
			l.y = l.y_1;
			if (l.y_2 < l.y_1)
			{
				flip(&l.y_2, &l.y_1);
				l.x = l.x_2;	
			}
			while (l.y <= l.y_2)
			{
				mlx_pixel_put(ptr, win, l.x, l.y, 0xffffff);
				l.offset += l.delta;
				if (l.offset >= l.threshold)
				{
					l.x += l.adjust;
					l.threshold += l.threshold_inc;
				}
				l.y++;
			}
		}
	}
}