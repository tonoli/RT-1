/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:40:51 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/07 20:01:45 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

void		size_interpretor(t_obj *obj, t_vector *v1, t_vector *v2)
{
	*v1 = vector_sub(obj->ori, vector_scale(vector_negative(obj->dir), obj->len1));
	*v2 = vector_sub(obj->ori, vector_scale(vector_negative(obj->dir2), obj->len2));
}

double		hit_tri(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v0v1;
	t_vector	v0v2;
	t_vector	n;
	t_vector	p;
	t_vector	c;
	t_vector	edge0;
	t_vector	vp0;
	t_vector	edge1;
	t_vector	vp1;
	t_vector	edge2;
	t_vector	vp2;
	double		n_dot_raydir;
	double		d;
	double		t;

	size_interpretor(obj, &v1, &v2);
	v0v1 = vector_sub(v1, obj->ori);
	v0v2 = vector_sub(v2, obj->ori);

	n = vector_cross(v0v1, v0v2);

	n_dot_raydir = vector_dot(n, ray.dir);
	if (fabs(n_dot_raydir) < 0.00000001)
		return (-1);

	d = vector_dot(n, obj->ori);
	
	t = (vector_dot(n, ray.ori) + d) / -n_dot_raydir;
	if (t < 0 || (t < e->t_min && t > e->t_max))
		return (-1);
	
	p = vector_add(ray.ori, vector_scale(ray.dir, t));
	
	edge0 = vector_sub(v1, obj->ori);
	vp0 = vector_sub(p, obj->ori);
	c = vector_cross(edge0, vp0);
	if (vector_dot(n, c) < 0)
		return (-1);

	edge1 = vector_sub(v2, v1);
	vp1 = vector_sub(p, v1);
	c = vector_cross(edge1, vp1);
	if (vector_dot(n, c) < 0)
		return (-1);

	edge2 = vector_sub(obj->ori, v2);
	vp2 = vector_sub(p, v2);
	c = vector_cross(edge2, vp2);
	if (vector_dot(n, c) < 0)
		return (-1);

	obj->t = t;
	obj->cross = vector_factor(ray.ori, t, ray.dir);
	obj->normal = n;
	return (t);
}
