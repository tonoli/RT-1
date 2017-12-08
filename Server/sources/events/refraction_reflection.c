/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_reflection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:02:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 08:35:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_refraction(t_env *e, int sense)
{
	if (!e->selected)
		return ;
	if (sense == INCREASE)
		e->selected->refraction += 0.1;
	else if (sense == DECREASE && e->selected->refraction > 0.0)
		e->selected->refraction -= 0.1;
}

void	change_reflection(t_env *e, int sense)
{
	if (!e->selected)
		return ;
	if (sense == INCREASE)
		e->selected->reflection += 0.1;
	else if (sense == DECREASE && e->selected->reflection > 0.0)
		e->selected->reflection -= 0.1;
}
