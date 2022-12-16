
#include "fdf.h"

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
		free(y_values);
		y_values = ft_split(s->d.arr[s->p.y + 1], ' ');
		if (dir == 'd')
		{
			s->p_1.z =  ft_atoi(y_values[s->p.count]);
			s->p_2.z = ft_atoi(y_values[s->p.count]);
		}
		free(x_values);
		free(y_values);
	}
}

static void	draw(fdf_data_set s)
{
	int	x_offset;
	int	y_offset;

	x_offset = 750;
	y_offset = 250;
	// Draw line right
	if (s.p.count < s.p.x_max)
	{
		get_next_points(&s, 'r');
		s.p_1.x = (s.p.count * s.p.x_offset) - (s.p.y * s.p.y_offset) + x_offset;
		s.p_1.y = ((s.p.count * s.p.x_offset) + (s.p.y * s.p.y_offset)) / 2 + y_offset;
		s.p_2.x =  ((s.p.count + 1) * s.p.x_offset) - (s.p.y * s.p.y_offset) + x_offset;
		s.p_2.y = ((s.p.count * s.p.x_offset) + (s.p.y + 1 * s.p.y_offset)) / 2 + y_offset;
		mlx_string_put(s.d.ptr, s.d.win, s.p_1.x, s.p_1.y, 0xffffff, "x");
		// draw_line(s);
	}
	// Draw line down
	if (s.p.y < s.p.y_max)
	{
		get_next_points(&s, 'd');
		s.p_1.x = (s.p.count * s.p.x_offset) - (s.p.y * s.p.y_offset) + x_offset;
		s.p_1.y = ((s.p.count * s.p.x_offset) + (s.p.y * s.p.y_offset)) / 2 + y_offset;
		s.p_2.x = ((s.p.count + 1) * s.p.x_offset) - (s.p.y * s.p.y_offset) + x_offset;
		s.p_2.y = ((s.p.count * s.p.x_offset) + (s.p.y + 1 * s.p.y_offset)) / 2 + y_offset;
		mlx_string_put(s.d.ptr, s.d.win, s.p_1.x, s.p_1.y, 0xffffff, "x");
		// draw_line(s);
	}
}

void	graphic_engine(fdf_data_set s)
{	
	init_p(&s);
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
	mlx_loop(s.d.ptr);
}