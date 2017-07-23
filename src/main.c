/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:33:49 by sdarsie           #+#    #+#             */
/*   Updated: 2017/05/10 19:02:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	void	*mlx;
	void	*wind;
	t_data	*coords;

	if (argc != 2)
	{
		write(1, "No file provided\n", 17);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "bad filedes\n", 12);
		exit(0);
	}
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 2000, 1500, "window");
	coords = get_data(fd, mlx, wind);
	begin(coords);
	clear_data(coords, 0);
	return (0);
}
