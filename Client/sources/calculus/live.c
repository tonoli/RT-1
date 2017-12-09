/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:39:32 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_vector	live_preview(t_env *e, t_obj *closest_obj, t_ray ray)
{
	if (closest_obj->damier)
		damier(closest_obj);
	if (closest_obj->current_texture)
		color_mapping(closest_obj);
	return (closest_obj->color);
}
