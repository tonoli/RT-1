/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transparency_sources.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:03:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 07:30:36 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_texture_sources g_tsp_sources[] =
{
	{"earth", "./textures/transparency/earth.png"},
	{NULL, NULL}
};

void	init_transparency_tx_sources(t_env *e)
{
	int i;

	g_mem.tsp_tx_total = 0;
	i = 0;
	while (g_tsp_sources[i].file_address)
	{
		if (!(g_mem.s_tsp_tx[i] = IMG_Load(g_tsp_sources[i].file_address)))
		{
			printf("FATAL : Failed to load transparency texture %s\n",
												g_tsp_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.tsp_tx_total++;
	}
}
