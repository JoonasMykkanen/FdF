

#include "fdf.h"

int	main(int argc, char **argv)
{
	// void	*ptr;
	// void	*win;
	char	**arr;

	if (argc < 2)
	{
		ft_printf("No map specified... Always assume user is an idiot!\n");
		return (0);
	}
	arr = build_map(arr, argv);
	// ptr = mlx_init();
	// win = mlx_new_window(ptr, 1920, 1080, "FdF - jmykkane");
	// mlx_loop(ptr);
	return (0);
}
