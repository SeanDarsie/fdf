/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 20:13:59 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/23 15:30:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void				pass_pts(t_data *coords)
{
	t_data			*tmp1;
	t_data			*tmp2;
	int				i;

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

static void			redraw(t_data *coords, int y_off, int x_off, float c)
{
	t_data			*tmp;

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

static int			key2(int keynum, t_data *coords)
{
	if (keynum == 24)
		redraw(coords, 0, 0, 3);
	if (keynum == 27)
		redraw(coords, 0, 0, 0.75);
	if (keynum == 86)
		rot_matrices(coords, 8, 'z');
	if (keynum == 84)
		rot_matrices(coords, -8, 'z');
	if (keynum == 88)
		rot_matrices(coords, -2, 'y');
	if (keynum == 91)
		rot_matrices(coords, 2, 'n');
	if (keynum == 89)
		rot_matrices(coords, 2, 'x');
	if (keynum == 92)
		rot_matrices(coords, 2, 'l');
	return (0);
}

static int			keyboard(int keynum, t_data *coords)
{
	if (keynum == 53)
		exit(0);
	if (keynum == 123)
		redraw(coords, 0, -80, 0);
	if (keynum == 124)
		redraw(coords, 0, 80, 0);
	if (keynum == 125)
		redraw(coords, 80, 0, 0);
	if (keynum == 126)
		redraw(coords, -80, 0, 0);
	if (keynum == 49)
		show_perspective(coords, 'p');
	if (keynum == 36)
		show_perspective(coords, 'n');
	key2(keynum, coords);
	return (0);
}

int					begin(t_data *coords)
{
	show_perspective(coords, 'p');
	pass_pts(coords);
	mlx_hook(coords->wind, 2, 3, keyboard, coords);
	mlx_loop(coords->mlx);
	return (0);
}
