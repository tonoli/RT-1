/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/08 14:46:06 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

static void	decompose_a_coef(t_obj *obj, t_ray ray)
{
	obj->a = vector_dot(ray.dir, ray.dir) -
		(vector_dot(ray.dir, obj->dir) * (vector_dot(ray.dir, obj->dir)));
}

static void	decompose_b_coef(t_obj	*obj, t_ray ray, t_vector v)
{
	obj->b = 2 * (vector_dot(ray.dir, v) -
			vector_dot(ray.dir, obj->dir) * vector_dot(v, obj->dir));
}

static void	decompose_c_coef(t_obj *obj, t_ray ray, t_vector v)
{
	obj->c = vector_dot(v, v) -
		(vector_dot(v, obj->dir) * vector_dot(v, obj->dir)) - obj->radius;
}

static double	solution(t_env *e, t_obj *obj, t_ray ray, t_vector v)
{
	double	t;
	double	x;

	t = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
	if (x < obj->height && x >= 0)
	{
		if (t > e->t_min && t < e->t_max && t)
		{
			obj->t = t;
			obj->cross = vector_factor(ray.ori, t, ray.dir);
			obj->normal = normal_cyl(obj);
			return (t);
		}
	}
	t = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
	if (x < obj->height && x >= 0)
	{
		if (t > e->t_min && t < e->t_max)
		{
			obj->t = t;
			obj->cross = vector_factor(ray.ori, t, ray.dir);
			obj->normal = normal_cyl(obj);
			return (t);
		}
	}
	return (-1);
}

double			hit_cyl(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;

	ray.dir = vector_normalize(ray.dir);
	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray);
	decompose_b_coef(obj, ray, v);
	decompose_c_coef(obj, ray, v);
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0.00001)
		return (solution(e, obj, ray, v));
	return (-1);
}
