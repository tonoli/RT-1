/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 02:13:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_vector	diffuse(t_env *e, t_ray ray, t_obj *closest_obj)
{
	t_vector color;
	t_vector v;
	t_vector obj_col;

	(closest_obj->marblesize) ? marble(e, &closest_obj->color, closest_obj) : 0;
	(closest_obj->current_texture) ? color_mapping(closest_obj) : 0;
	if (closest_obj->emit)
		return (vector_scale(closest_obj->color, closest_obj->light));
	v = vector_add(closest_obj->cross, closest_obj->normal);
	v = vector_add(v, random_unit_sphere());
	ray.ori = closest_obj->cross;
	ray.dir = vector_sub(v, closest_obj->cross);
	obj_col = closest_obj->color;
	color = compute_objects(e, ray);
	color.x *= obj_col.x * 0.8;
	color.y *= obj_col.y * 0.8;
	color.z *= obj_col.z * 0.8;
	if (closest_obj->marblesize)
		marble(e, &color, closest_obj);
	return (color);
}
