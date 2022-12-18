

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	char	**arr;
	char	**map;
	void	*img_blk;
	int		window_width;
	int		window_height;
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
	float 	m;
	int		run;
	int 	rise;
	int 	delta;
	int 	offset;
	int 	adjust;
	float	threshold;
	int		threshold_inc;
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

typedef struct	s_image
{
	int endian;
	int pixel_bits;
	int line_pixels;
	int	*blk;
	int	*img;
}				image;
typedef struct	s_fdf
{
	data		d;
	point_1		p_1;
	point_2		p_2;
	line_args	l;
	pixel		p;
	image		i;

}				fdf_data_set;

int		count_rows(char **arr);
int		line_count(char **argv);
void	flip(int *one, int *two);
void	mod_p(pixel *p, int mode);
void	draw_line(fdf_data_set s);
int 	count_columns(char **arr);
void	init_graphics(fdf_data_set *s);
void	graphic_engine(fdf_data_set s);
void	draw_pixel(fdf_data_set *s, int x, int y);
void	blk_image(fdf_data_set *s, void *image, int *data, int x, int y);
