/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:25:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 16:09:37 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_radius(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->radius++;
	else if (mode == DECREASE && e->selected->radius > 0.0)
		e->selected->radius--;
}

void	change_angle(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->radius += 0.1;
	else if (mode == DECREASE && e->selected->radius > 0.0)
		e->selected->radius -= 0.1;
}

void	change_radius_angle(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (e->selected->type == OBJ_CONE)
		change_angle(e, mode);
	else
		change_radius(e, mode);
}
