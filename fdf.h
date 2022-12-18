

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	s_data
	{
		void	*ptr;
		void	*win;
		char	**arr;
		char	**map;
	}				data;
	typedef struct	s_point_1
	{
		int	x;
		int y;
		int z;
	}				point_1;
	
	typedef struct	s_point_2
	{
		int	x;
		int	y;
		int	z;
	}				point_2;

	typedef struct	s_line_args
	{
		int		x;
		int 	y;
		int 	x_1;
		int		x_2;
		int 	y_1;
		int 	y_2;
		int 	d_x;
		int 	d_y;
		int		run;
		int 	rise;
		float 	m;
		int 	adjust;
		int 	delta;
		float	threshold;
		int		threshold_inc;
		int 	offset;
	}				line_args;

	typedef	struct	s_pixel
	{
		int	x;
		int y;
		int z;
		int	z_x;
		int z_y;
		int	count;
		int	color;
		int x_max;
		int y_max;
		int	x_offset;
		int	y_offset;
		int	x_translate;
		int y_translate;
	}				pixel;
typedef struct	s_fdf
{
	data		d;
	point_1		p_1;
	point_2		p_2;
	line_args	l;
	pixel		p;
}				fdf_data_set;

int		count_rows(char **arr);
void	init_p(fdf_data_set *s);
int		line_count(char **argv);
void	flip(int *one, int *two);
void	mod_p(pixel *p, int mode);
void	draw_line(fdf_data_set s);
int 	count_columns(char **arr);
void	graphic_engine(fdf_data_set s);