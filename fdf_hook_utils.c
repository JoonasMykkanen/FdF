

#include "fdf.h"

void	adjust_z(fdf_data_set *s, char dir)
{
	if (dir == 'i')
	{
		s->d.z_offset -= 10;
	}
	else if (dir == 'd')
	{
		s->d.z_offset += 10;
	}
	update_image(*s);
}

void	zoom(fdf_data_set *s, char dir)
{
	if (dir == '+')
	{
		s->p.x_of += 10;
		s->p.y_of += 10;
	}
	else if (dir == '-')
	{
		s->p.x_of -= 10;
		s->p.y_of -= 10;
	}
	update_image(*s);
}

void	translate(fdf_data_set *s, char dir)
{
	if (dir == 'u')
	{
		s->p.y_t -= 10;
	}
	else if (dir == 'd')
	{
		s->p.y_t += 10;
	}
	else if (dir == 'r')
	{
		s->p.x_t += 10;
	}
	else if (dir == 'l')
	{
		s->p.x_t -= 10;
	}
	update_image(*s);
}

int	ft_close(void)
{
	exit(0);
}

int	handle_no_event(void)
{
	return (0);
}
