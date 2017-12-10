/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:45:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

//http://cosinekitty.com/raytrace/chapter14_set_operations.html

//http://www.ams.org/journals/mcom/1960-14-071/S0025-5718-1960-0117882-6/S0025-5718-1960-0117882-6.pdf

//http://users.wowway.com/~phkahler/torus.pdf

//https://github.com/Victor-Savu/vgt/blob/679745bb31bee728a9397e634a8b967b3db6c037/math/roots3and4.c

double	hit_torus(t_env *e, t_obj *obj, t_ray ray)
{

	t_vector A;
	t_vector C;
	t_vector P0, P1;
	t_vector Q;
	double u;
	double v;
	C = obj->ori;
	A = vector_normalize(obj->dir);
	P0 = ray.ori;
	P1 = vector_normalize(ray.dir);
	Q = vector_sub(P0, C);
	u = vector_dot(A, Q);
	v = vector_dot(A, P1);

	obj->a = 1.0 - (v * v);
	obj->b = 2.0 * (vector_dot(Q, P1) - (u * v));
	obj->c = vector_dot(Q, Q) - (u * u);
	obj->d = vector_dot(Q, Q) + (obj->radius * obj->radius) - (obj->small_r * obj->small_r);

	double cube[5];
	cube[4] = 1.0;
	cube[3] = 4.0 * (vector_dot(Q, P1));
	cube[2] = (2.0 * obj->d) + (0.25 * cube[3] * cube[3]) - (4.0 * obj->radius * obj->radius * obj->a);
	cube[1] = (cube[3] * obj->d) - (4.0 * obj->radius * obj->radius * obj->b);
	cube[0] = (obj->d * obj->d) - (4.0 * obj->radius * obj->radius * obj->c);

	double ret[4] = {-1.0, -1.0, -1.0, -1.0};

	int r = solve_quartic(cube, ret);

	if (!r)
		return (-1);

	double best = e->t_max;
	double found = 0;

	for (int i = 0; i < r; ++i)
	{
		if (ret[i] > e->t_min && ret[i] < best)
		{
			best = ret[i];
			found = 1;
		}
	}

	if (!found)
		return -1;

	obj->t = best;
	obj->cross = vector_factor(ray.ori, best, vector_normalize(ray.dir));
	obj->normal = normal_torus(obj);

	return (best);

	return (-1);
}
