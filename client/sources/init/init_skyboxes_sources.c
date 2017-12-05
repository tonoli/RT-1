/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_sources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:12:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 14:59:51 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_e_sources g_skybox_sources[] =
{
	{"appartment", "./es/skybox/appartment.jpg"},
	{"bar", "./es/skybox/bar.jpg"},
	{"bedroom", "./es/skybox/bedroom.jpg"},
	{"clouds", "./es/skybox/clouds.jpg"},
	{"fractale", "./es/skybox/fractale.jpg"},
	{"snow", "./es/skybox/snow.jpg"},
	{"universe", "./es/skybox/universe.png"},
	{"coucou", "./es/skybox/coucou.png"},
	{NULL, NULL}
};

void	init_skyboxes_tx_sources(t_env *e)
{
	int i;

	g_mem.skybox_index = 0;
	g_mem.skybox_total = 0;
	i = 0;
	while (g_skybox_sources[i].file_address)
	{
		if (!(g_mem.s_skybox[i] = IMG_Load(g_skybox_sources[i].file_address)))
		{
			printf("FATAL : Failed to load skybox e %s\n",
					g_skybox_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.skybox_total++;
	}
	g_mem.current_skybox = NULL;
	g_mem.skybox_index = -1;
}
