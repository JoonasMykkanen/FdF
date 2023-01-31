/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:12:06 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:12:11 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("increase z: 2\n");
	ft_printf("decrease z: 1\n");
}

static void	build_line(t_fdf_data_set *s, char *line)
{
	if (!line || line == NULL)
	{
		s->d.arr[s->d.map_i] = NULL;
	}
	else
	{
		s->d.arr[s->d.map_i] = malloc(sizeof(char) * s->d.map_len + 1);
		ft_memcpy(s->d.arr[s->d.map_i], line, s->d.map_len + 1);
	}
	s->d.map_i++;
}

static void	build_arr(t_fdf_data_set *s, char **argv)
{
	int		fd;
	int		count;
	char	*line;

	s->d.map_i = 0;
	count = line_count(argv);
	s->d.arr = malloc(sizeof(char *) * (count + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		s->d.map_status = -1;
		return ;
	}
	while (s->d.map_i < count)
	{
		line = get_next_line(fd);
		s->d.map_len = ft_strlen(line);
		build_line(s, line);
		free(line);
	}
	s->d.arr[s->d.map_i] = NULL;
	s->d.map_status = 1;
	close(fd);
}

int	main(int argc, char **argv)
{
	t_fdf_data_set	s;

	if (argc < 2 || argc > 2)
	{
		ft_printf("No map specified... Always assume user is an idiot!\n");
		return (0);
	}
	s.d.win_width = 1500;
	s.d.win_height = 900;
	welcome_message();
	build_arr(&s, argv);
	if (s.d.map_status == 1)
	{
		s.d.ptr = mlx_init();
		s.d.win = mlx_new_window(s.d.ptr, s.d.win_width, s.d.win_height, "");
		graphic_engine(s);
		ft_cleanup(s);
	}
	else
		ft_printf("Map error... Exit! \n");
	return (0);
}
