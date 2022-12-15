

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*ptr;
	void	*win;
	char	**arr;
	char	**map;

	if (argc < 2 || argc > 2)
	{
		ft_printf("No map specified... Always assume user is an idiot!\n");
		return (0);
	}
	arr = NULL;
	arr = build_arr(arr, argv);
	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 1000, "FdF - jmykkane");
	graphic_engine(ptr, win, arr);
	return (0);
}
