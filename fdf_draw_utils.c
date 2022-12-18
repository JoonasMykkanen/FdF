

#include "fdf.h"

void	mod_p(pixel *p, int mode)
{
	if (mode == 0)
	{
		p->x = -1;
		p->count = 0;
	}
}

void	flip(int *one, int *two)
{
	int	temp;

	temp = *two;
	*two = *one;
	*one = temp;
}

void	init_p(fdf_data_set *s)
{
	s->p.x_max = count_columns(ft_split(s->d.arr[0], ' '));
	s->p.y_max = count_rows(s->d.arr);
	s->p.x_translate = 750;
	s->p.y_translate = 250;
	s->p.y_offset = 500 / s->p.y_max;
	s->p.x_offset = 500 / s->p.x_max;
	s->p.count = 0;
	s->p.x = -1;
	s->p.y = -1;
}