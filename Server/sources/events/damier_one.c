/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:31:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

//Dont forget to setunset e->selected->damier....

void	dam_one_color_r(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier1.x < 1.0)
		e->selected->damier1.x += 0.01;
	else if (mode == DECREASE && e->selected->damier1.x > 0.0)
		e->selected->damier1.x -= 0.01;
}

void	dam_one_color_g(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier1.y < 1.0)
		e->selected->damier1.y += 0.01;
	else if (mode == DECREASE && e->selected->damier1.y > 0.0)
		e->selected->damier1.y -= 0.01;
}

void	dam_one_color_b(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->damier1.z < 1.0)
		e->selected->damier1.z += 0.01;
	else if (mode == DECREASE && e->selected->damier1.z > 0.0)
		e->selected->damier1.z -= 0.01;
}
