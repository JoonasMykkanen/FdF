/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:25 by jmykkane          #+#    #+#             */
/*   Updated: 2023/01/02 11:11:29 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_z(t_fdf_data_set *s, char dir)
{
	if (dir == 'i')
	{
		s->d.z_offset -= 10;
	}
	else if (dir == 'd')
	{
		s->d.z_offset += 10;
	}
	update_image(*s);
}

void	zoom(t_fdf_data_set *s, char dir)
{
	if (dir == '+')
	{
		s->p.x_of += 10;
		s->p.y_of += 10;
	}
	else if (dir == '-')
	{
		s->p.x_of -= 10;
		s->p.y_of -= 10;
	}
	update_image(*s);
}

void	translate(t_fdf_data_set *s, char dir)
{
	if (dir == 'u')
	{
		s->p.y_t -= s->d.win_height / 10;
	}
	else if (dir == 'd')
	{
		s->p.y_t += s->d.win_height / 10;
	}
	else if (dir == 'r')
	{
		s->p.x_t += s->d.win_width / 10;
	}
	else if (dir == 'l')
	{
		s->p.x_t -= s->d.win_width / 10;
	}
	update_image(*s);
}

int	ft_close(void)
{
	exit(0);
}

int	handle_no_event(void)
{
	return (0);
}
