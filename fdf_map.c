

#include "fdf.h"

static char	*create_row(char **list)
{
	char	*row;

	
	return (row);
}

char	**generate_map(char **arr)
{
	int		i;
	int		len;
	char	**map;
	char	*line;

	i = -1;
	len = line_count(arr);
	map = malloc(sizeof(char *) * len);
	if (!map)
		return (NULL);
	while (arr[++i] != NULL)
	{
		len = ft_strlen(arr[i]);
		map[i] = malloc(sizeof(char) * len);
		map[i] = create_row(ft_split(arr[i], ' '));
	}
	return (map);
}
