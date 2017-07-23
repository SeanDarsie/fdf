/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:36:30 by sdarsie           #+#    #+#             */
/*   Updated: 2017/05/15 19:12:20 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		show_negative(t_data *coords)
{
	t_data		*tmp;

	tmp = coords;
	while (tmp)
	{
		if (tmp->z != 0)
		{
			tmp->x += (tmp->z * -1.2);
			tmp->y += (tmp->z * 3);
		}
		tmp = tmp->next;
	}
}

void			show_perspective(t_data *coords, char c)
{
	t_data		*tmp;

	tmp = coords;
	if (c == 'p')
	{
		while (tmp)
		{
			if (tmp->z != 0)
			{
				tmp->x += (tmp->z * 1.2);
				tmp->y += (tmp->z * -3);
			}
			tmp = tmp->next;
		}
	}
	else
		show_negative(coords);
	pass_pts(coords);
}
