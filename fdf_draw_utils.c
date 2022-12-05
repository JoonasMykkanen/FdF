

#include "fdf.h"

void	choose_color(pixel *p, char **arr)
{
	int z;
	int color;

	z = arr[p->y][p->x];
	if (z < 0)
	{
		color = convert_rgb(50, 50, 255);
	}
	else if (z > 0 && z < 10)
	{
		color = convert_rgb(230, 230, 230);
	}
	else
	{
		color = convert_rgb(255, 50, 50);
	}
	p->color = color;
}

void	calc_z(char **arr, pixel *p)
{
	int 	z;
	int 	len;
	char	**values;

	values = ft_split(arr[p->y], ' ');
	len = count_rows(values);
	ft_printf("len: %d\n", len);
	z = ft_atoi(values[p->count]);
	p->z = z;
	p->offset = 1000 / len;
	ft_printf("offset: %d\n", p->offset);
}

void	init_p(pixel *p, char **arr)
{
	p->x_max = sizeof(ft_split(arr[0], ' '));
	p->y_max = count_rows(arr);
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