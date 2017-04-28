/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 20:13:59 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/17 20:34:27 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pass_pts(t_data *coords)
{
	t_data	*tmp1;
	t_data	*tmp2;
	int		i;

	mlx_clear_window(coords->mlx, coords->wind);
	i = 0;
	tmp1 = coords;
	tmp2 = coords;
	while (i++ < coords->w)
		tmp2 = tmp2->next;
	while (tmp1 && tmp1->next != NULL)
	{
		if (i >= coords->w)
			i = 0;
		if (tmp2)
		{
			bres_line(coords->mlx, coords->wind, tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		i++;
		if (i != coords->w)
			bres_line(coords->mlx, coords->wind, tmp1, tmp1->next);
		tmp1 = tmp1->next;
	}
}

void		redraw(t_data *coords, int y_off, int x_off, float c)
{
	t_data	*tmp;

	tmp = coords;
	if (c == 0)
	{
		while (tmp)
		{
			tmp->y += y_off;
			tmp->x += x_off;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			tmp->y *= c;
			tmp->x *= c;
			tmp = tmp->next;
		}
	}
	pass_pts(coords);
}

int			keyboard(int keynum, t_data *coords)
{
	if (keynum == 53)
		exit(0);
	if (keynum == 123)
		redraw(coords, 0, -40, 0);
	if (keynum == 124)
		redraw(coords, 0, 40, 0);
	if (keynum == 125)
		redraw(coords, 40, 0, 0);
	if (keynum == 126)
		redraw(coords, -40, 0, 0);
	if (keynum == 49)
		show_perspective(coords, 'p');
	if (keynum == 36)
		show_perspective(coords, 'n');
	if (keynum == 24)
		redraw(coords, 0, 0, 1.25);
	if (keynum == 27)
		redraw(coords, 0, 0, 0.75);
	if (keynum == 86)
		rot_matrices(coords, 8, 'z');
	if (keynum == 84)
		rot_matrices(coords, -8, 'z');
	return (0);
}

int			begin(t_data *coords)
{
	pass_pts(coords);
	mlx_key_hook(coords->wind, keyboard, coords);
	mlx_loop(coords->mlx);
	return (0);
}
