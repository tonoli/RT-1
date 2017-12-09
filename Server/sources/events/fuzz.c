/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:37:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_fuzz(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE && e->selected->fuzz < 1.0)
		e->selected->fuzz += 0.1;
	else if (mode == DECREASE && e->selected->fuzz > 0.0)
		e->selected->fuzz -= 0.1;
}
