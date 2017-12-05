/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 07:00:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 07:13:21 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

t_vector	vector_normalize(t_vector a)
{
	t_vector v;

	v = vector_scale(a, 1.0 / vector_magnitude(a));
	return (v);
}

t_vector	normal_sphere(t_obj *closest_obj)
{
	t_vector n;

	n = vector_sub(closest_obj->cross, closest_obj->ori);
	n = vector_normalize(n);
	return (n);
}

t_vector	normal_cone(t_obj *closest_obj)
{
	double		k;
	double		m;
	t_vector	a;
	t_vector	b;
	t_vector	al;

	a = vector_sub(closest_obj->cross, closest_obj->ori);
	m = vector_dot(a, closest_obj->dir);
	al = vector_add(closest_obj->ori, vector_scale(closest_obj->dir, m));
	k = vector_magnitude(vector_sub(closest_obj->cross, al)) / m;
	b = vector_scale(closest_obj->dir, m * (1 + k * k));
	return (vector_normalize(vector_sub(a, b)));
}

t_vector	normal_plane(t_obj *closest_obj, t_ray ray)
{
	double		dot;
	t_vector	n;

	dot = vector_dot(ray.dir, closest_obj->dir);
	if (dot > 0)
		n = vector_negative(closest_obj->dir);
	else
		n = closest_obj->dir;
	return (vector_normalize(n));
}

t_vector	normal_cyl(t_obj *closest_obj)
{
	t_vector	a;
	t_vector	b;

	a = vector_sub(closest_obj->cross, closest_obj->ori);
	b = vector_scale(closest_obj->dir, vector_dot(a, closest_obj->dir));
	return (vector_normalize(vector_sub(a, b)));
}
