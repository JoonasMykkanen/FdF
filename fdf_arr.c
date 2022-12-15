
#include "fdf.h"

char	**build_arr(char **arr, char **argv)
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
	while (i < count)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		arr[i] = malloc(sizeof(char) * len + 1);
		ft_memcpy(arr[i], line, len);
		ft_printf("second: %s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (arr);
}
