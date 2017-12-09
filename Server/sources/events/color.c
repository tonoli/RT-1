/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:45:40 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_color_r(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->color.x < 1.0)
		e->selected->color.x += 0.01;
	else if (mode == DECREASE && e->selected->color.x > 0.0)
		e->selected->color.x -= 0.01;
}

void	change_color_g(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->color.y < 1.0)
		e->selected->color.y += 0.01;
	else if (mode == DECREASE && e->selected->color.y > 0.0)
		e->selected->color.y -= 0.01;
}

void	change_color_b(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->color.z < 1.0)
		e->selected->color.z += 0.01;
	else if (mode == DECREASE && e->selected->color.z > 0.0)
		e->selected->color.z -= 0.01;
}
