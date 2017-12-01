/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:22:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:44:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	move_ojbect_up(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.y += MOVE_SPEED / (double)2.0;
}

void	move_ojbect_down(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.y -= MOVE_SPEED / (double)2.0;
}

void	move_ojbect_forward(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x -= MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->selected->ori.y += MOVE_SPEED * sin(PITCH);
	e->selected->ori.z += MOVE_SPEED * cos(PITCH) * cos(YAW);
}

void	move_ojbect_backward(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x += MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->selected->ori.y -= MOVE_SPEED * sin(PITCH);
	e->selected->ori.z -= MOVE_SPEED * cos(PITCH) * cos(YAW);
}

void	move_ojbect_left(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x -= MOVE_SPEED * cos(YAW);
	e->selected->ori.z -= MOVE_SPEED * sin(YAW);
}

void	move_ojbect_right(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x += MOVE_SPEED * cos(YAW);
	e->selected->ori.z += MOVE_SPEED * sin(YAW);
}
