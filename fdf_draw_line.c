

#include "fdf.h"

static void	vertical_line(fdf_data_set s)
{
	s.l.x = s.p_1.x;
	if (s.p_2.y < s.p_1.y)
		flip(&s.p_2.y, &s.p_1.y);
	s.l.y = s.p_1.y - 1;
	while (++s.l.y <= s.p_2.y)
	{
		s.p.z++;
		draw_pixel(&s, s.l.x, s.l.y);
	}
}

static void	rise_over_run(fdf_data_set s)
{
	s.l.delta = abs(s.l.rise) * 2;
	s.l.threshold = abs(s.l.run);
	s.l.threshold_inc = abs(s.l.run) * 2;
	s.l.y = s.p_1.y;
	if (s.p_2.x < s.p_1.x)
	{
		flip(&s.p_2.x, &s.p_1.x);
		s.l.y = s.p_2.y;
	}
	s.l.x = s.p_1.x;
	while (s.l.x <= s.p_2.x)
	{
		draw_pixel(&s, s.l.x, s.l.y);
		s.l.offset += s.l.delta;
		if (s.l.offset >= s.l.threshold)
		{
			s.p.z += s.l.adjust;
			s.l.y += s.l.adjust;
			s.l.threshold += s.l.threshold_inc;
		}
		s.l.x++;
	}
}

static void	run_over_rise(fdf_data_set s)
{
	s.l.delta = abs(s.l.run)  * 2;
	s.l.threshold = abs(s.l.rise);
	s.l.threshold_inc = abs(s.l.rise) * 2;
	s.l.x = s.p_1.x;
	s.l.y = s.p_1.y;
	if (s.p_2.y < s.p_1.y)
	{
		flip(&s.p_2.y, &s.p_1.y);
		s.l.x = s.p_2.x;
	}
	while (s.l.y <= s.p_2.y)
	{
		draw_pixel(&s, s.l.x, s.l.y);
		s.l.offset += s.l.delta;
		if (s.l.offset >= s.l.threshold)
		{
			s.l.x += s.l.adjust;
			s.l.threshold += s.l.threshold_inc;
		}
		s.p.z++;
		s.l.y++;
	}
}

void	draw_line(fdf_data_set s)
{
	add_height(&s);
	s.l.rise = s.p_2.y - s.p_1.y;
	s.l.run = s.p_2.x - s.p_1.x;
	if (s.l.run == 0)
		vertical_line(s);
	else
	{
		s.l.m = (float)s.l.rise / s.l.run;
		if (s.l.m >= 0)
			s.l.adjust = 1;
		else
			s.l.adjust = -1;
		s.l.offset = 0;
		if (s.l.m <= 1 && s.l.m >= -1)
			rise_over_run(s);
		else
			run_over_rise(s);
	}
}
