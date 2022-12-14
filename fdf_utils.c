
#include "fdf.h"

int	count_rows(char **arr)
{
	int count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count - 1);
}

int count_columns(char **arr)
{
	int	count;

	count = -1;
	while (arr[++count] != NULL)
		;
	return (count);
}

int convert_rgb(int r, int g, int b)
{
	int	hex;

	hex = (r<<16) | (g<<8) | b;
    return (hex);
}

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