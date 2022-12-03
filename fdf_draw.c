
#include "fdf.h"

static int	choose_color(pixel p, char **arr)
{
	int z;
	int color;

	z = arr[p.y][p.x];
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
	return (color);
}

static int	calc_z(char **arr, pixel p)
{
	int 	z;
	int 	len;
	char	**values;

	values = ft_split(arr[p.y], ' ');
	len = line_count(values);
	z = ft_atoi(values[p.count]);
	ft_printf("z is: %d\n", z);
	return (z);
}

void	graphic_engine(void *ptr, void *win, char **arr)
{
	pixel	p;
	int		z;
	int		color;
	
	p.x_max = ft_strlen(arr[0]);
	p.y_max = count_rows(arr);
	p.count = 0;
	p.x = -1;
	p.y = -1;
	while (++p.y < p.y_max)
	{
		while (++p.x < p.x_max)
		{
			color = choose_color(p, arr);
			p.color = color;
			if (arr[p.y][p.x] != ' ')
			{
				z = calc_z(arr, p);
				p.z = z;
				mlx_pixel_put(ptr, win, p.x, p.y, p.color);
				p.count++;
				while (arr[p.y][p.x] != ' ' && p.x < p.x_max)
					p.x++;
			}
		}
		p.x = -1;
		p.count = 0;
	}
	mlx_loop(ptr);
}