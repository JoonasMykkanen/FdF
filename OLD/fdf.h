

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	s_fdf
{
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
	}				p_1;
	
	typedef struct	s_point_2
	{
		int	x;
		int	y;
		int	z;
	}				p_2;

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
}				pixel;
}				fdf;


int		count_rows(char **arr);
int		line_count(char **argv);
void	flip(int *one, int *two);
void	mod_p(pixel *p, int mode);
int		count_columns(char **arr);
void	calc_z(char **arr, pixel *p);
void	init_p(pixel *p, char **arr);
int		convert_rgb(int r, int g, int b);
void	get_next_args(pixel *p, char **arr);
char	**build_arr(char **arr, char **argv);
void	graphic_engine(void *ptr, void *win, char **arr);
int		isometric_pos(pixel p, char dir, int n, char type);
void	init_line_args(line_args *l, pixel *p, char c);
void	draw_bresenhams_line(void *ptr, void *win, pixel p, line_args l);