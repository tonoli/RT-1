/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 00:15:19 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_render_env(t_env *e)
{
	e->avoid = NULL;
	perlin_generate(e);
	perlin_generate_perm((int *)&e->perm_x);
	perlin_generate_perm((int *)&e->perm_y);
	perlin_generate_perm((int *)&e->perm_z);
	e->wait = 0;
	e->increment = 1;
	e->recursion = 10;
	e->sum = 0;
	e->threads = 32;
	e->magic = MAGIC;
	e->skybox_total = TOTAL_SKYBOX;
	e->obj_tx_total = TOTAL_TX;
	e->tsp_tx_total = TOTAL_TSP;
}
