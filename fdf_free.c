/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:25 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:11:29 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("Exit!\n");
}
