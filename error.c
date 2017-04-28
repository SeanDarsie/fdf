/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:24:33 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/18 18:02:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int x)
{
	if (x == 0)
	{
		ft_putstr("incorrectly formatted input file\n");
		exit(1);
	}
	if (x == 1)
		exit(1);
}

void	check(char ***raw)
{
	int	i;
	int	w;
	int	k;

	i = 0;
	while (raw[0][i] != NULL)
		i++;
	w = i;
	i = 0;
	while (raw[i][0][0] != '\0')
	{
		k = 0;
		while (raw[i][k] != NULL)
			k++;
		if (k != w)
			error(0);
		i++;
	}
}
