/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 05:36:19 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 16:59:20 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	rotate_object_x(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->dir.x += ROT_SPEED;
	else if (mode == DECREASE)
		e->selected->dir.x -= ROT_SPEED;
	else if (mode == INCREASE_MAX)
			e->selected->dir.x += ROT_SPEED * 10;
	else if (mode == DECREASE_MAX)
			e->selected->dir.x -= ROT_SPEED * 10;
	e->selected->dir = vector_normalize(e->selected->dir);
}

void	rotate_object_y(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->dir.y += ROT_SPEED;
	else if (mode == DECREASE)
		e->selected->dir.y -= ROT_SPEED;
	else if (mode == INCREASE_MAX)
		e->selected->dir.y += ROT_SPEED * 10;
	else if (mode == DECREASE_MAX)
		e->selected->dir.y -= ROT_SPEED * 10;
	e->selected->dir = vector_normalize(e->selected->dir);
}

void	rotate_object_z(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->dir.z += ROT_SPEED;
	else if (mode == DECREASE)
		e->selected->dir.z -= ROT_SPEED;
	else if (mode == INCREASE_MAX)
		e->selected->dir.z += ROT_SPEED * 10;
	else if (mode == DECREASE_MAX)
		e->selected->dir.z -= ROT_SPEED * 10;
	e->selected->dir = vector_normalize(e->selected->dir);
}
