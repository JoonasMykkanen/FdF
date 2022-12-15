

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

int		count_rows(char **arr);
int		line_count(char **argv);
void	mod_p(pixel *p, int mode);
int		count_columns(char **arr);
void	calc_z(char **arr, pixel *p);
void	init_p(pixel *p, char **arr);
int		convert_rgb(int r, int g, int b);
void	choose_color(pixel *p, char **arr);
char	**build_arr(char **arr, char **argv);
void	graphic_engine(void *ptr, void *win, char **arr);