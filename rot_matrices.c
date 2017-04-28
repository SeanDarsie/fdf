/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:21:52 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/17 20:50:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RAD (M_PI / 180)

void		mult_redraw(t_data *coords, t_mat m, int deg)
{
	t_data	*tmp;

	tmp = coords;
	while (tmp)
	{
		tmp->x = (m.x0 * tmp->x) + (m.y0 * tmp->y);
		tmp->y = (m.x1 * tmp->x) + (m.y1 * tmp->y);
		tmp = tmp->next;
	}
	pass_pts(coords);
}

t_mat		x_rot(t_mat matrix, int deg)
{
	matrix.x0 = 1;
	matrix.x1 = 0;
	matrix.x2 = 0;
	matrix.y0 = 0;
	matrix.y1 = cos(RAD * deg);
	matrix.y2 = sin(RAD * deg);
	matrix.z0 = 0;
	matrix.z1 = -sin(RAD * deg);
	matrix.z2 = cos(RAD * deg);
	return (matrix);
}

t_mat		y_rot(t_mat matrix, int deg)
{
	matrix.x0 = cos(RAD * deg);
	matrix.x1 = 0;
	matrix.x2 = -sin(RAD * deg);
	matrix.y0 = 0;
	matrix.y1 = 1;
	matrix.y2 = 0;
	matrix.z0 = sin(RAD * deg);
	matrix.z1 = 0;
	matrix.z2 = cos(RAD * deg);
	return (matrix);
}

void		z_rot(t_data *pts, int deg)
{
	t_data	*tmp;

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

void		rot_matrices(t_data *coords, int deg, char dir)
{
	t_mat		matrix;

	if (dir == 'x')
	{
		matrix = x_rot(matrix, deg);
		mult_redraw(coords, matrix, deg);
	}
	if (dir == 'y')
	{
		matrix = y_rot(matrix, deg);
		mult_redraw(coords, matrix, deg);
	}
	if (dir == 'z')
		z_rot(coords, deg);
}
