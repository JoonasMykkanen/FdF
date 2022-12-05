

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
	int	offset;
}				pixel;

int		count_rows(char **arr);
int		line_count(char **argv);
char	**build_map(char **arr);
void	mod_p(pixel *p, int mode);
void	calc_z(char **arr, pixel *p);
void	init_p(pixel *p, char **arr);
int		convert_rgb(int r, int g, int b);
void	choose_color(pixel *p, char **arr);
char	**build_arr(char **arr, char **argv);
void	graphic_engine(void *ptr, void *win, char **arr);