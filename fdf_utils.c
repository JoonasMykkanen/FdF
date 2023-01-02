
#include "fdf.h"

void	find_top(t_fdf_data_set *s)
{
	int		i;
	int		l;
	int		max;
	int		temp;
	char	**row;

	i = -1;
	l = -1;
	max = 0;
	while (s->d.arr[++i] != NULL)
	{
		row = ft_split(s->d.arr[i], ' ');
		while (row[++l] != NULL)
		{
			temp = ft_atoi(row[l]);
			if (temp > max)
				max = temp;
		}
		free(row);
		l = -1;
	}
	s->d.z_max = max;
}

int	count_rows(char **arr)
{
	int count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count - 1);
}

int	count_columns(char **arr)
{
	int	count;

	count = -1;
	while (arr[++count] != NULL)
		;
	return (count);
}

int	line_count(char **argv)
{
	int		fd;
	int		count;
	char	*line;

	count = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}
