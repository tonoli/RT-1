/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_sources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:12:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 20:53:14 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_texture_sources g_skybox_sources[] =
{
	{"appartment", "./textures/skybox/appartment.jpg"},
	{"bar", "./textures/skybox/bar.jpg"},
	{"bedroom", "./textures/skybox/bedroom.jpg"},
	{"clouds", "./textures/skybox/clouds.jpg"},
	{"fractale", "./textures/skybox/fractale.jpg"},
	{"snow", "./textures/skybox/snow.jpg"},
	{"universe", "./textures/skybox/universe.png"},
	{"aurore", "./textures/skybox/aurore.jpg"},
	{"Notre-Dame", "./textures/skybox/Notre-Dame.jpg"},	
	{"mountain", "./textures/skybox/mountain.jpg"},
	{"galaxy", "./textures/skybox/galaxy.jpg"},
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
		// printf("index = %d\n", e->skybox_index);		
		if (!(g_mem.s_skybox[i] = IMG_Load(g_skybox_sources[i].file_address)))
		{
			printf("FATAL : Failed to load skybox texture %s\n",
					g_skybox_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		// printf("g_skybox_sources[i].name = %s\n", g_skybox_sources[i].name);
		// printf("e->skybox_selected = %s\n", e->skybox_selected);
		// if (g_skybox_sources[i].name == e->skybox_selected && e->skybox == 1)
		// {
		// 	e->skybox_index = i;
		//  printf("index init if = %d\n", e->skybox_index);
		// }
		i++;
		g_mem.skybox_total++;
	}
	if (e->skybox != 1)
	{
		g_mem.current_skybox = NULL;
		g_mem.skybox_index = -1;
	}
}
