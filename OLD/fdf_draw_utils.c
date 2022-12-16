

#include "fdf.h"

void	get_next_args(pixel *p, char **arr)
{
	char	**values;

	values = ft_split(arr[p->y], ' ');
	ft_printf("z: %s\n", (values[p->count + 1]));
	ft_printf("Checkpoint1 \n");
	p->z_x = ft_atoi(values[p->count + 1]);
	ft_printf("Checkpoint2 \n");
	free(values);
	ft_printf("Checkpoint3 \n");
	values = ft_split(arr[p->y + 1], ' ');
	ft_printf("Checkpoint4 \n");
	p->z_y =  ft_atoi(values[p->count]);
	ft_printf("Checkpoint5 \n");
	free(values);
	ft_printf("Checkpoint6 \n");
}

void	init_line_args(line_args *l, pixel *p, char c)
{
	l->x_1 = 100;
	l->y_1 = 100;
	l->x_2 = 100;
	l->y_2 = 100;
	l->rise = l->y_2 - l->y_1;
	l->run = l->x_2 - l->x_1;
}

void	calc_z(char **arr, pixel *p)
{
	int 	z;
	int 	color;
	char	**values;

	values = ft_split(arr[p->y], ' ');
	z = ft_atoi(values[p->count]);
	p->z = (z * p->y_offset) * 0.25;
	free(values);
	if (p->z <= 0)
		color = convert_rgb(255, 255, 255);
	else
		color = convert_rgb(255, 0, 0);
	p->color = color;
}

void	init_p(pixel *p, char **arr)
{
	p->x_max = count_columns(ft_split(arr[0], ' '));
	p->y_max = count_rows(arr);
	p->y_offset = 500 / p->y_max;
	p->x_offset = 500 / p->x_max;
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

void	flip(int *one, int *two)
{
	int	temp;

	temp = *two;
	*two = *one;
	*one = temp;
}