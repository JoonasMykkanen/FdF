

#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef	struct	s_point
{
	int	x;
	int y;
	int z;
}				point;

typedef struct	s_color
{
	int	r;
	int	g;
	int b;
}				color;

int		line_count(char **argv);
char	**build_map(char **arr, char **argv);