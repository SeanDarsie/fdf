/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:18:49 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/17 20:29:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_negative_y(void *mlx, void *wind, t_data *p1, t_data *p2)
{
	VARS;
	m = (p2->x - p1->x) / (p2->y - p1->y);
	e = m + 1.0;
	x = p1->x;
	y = p1->y;
	if (p1->y < p2->y)
		draw_negative_y(mlx, wind, p2, p1);
	while (y >= p2->y)
	{
		mlx_pixel_put(mlx, wind, x, y, 0x000000FF);
		y--;
		e += m;
		if (e <= 0)
		{
			x++;
			e++;
		}
	}
}

void	draw_negative_x(void *mlx, void *wind, t_data *p1, t_data *p2)
{
	VARS;
	m = (p2->y - p1->y) / (p2->x - p1->x);
	e = m + 1;
	x = p1->x;
	y = p1->y;
	if (p1->x < p2->x)
		draw_negative_x(mlx, wind, p2, p1);
	while (x >= p2->x)
	{
		mlx_pixel_put(mlx, wind, x, y, 0x0000FF00);
		x--;
		e += m;
		if (e <= 0)
		{
			y++;
			e++;
		}
	}
}

void	driving_x(void *mlx, void *wind, t_data *coords1, t_data *coords2)
{
	VARS;
	m = (coords2->y - coords1->y) / (coords2->x - coords1->x);
	if (m < 0)
	{
		draw_negative_x(mlx, wind, coords1, coords2);
		return ;
	}
	if (coords1->x > coords2->x)
		driving_x(mlx, wind, coords2, coords1);
	e = m - 1.0;
	x = coords1->x;
	y = coords1->y;
	while (x <= coords2->x)
	{
		mlx_pixel_put(mlx, wind, x, y, 0x00FF0000);
		x++;
		e += m;
		if (e >= 0)
		{
			y++;
			e--;
		}
	}
}

void	driving_y(void *mlx, void *wind, t_data *coords1, t_data *coords2)
{
	VARS;
	m = (coords2->x - coords1->x) / (coords2->y - coords1->y);
	if (m < 0)
	{
		draw_negative_y(mlx, wind, coords1, coords2);
		return ;
	}
	if (coords1->y > coords2->y)
		driving_y(mlx, wind, coords2, coords1);
	e = m - 1;
	x = coords1->x;
	y = coords1->y;
	while (y < coords2->y)
	{
		mlx_pixel_put(mlx, wind, x, y, 0x00FFFF00);
		y++;
		e += m;
		if (e >= 0)
		{
			x++;
			e--;
		}
	}
}

void	bres_line(void *mlx, void *wind, t_data *p1, t_data *p2)
{
	t_line	line;

	line.dx = (p2->x - p1->x);
	line.dy = (p2->y - p1->y);
	line.m = (line.dy / line.dx);
	if (ft_abs_value(line.m) < 1)
		driving_x(mlx, wind, p1, p2);
	else
		driving_y(mlx, wind, p1, p2);
}
