/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:09:44 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:09:51 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	char	**arr;
	int		z_max;
	void	*img_blk;
	int		z_offset;
	int		win_width;
	int		win_height;
	int		z_offset_og;
}				t_data;
typedef struct s_point_1
{
	int	x;
	int	y;
	int	z;
}				t_point_1;

typedef struct s_point_2
{
	int	x;
	int	y;
	int	z;
}				t_point_2;

typedef struct s_line_args
{
	float	m;
	int		x;
	int		y;
	int		run;
	int		rise;
	int		delta;
	int		offset;
	int		adjust;
	float	sin_mult;
	float	cos_mult;
	float	threshold;
	int		threshold_inc;
}				t_line_args;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	c;
	int	z_x;
	int	z_y;
	int	x_t;
	int	y_t;
	int	x_of;
	int	y_of;
	int	y_max;
	int	color;
	int	x_max;
}				t_pixel;

typedef struct s_image
{
	int	*blk;
	int	*img;
}				t_image;

typedef struct s_fdf
{
	t_data			d;
	t_point_1		p_1;
	t_point_2		p_2;
	t_line_args		l;
	t_pixel			p;
	t_image			i;
}				t_fdf_data_set;

int		ft_close(void);
int		count_rows(char **arr);
void	draw(t_fdf_data_set s);
int		line_count(char **argv);
void	ft_free(char **garbage);
void	flip(int *one, int *two);
int		count_columns(char **arr);
void	find_top(t_fdf_data_set *s);
void	draw_line(t_fdf_data_set s);
void	mod_p(t_pixel *p, int mode);
void	ft_cleanup(t_fdf_data_set s);
void	add_height(t_fdf_data_set *s);
void	update_image(t_fdf_data_set s);
void	hook_engine(t_fdf_data_set *s);
void	init_graphics(t_fdf_data_set *s);
void	graphic_engine(t_fdf_data_set s);
void	zoom(t_fdf_data_set *s, char dir);
void	get_pixel_color(t_fdf_data_set *s);
void 	rotate(t_fdf_data_set *s, char dir);
void	adjust_z(t_fdf_data_set *s, char dir);
void	translate(t_fdf_data_set *s, char dir);
void	draw_pixel(t_fdf_data_set *s, int x, int y);
void	blk_image(t_fdf_data_set *s, void *image, int *data);

#endif
