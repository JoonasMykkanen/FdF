

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
}				pixel;

int		count_rows(char **arr);
char	**build_map(char **arr);
int		line_count(char **argv);
int		convert_rgb(int r, int g, int b);
char	**build_arr(char **arr, char **argv);
void	graphic_engine(void *ptr, void *win, char **arr);