

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef	struct	s_pixel
{
	int	x;
	int y;
	int z;
	int	count;
	int	color;
	int x_max;
	int y_max;
	int	x_offset;
	int	y_offset;
}				pixel;

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

int		count_rows(char **arr);
int		line_count(char **argv);
void	flip(int *one, int *two);
void	mod_p(pixel *p, int mode);
int		count_columns(char **arr);
void	calc_z(char **arr, pixel *p);
void	init_p(pixel *p, char **arr);
int		convert_rgb(int r, int g, int b);
char	**build_arr(char **arr, char **argv);
void	init_line_args(line_args *l, pixel *p, char c);
void	graphic_engine(void *ptr, void *win, char **arr);
int		isometric_pos(pixel p, int n, char dir, char type);
void	draw_bresenhams_line(void *ptr, void *win, pixel p, char c);