
#include "fdf.h"

// Access arr to get x+1 and y+1 Z values
static void	get_next_points(fdf_data_set *s, char dir)
{
	char	**x_values;
	char	**y_values;

	if (s->p.count < s->p.x_max - 1 && s->p.y < s->p.y_max - 1)
	{
		x_values = ft_split(s->d.arr[s->p.y], ' ');
		y_values = ft_split(s->d.arr[s->p.y], ' ');
		if (dir == 'r')
		{
			s->p_1.z = ft_atoi(x_values[s->p.count]);
			s->p_2.z = ft_atoi(x_values[s->p.count + 1]);
		}
		if (dir == 'd')
		{
			s->p_1.z =  ft_atoi(y_values[s->p.count]);
			free(y_values);
			y_values = ft_split(s->d.arr[s->p.y + 1], ' ');
			s->p_2.z = ft_atoi(y_values[s->p.count]);
		}
		free(x_values);
		free(y_values);
	}
}

// Translate picture from 2D to 3D using in isometric view functions
// get_next_points() gets Z value from points + 1 to right and down
// draw_line goes from current position to next position using bresenham's algorithm
void	draw(fdf_data_set s)
{
	s.p_1.x = (s.p.count * s.p.x_offset) - (s.p.y * s.p.y_offset) + s.p.x_translate;
	s.p_1.y = (((s.p.count * s.p.x_offset) + (s.p.y * s.p.y_offset)) / 2) + s.p.y_translate;
	if (s.p.count < s.p.x_max - 1)
	{
		get_next_points(&s, 'r');
		s.p_2.x = ((s.p.count + 1) * s.p.x_offset) - (s.p.y * s.p.y_offset) + s.p.x_translate;
		s.p_2.y = ((((s.p.count + 1) * s.p.x_offset) + (s.p.y * s.p.y_offset)) / 2) + s.p.y_translate;
		draw_line(s);
	}
	if (s.p.y < s.p.y_max - 1)
	{
		get_next_points(&s, 'd');
		s.p_2.x = (s.p.count * s.p.x_offset) - ((s.p.y + 1) * s.p.y_offset) + s.p.x_translate;
		s.p_2.y = (((s.p.count * s.p.x_offset) + ((s.p.y + 1) * s.p.y_offset)) / 2) + s.p.y_translate;
		draw_line(s);
	}
}

// Goes through arr and translates map size to actual pixels.
void	graphic_engine(fdf_data_set s)
{	
	init_graphics(&s);
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
	hook_engine(&s);
}