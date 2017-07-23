/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:28:28 by sdarsie           #+#    #+#             */
/*   Updated: 2017/05/09 19:53:56 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char		***allocate_mem(void)
{
	char		***get;
	int			i;
	int			j;

	i = -1;
	j = 0;
	get = (char***)malloc(sizeof(char**) * 1500);
	while (++i <= 900)
		get[i] = malloc(sizeof(char**) * 1500);
	i = 0;
	while (i < 900)
	{
		j = 0;
		while (j < 20)
		{
			get[i][j] = ft_strnew(10);
			ft_bzero(get[i][j], 10);
			j++;
		}
		i++;
	}
	return (get);
}

t_data			*get_data(const int fd, void *mlx, void *wind)
{
	int			i;
	char		*line;
	char		***get;
	t_data		*points;

	i = 0;
	get = allocate_mem();
	while ((get_next_line(fd, &line)) > 0)
		get[i++] = ft_strsplit(line, ' ');
	check(get);
	points = prep_data(get, mlx, wind);
	clear_data(get, 1);
	free(get);
	free(line);
	return (points);
}
