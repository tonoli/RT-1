/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:25:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
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
