

#include "fdf.h"

static void	welcome_message(void)
{
	ft_printf("Welcome to FdF\n");
	ft_printf("\n");
	ft_printf("Controls are as follows:\n");
	ft_printf("quit: esc\n");
	ft_printf("move right: right arrow\n");
	ft_printf("move left: left arrow\n");
	ft_printf("move up: up arrow\n");
	ft_printf("move down: down arrow\n");
	ft_printf("zoom in: +\n");
	ft_printf("zoom out: -\n");
	ft_printf("increase z: z\n");
	ft_printf("decrease z: x\n");
}

// Builds main dataset from our input file
static void	build_arr(fdf_data_set *s, char **argv)
{
	int		i;
	int		fd;
	int		len;
	int		count;
	char	*line;

	i = 0;
	count = line_count(argv);
	s->d.arr = malloc(sizeof(char *) * (count + 1));
	fd = open(argv[1], O_RDONLY);
	while (i < count)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		s->d.arr[i] = malloc(sizeof(char) * len + 1);
		ft_memcpy(s->d.arr[i], line, len);
		free(line);
		i++;
	}
	close(fd);
}

// This is main loop, obviously... Why did you ask?
int	main(int argc, char **argv)
{
	fdf_data_set	s;

	if (argc < 2 || argc > 2)
	{
		ft_printf("No map specified... Always assume user is an idiot!\n");
		return (0);
	}
	s.d.window_width = 1500;
	s.d.window_height = 900;
	welcome_message();
	build_arr(&s, argv);
	if (s.d.arr)
	{
		s.d.ptr = mlx_init();
		s.d.win = mlx_new_window(s.d.ptr, s.d.window_width, s.d.window_height, "FdF - jmykkane");
		graphic_engine(s);
	}
	return (0);
}
