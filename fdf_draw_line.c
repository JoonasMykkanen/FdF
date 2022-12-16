
#include "fdf.h"

void	draw_line(fdf_data_set s)
{
	// if (s.p.z == 0)
	// 	mlx_string_put(s.d.ptr, s.d.win, s.l.x_1, s.l.y_1, 0xffffff, "X");
	// else
	// 	mlx_string_put(s.d.ptr, s.d.win, s.l.x_1, s.l.y_1 + s.p.z, 0xff0000, "X");

	if (s.l.run == 0)
	{
		if (s.l.y_2 < s.l.y_1)
			flip(&s.l.y_2, &s.l.y_1);
		s.l.y = s.l.y_1 - 1;
		while (++s.l.y <= s.l.y_2)
		{
			mlx_pixel_put(s.d.ptr, s.d.win, s.l.x, s.l.y, 0xffffff);
		}
	}
	else
	{
		s.l.m = (float)s.l.rise / s.l.run;
		if (s.l.m >= 0)
			s.l.adjust = 1;
		else
			s.l.adjust = -1;
		s.l.offset = 0;
		if (s.l.m <= 1 && s.l.m >= -1)
		{
			s.l.delta = abs(s.l.rise) * 2;
			s.l.threshold = abs(s.l.run);
			s.l.threshold_inc = abs(s.l.run) * 2;
			s.l.y = s.l.y_1;
			if (s.l.x_2 < s.l.x_1)
			{
				flip(&s.l.x_2, &s.l.x_1);
				s.l.y = s.l.y_2;
			}
			s.l.x = s.l.x_1;
			while (s.l.x <= s.l.x_2)
			{
				mlx_pixel_put(s.d.ptr, s.d.win, s.l.x, s.l.y, 0xffffff);
				s.l.offset += s.l.delta;
				if (s.l.offset >= s.l.threshold)
				{
					s.l.y += s.l.adjust;
					s.l.threshold += s.l.threshold_inc;
				}
				s.l.x++;
			}
		}
		else
		{
			s.l.delta = abs(s.l.run)  * 2;
			s.l.threshold = abs(s.l.rise);
			s.l.threshold_inc = abs(s.l.rise) * 2;
			s.l.y = s.l.y_1;
			if (s.l.y_2 < s.l.y_1)
			{
				flip(&s.l.y_2, &s.l.y_1);
				s.l.x = s.l.x_2;	
			}
			while (s.l.y <= s.l.y_2)
			{
				mlx_pixel_put(s.d.ptr, s.d.win, s.l.x, s.l.y, 0xffffff);
				s.l.offset += s.l.delta;
				if (s.l.offset >= s.l.threshold)
				{
					s.l.x += s.l.adjust;
					s.l.threshold += s.l.threshold_inc;
				}
				s.l.y++;
			}
		}
	}
}