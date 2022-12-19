

#include "fdf.h"

void	zoom(fdf_data_set *s, char dir)
{
	if (dir == '+')
	{
		s->p.x_offset += 10;
		s->p.y_offset += 10;
	}
	else if (dir == '-')
	{
		s->p.x_offset -= 10;
		s->p.y_offset -= 10;
	}
	update_image(*s);
}

void	translate(fdf_data_set *s, char dir)
{
	if (dir == 'u')
	{
		s->p.y_translate -= 10;
	}
	else if (dir == 'd')
	{
		s->p.y_translate += 10;
	}
	else if (dir == 'r')
	{
		s->p.x_translate += 10;
	}
	else if (dir == 'l')
	{
		s->p.x_translate -= 10;
	}
	update_image(*s);
}

void	ft_close(fdf_data_set *s)
{
	exit(0);
}

int handle_no_event(fdf_data_set *s)
{
	return (0);
}