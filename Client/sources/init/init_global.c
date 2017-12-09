/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:45:55 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_globals(void)
{
	int				i;
	struct timeval	t;

	g_buffer = (int *)ft_memalloc(sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT);
	g_color_array = (t_vector **)ft_memalloc(
									sizeof(t_vector *) * (F_HEIGHT + 1));
	g_frame_array = (int **)ft_memalloc(sizeof(int *) * (F_HEIGHT + 1));
	i = -1;
	while (++i < (int)F_HEIGHT)
	{
		g_color_array[i] = (t_vector *)ft_memalloc(
											sizeof(t_vector) * (int)F_WIDTH);
		g_frame_array[i] = (int *)ft_memalloc(sizeof(int) * (int)F_WIDTH);
	}
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
}
