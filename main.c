/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:33:49 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/18 13:46:12 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*wind;
	t_data	*coords;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "bad filedes\n", 12);
		exit(0);
	}
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 1750, 1000, "window");
	coords = get_data(fd, mlx, wind);
	begin(coords);
	clear_data(coords, 0);
	return (0);
}
