/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:30:19 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	dam_two_color_r(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier2.x < 1.0)
		e->selected->damier2.x += 0.01;
	else if (mode == DECREASE && e->selected->damier2.x > 0.0)
		e->selected->damier2.x -= 0.01;
}

void	dam_two_color_g(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier2.y < 1.0)
		e->selected->damier2.y += 0.01;
	else if (mode == DECREASE && e->selected->damier2.y > 0.0)
		e->selected->damier2.y -= 0.01;
}

void	dam_two_color_b(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier2.z < 1.0)
		e->selected->damier2.z += 0.01;
	else if (mode == DECREASE && e->selected->damier2.z > 0.0)
		e->selected->damier2.z -= 0.01;
}
