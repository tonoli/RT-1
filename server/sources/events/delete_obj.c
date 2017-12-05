/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:24:57 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 08:35:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	delete_object(t_env *e)
{
	t_obj *obj;

	if (!e->selected)
		return ;
	if (e->objects == e->selected)
	{
		e->objects = e->objects->next;
		free(e->selected);
		e->selected = NULL;
	}
	else
	{
		obj = e->objects;
		while (obj)
		{
			if (obj->next == e->selected)
			{
				obj->next = obj->next->next;
				free(e->selected);
				e->selected = NULL;
				break ;
			}
			obj = obj->next;
		}
	}
}
