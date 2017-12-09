/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:28:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 16:18:29 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_type(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	e->selected->type++;
	if (e->selected->type == 4)
		e->selected->type = 1;
}
