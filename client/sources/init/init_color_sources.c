/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_sources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:03:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 21:27:50 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static const t_texture_sources g_color_sources[] =
{
	{"earth", "./textures/color/earth.png"},
	{"moon", "./textures/color/moon.jpg"},
	{"mars", "./textures/color/mars.jpg"},
	{"sun", "./textures/color/sun.jpg"},
	{"football", "./textures/color/football.jpg"},
	{"baseball", "./textures/color/baseball.jpeg"},
	{"brick1", "./textures/color/brick1.jpg"},
	{"floor1", "./textures/color/floor1.jpg"},
	{"floor2", "./textures/color/floor2.png"},
	{"Metal(31)", "./textures/color/Metal(31).jpg"},
	{"Metal(32)", "./textures/color/Metal(32).jpg"},
	{"Metal(33)", "./textures/color/Metal(33).jpg"},
	{"Metal(34)", "./textures/color/Metal(34).jpg"},
	{"Metal(35)", "./textures/color/Metal(35).jpg"},
	{"Metal(36)", "./textures/color/Metal(36).jpg"},
	{"pavement2", "./textures/color/pavement2.jpg"},
	{"pavement3", "./textures/color/pavement3.jpg"},
	{"punisher", "./textures/color/punisher.jpeg"},
	{"raytracer", "./textures/color/raytracer.png"},
	{"rayure", "./textures/color/rayure.jpeg"},
	{"stone1", "./textures/color/stone1.jpg"},
	{"stone2", "./textures/color/stone2.jpg"},
	{"stone3", "./textures/color/stone3.jpg"},
	{"stone4", "./textures/color/stone4.jpg"},
	{"stone5", "./textures/color/stone5.jpg"},
	{"stone6", "./textures/color/stone6.jpg"},
	{"wood5", "./textures/color/wood5.jpg"},
	{"zebra", "./textures/color/zebra.jpeg"},
	{NULL, NULL}
};

void	init_color_tx_sources(t_env *e)
{
	int i;

	g_mem.obj_tx_total = 0;
	i = 0;
	while (g_color_sources[i].file_address)
	{
		if (!(g_mem.s_obj_tx[i] = IMG_Load(g_color_sources[i].file_address)))
		{
			printf("FATAL : Failed to load color texture %s\n",
											g_color_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.obj_tx_total++;
	}
}
