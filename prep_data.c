/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:21:25 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/17 20:36:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_data(t_data *coords, double x, double y, int z)
{
	t_data	*new;

	new = (t_data*)malloc(sizeof(t_data));
	while (coords->next != NULL)
		coords = coords->next;
	new->x = x;
	new->y = y;
	new->z = z;
	new->cx = 700;
	new->cy = 500;
	new->next = NULL;
	coords->next = new;
}

int			get_w_and_h(char ***s, int flag)
{
	int		i;

	i = 0;
	if (flag == 0)
	{
		while (s[0][i] != NULL)
		{
			i++;
		}
		return (i);
	}
	else
	{
		while (s[i][0][0] != '\0')
			i++;
		return (i);
	}
	return (0);
}

t_line		prep_vars(int w, int h)
{
	t_line	nums;

	nums.i = 0;
	nums.k = 0;
	nums.offy = (300 / h);
	nums.offx = (600 / w);
	nums.x1 = 400;
	nums.y1 = 400;
	return (nums);
}

t_data		*store_coords(char ***get, int w, int h)
{
	t_line	d;
	t_data	*coords;
	t_data	*tmp;

	d = prep_vars(w, h);
	coords = malloc(sizeof(t_data));
	coords->next = NULL;
	tmp = coords;
	while (d.i < h)
	{
		d.x = (d.x1 - (d.offx * d.i));
		d.y = (d.y1 + (d.offy * d.i));
		d.k = 0;
		while (d.k < w)
		{
			fill_data(tmp, d.x, d.y, ft_atoi(get[d.i][d.k]));
			tmp = tmp->next;
			d.x += d.offx;
			d.y += d.offy;
			d.k++;
		}
		d.i++;
	}
	return (coords);
}

t_data		*prep_data(char ***data, void *mlx, void *wind)
{
	int		w;
	int		h;
	t_data	*coord;
	t_data	*tmp;

	w = get_w_and_h(data, 0);
	h = get_w_and_h(data, 1);
	coord = store_coords(data, w, h);
	coord = coord->next;
	tmp = coord;
	while (tmp)
	{
		tmp->mlx = mlx;
		tmp->h = h;
		tmp->w = w;
		tmp->wind = wind;
		tmp = tmp->next;
	}
	return (coord);
}
