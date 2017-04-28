/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:24:41 by sdarsie           #+#    #+#             */
/*   Updated: 2017/04/26 19:21:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_array(char ***data)
{
	int		i;
	int		k;

	i = 0;
	while (i < 900)
	{
		k = 0;
		while (k < 20)
		{
			free(data[i][k]);
			data[i][k] = NULL;
			k++;
		}
		i++;
	}
}

void		clear_data(void *data, int flag)
{
	t_data	*tmp;
	t_data	*del;
	char	***get;

	if (flag == 0)
	{
		tmp = (t_data*)data;
		del = (t_data*)data;
		while (data)
		{
			tmp = data;
			del = del->next;
			free(tmp);
		}
		data = NULL;
	}
	else
		free_array((char***)data);
}
