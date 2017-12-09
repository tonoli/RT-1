/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:13:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	marble_color_r(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if (mode == INCREASE && e->selected->marblecolor.x < 1.0)
		e->selected->marblecolor.x += 0.01;
	else if (mode == DECREASE && e->selected->marblecolor.x > 0.0)
		e->selected->marblecolor.x -= 0.01;
}

void	marble_color_g(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if (mode == INCREASE && e->selected->marblecolor.y < 1.0)
		e->selected->marblecolor.y += 0.01;
	else if (mode == DECREASE && e->selected->marblecolor.y > 0.0)
		e->selected->marblecolor.y -= 0.01;
}

void	marble_color_b(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if (mode == INCREASE && e->selected->marblecolor.z < 1.0)
		e->selected->marblecolor.z += 0.01;
	else if (mode == DECREASE && e->selected->marblecolor.z > 0.0)
		e->selected->marblecolor.z -= 0.01;
}
