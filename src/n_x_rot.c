/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_x_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:27:10 by sdarsie           #+#    #+#             */
/*   Updated: 2017/05/16 17:44:22 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		n_x_rot(t_data *pts)
{
	t_data		*tmp;
	int			i;
	int			w;
	int			h2;
	int			scalar;

	tmp = pts;
	h2 = pts->h;
	while (h2 > 0)
	{
		i = 0;
		w = (pts->w / 2) * -1;
		scalar = 2 * w;
		while (i < pts->w && tmp)
		{
			tmp->x += scalar;
			i++;
			w++;
			scalar = 2 * w;
			tmp = tmp->next;
		}
		h2--;
	}
	pass_pts(pts);
}
