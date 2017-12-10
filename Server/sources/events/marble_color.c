/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:13:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 17:13:27 by itonoli-         ###   ########.fr       */
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
		e->selected->marblecolor.x -= 0.0;
	else if (mode == INCREASE_MAX)
		e->selected->marblecolor.x = 1;
	else if (mode == DECREASE_MAX)
		e->selected->marblecolor.x = 0;
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
	else if (mode == INCREASE_MAX)
		e->selected->marblecolor.x = 1;
	else if (mode == DECREASE_MAX)
		e->selected->marblecolor.x = 0;
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
	else if (mode == INCREASE_MAX)
		e->selected->marblecolor.x = 1;
	else if (mode == DECREASE_MAX)
		e->selected->marblecolor.x = 0;
}
