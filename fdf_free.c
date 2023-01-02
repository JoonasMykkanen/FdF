

#include "fdf.h"

void	ft_free(char **garbage)
{
	int	len;

	len = count_columns(garbage);
	while (len >= 0)
	{
		free(garbage[len]);
		len--;
	}
	free(garbage);
}

void	ft_cleanup(t_fdf_data_set s)
{
	ft_free(s.d.arr);
}