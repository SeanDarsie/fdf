/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:21:22 by sdarsie           #+#    #+#             */
/*   Updated: 2017/05/16 17:44:46 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define RAD (M_PI / 180)

static void		x_rot(t_data *pts)
{
	t_data		*tmp;
	int			i;
	int			w;
	int			h2;
	int			scalar;

	tmp = pts;
	h2 = pts->h;
	while (h2 >= 0)
	{
		i = 0;
		w = (pts->w / 2);
		scalar = 2 * w;
		while (i < pts->w && tmp)
		{
			tmp->x += scalar;
			i++;
			w--;
			scalar = 2 * w;
			tmp = tmp->next;
		}
		h2--;
	}
	pass_pts(pts);
}

static void		n_y_rot(t_data *pts)
{
	t_data		*tmp;
	int			i;
	int			h;
	int			h2;
	int			scalar;

	tmp = pts;
	h2 = pts->h;
	h = (pts->h / 2) * -1;
	scalar = 2 * h;
	while (h2 > 0)
	{
		i = 0;
		while (i < pts->w && tmp)
		{
			tmp->y += scalar;
			i++;
			tmp = tmp->next;
		}
		h++;
		h2--;
		scalar = 2 * h;
	}
	pass_pts(pts);
}

static void		y_rot(t_data *pts)
{
	t_data		*tmp;
	int			i;
	int			h;
	int			h2;
	int			scalar;

	tmp = pts;
	h2 = pts->h;
	h = pts->h / 2;
	scalar = 2 * h;
	while (h2 > 0)
	{
		i = 0;
		while (i < pts->w && tmp)
		{
			tmp->y += scalar;
			i++;
			tmp = tmp->next;
		}
		h--;
		h2--;
		scalar = 2 * h;
	}
	pass_pts(pts);
}

static void		z_rot(t_data *pts, int deg)
{
	t_data		*tmp;

	tmp = pts;
	while (tmp)
	{
		tmp->y = tmp->cy + (((tmp->x - tmp->cx) * sin(RAD * deg))
				+ ((tmp->y - tmp->cy) * cos(RAD * deg))) * 1.008;
		tmp->x = tmp->cx + (((tmp->x - tmp->cx) * cos(RAD * deg))
				- ((tmp->y - tmp->cy) * sin(RAD * deg))) * 1.008;
		tmp = tmp->next;
	}
	tmp = pts;
	pass_pts(pts);
}

void			rot_matrices(t_data *coords, int deg, char dir)
{
	if (dir == 'n')
		n_y_rot(coords);
	if (dir == 'y')
		y_rot(coords);
	if (dir == 'z')
		z_rot(coords, deg);
	if (dir == 'x')
		x_rot(coords);
	if (dir == 'l')
		n_x_rot(coords);
}
