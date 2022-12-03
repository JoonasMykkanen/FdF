
#include "fdf.h"

int	line_count(char **argv)
{
	int		fd;
	int		count;
	char	*line;

	count = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	free(line);
	while(line)
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**build_map(char **arr, char **argv)
{
	int		i;
	int		fd;
	int		len;
	int		count;
	char	*line;

	i = 0;
	count = line_count(argv);
	arr = malloc(sizeof(char *) * (count + 1));
	fd = open(argv[1], O_RDONLY);
	while (i < count && line!= NULL)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		arr[i] = malloc(sizeof(char) * len + 1);
		ft_memcpy(arr[i], line, len);
		free(line);
		i++;
	}
	close(fd);
	return (arr);
}