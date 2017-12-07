/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squarre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:41:50 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/07 18:56:33 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

double		hit_squarre(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	tmp1;
	t_vector	tmp2;
	t_vector	tmp3;
	double		t;

	size_interpretor(obj, &v1, &v2);
	if ((t = hit_tri(e, obj, ray)) > -1)
		return (t);
	tmp1 = obj->ori;
	tmp2 = obj->dir;
	tmp3 = obj->dir2;

	obj->ori = vector_add(vector_add(obj->ori, vector_scale(obj->dir, obj->len1)), vector_scale(obj->dir2, obj->len2));
	obj->dir = vector_negative(obj->dir);
	obj->dir2 = vector_negative(obj->dir2);
	if ((t = hit_tri(e, obj, ray)) != -1)
	{
		obj->ori = tmp1;
		obj->dir = tmp2;
		obj->dir2 = tmp3;
		return (t);
	}
	obj->ori = tmp1;
	obj->dir = tmp2;
	obj->dir2 = tmp3;
	return (-1);
}
