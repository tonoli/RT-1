/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:28:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 00:01:46 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		int_obj(t_env *e)
{
	if (e->selected->type == OBJ_CONE || e->selected->type == OBJ_PLANE
		|| e->selected->type == OBJ_CYL)
	{
		e->selected->dir.x = 0;
		e->selected->dir.y = -1;
		e->selected->dir.z = 0;
		e->selected->height = 50;
	}
	if (e->selected->type == OBJ_TORUS)
	{
		e->selected->small_r = sqrt(10);
		e->selected->big_r = sqrt(100);
	}
	else
	{
		if (!e->selected->radius)
			e->selected->radius = 100;
	}
}

void	change_type(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->type++;
	if (mode == DECREASE)
		e->selected->type--;
	if (e->selected->type == 8)
		e->selected->type = OBJ_SPHERE;
	if (e->selected->type == 0)
		e->selected->type = OBJ_TORUS;
	int_obj(e);
}
