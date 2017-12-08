/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/08 14:55:42 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

static void	decompose_a_coef(t_obj *obj, t_ray ray, double k)
{
	obj->a = vector_dot(ray.dir, ray.dir) - ((1 + k * k) * vector_dot(ray.dir, obj->dir) * vector_dot(ray.dir, obj->dir));
}

static void	decompose_b_coef(t_obj *obj, t_ray ray, t_vector v, double k)
{
	obj->b = 2 * (vector_dot(ray.dir, v) - ((1 + k * k) * vector_dot(ray.dir, obj->dir) * vector_dot(v, obj->dir)));
}

static void	decompose_c_coef(t_obj *obj, t_vector v, double k)
{
	obj->c = vector_dot(v, v) - ((1 + k * k) * vector_dot(v, obj->dir) * vector_dot(v, obj->dir));
}

static double	solution(t_env *e, t_obj *obj, t_ray ray, t_vector v)
{
	double	t;
	double	x;

	if (obj->d > 0.001)
	{
		t = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
		x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
		if ((x < (obj->height / 2) && x > -(obj->height / 2)) || obj->height <= 0)
		{
			if (t > e->t_min && t < e->t_max)
			{
				obj->t = t;
				obj->cross = vector_factor(ray.ori, t, ray.dir);
				obj->normal = normal_cone(obj);
				return (t);
			}
		}
		t = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
		x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
		if ((x < (obj->height / 2) && x > -(obj->height / 2)) || obj->height <= 0)
		{
			if (t > e->t_min && t < e->t_max)
			{
				obj->t = t;
				obj->cross = vector_factor(ray.ori, t, ray.dir);
				obj->normal = normal_cone(obj);
				return (t);
			}
		}
	}
	return (-1);
}

double			hit_cone(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	double		k;

	k = tan(obj->radius / 2);
	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray, k);
	decompose_b_coef(obj, ray, v, k);
	decompose_c_coef(obj, v, k);
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	return (solution(e, obj, ray, v));
}
