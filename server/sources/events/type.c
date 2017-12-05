/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:28:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 08:35:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_type(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->type++;
	if (e->selected->type == 5)
		e->selected->type = 1;
}
