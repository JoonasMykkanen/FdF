

#include "fdf.h"

void	choose_color(pixel *p, char **arr)
{
	int color;

	if (p->z <= 0)
		color = convert_rgb(255, 255, 255);
	else
		color = convert_rgb(255, 0, 0);
	p->color = color;
}

void	calc_z(char **arr, pixel *p)
{
	int 	z;
	char	**values;

	values = ft_split(arr[p->y], ' ');
	z = ft_atoi(values[p->count]);
	p->z = z;
	free(values);
}

void	init_p(pixel *p, char **arr)
{
	p->x_max = count_columns(ft_split(arr[0], ' '));
	p->y_max = count_rows(arr);
	p->y_offset = 700 / p->y_max;
	p->x_offset = 700 / p->x_max;
	p->count = 0;
	p->x = -1;
	p->y = -1;
}

void	mod_p(pixel *p, int mode)
{
	if (mode == 0)
	{
		p->x = -1;
		p->count = 0;
	}
}