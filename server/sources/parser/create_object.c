/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/30 18:11:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_obj	*new_obj(void)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	new->tsp_index = -1;
	new->texture_index = -1;
	new->next = NULL;
	return (new);
}

void	obj_push_back(t_obj **list, t_obj *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}
