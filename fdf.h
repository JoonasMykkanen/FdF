

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	char	**arr;
	int		z_max;
	void	*img_blk;
	int		z_offset;
	int		z_offset_og;
	int		win_width;
	int		win_height;
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
	int z;
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
	int	c;
	int	z_x;
	int z_y;
	int	color;
	int x_max;
	int y_max;
	int	x_of;
	int	y_of;
	int	x_t;
	int y_t;
}				pixel;

typedef struct	s_image
{
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

void	draw(fdf_data_set s);
int		count_rows(char **arr);
int		line_count(char **argv);
void	flip(int *one, int *two);
void	mod_p(pixel *p, int mode);
void	find_top(fdf_data_set *s);
void	ft_close(fdf_data_set *s);
void	draw_line(fdf_data_set s);
int 	count_columns(char **arr);
void	add_height(fdf_data_set *s);
void	update_image(fdf_data_set s);
void	hook_engine(fdf_data_set *s);
void	init_graphics(fdf_data_set *s);
void	graphic_engine(fdf_data_set s);
void	zoom(fdf_data_set *s, char dir);
void	get_pixel_color(fdf_data_set *s);
int 	handle_no_event(fdf_data_set *s);
void	adjust_z(fdf_data_set *s, char dir);
void	translate(fdf_data_set *s, char dir);
void	draw_pixel(fdf_data_set *s, int x, int y);
void	blk_image(fdf_data_set *s, void *image, int *data);