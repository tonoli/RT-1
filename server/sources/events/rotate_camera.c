/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:55:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:44:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	pitch_up(t_env *e)
{
	e->camera.dir.y += ROT_SPEED;
}

void	pitch_down(t_env *e)
{
	e->camera.dir.y -= ROT_SPEED;
}

void	yaw_left(t_env *e)
{
	e->camera.dir.x += ROT_SPEED;
}

void	yaw_right(t_env *e)
{
	e->camera.dir.x -= ROT_SPEED;
}
