/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:21:39 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 08:35:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	increase_limit(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->height++;
}

void	decrease_limit(t_env *e)
{
	if (!e->selected || e->selected->height == 0)
		return ;
	e->selected->height--;
}
