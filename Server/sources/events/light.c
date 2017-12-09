/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:13:33 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	light_object(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->emit = e->selected->emit == 0 ? 1 : 0;
	if (e->selected->emit)
		e->selected->light = 3.0;
	else
		e->selected->light = 0;
}

void	change_light(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
	{
		e->selected->light++;
		if (e->selected->light < 1.0)
			e->selected->light = 1.0;
	}
	else if (mode == DECREASE)
	{
		e->selected->light--;
		if (e->selected->light < 1.0)
			e->selected->light = 0.0;
	}
	if (e->selected->light >= 1.0)
		e->selected->emit = 1;
}
