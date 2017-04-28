/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:06:37 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/18 14:01:05 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# define VARS double x, y, e, m

typedef struct	s_data
{
	double			x;
	double			y;
	double			z;
	int				w;
	int				h;
	double			cx;
	double			cy;
	void			*mlx;
	void			*wind;
	struct s_data	*next;
}				t_data;

typedef struct	s_mat
{
	double			x0;
	double			x1;
	double			x2;
	double			y0;
	double			y1;
	double			y2;
	double			z0;
	double			z1;
	double			z2;
}				t_mat;

typedef struct	s_line
{
	double			m;
	double			dy;
	double			dx;
	double			e;
	int				i;
	int				k;
	double			x1;
	double			x;
	double			y1;
	double			y;
	double			offy;
	double			offx;
}				t_line;

void			bres_line(void *mlx, void *wind, t_data *p1, t_data *p2);

t_data			*prep_data(char ***data, void *mlx, void *wind);

t_data			*get_data(const int fd, void *mlx, void *wind);

void			pass_pts(t_data *coords);

int				begin(t_data *coords);

void			clear_data(void *data, int flag);

void			show_perspective(t_data *coords, char c);

void			rot_matrices(t_data *coords, int deg, char dir);

void			check(char ***raw);

#endif
