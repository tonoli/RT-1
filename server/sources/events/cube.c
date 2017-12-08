/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:41:45 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/08 13:23:29 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	face_f(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori = vector_add(vector_add(vector_add(env->objects->ori, vector_scale(env->objects->dir, env->objects->len1)), vector_scale(env->objects->dir2, env->objects->len2)), vector_scale(env->objects->dir3, env->objects->len3));
	obj->dir = vector_negative(env->objects->dir2);
	obj->dir2 = vector_negative(env->objects->dir3);
	obj->len2 = env->objects->len2;
	obj->len3 = env->objects->len3;
	obj->color = (t_vector){0xff, 0xff, 0x00};
	obj_push_back(&env->objects, obj);
}

void	face_e(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori = vector_add(vector_add(vector_add(env->objects->ori, vector_scale(env->objects->dir, env->objects->len1)), vector_scale(env->objects->dir2, env->objects->len2)), vector_scale(env->objects->dir3, env->objects->len3));
	obj->dir = vector_negative(env->objects->dir);
	obj->dir2 = vector_negative(env->objects->dir3);
	obj->len1 = env->objects->len1;
	obj->len3 = env->objects->len3;
	obj->color = (t_vector){0x00, 0xff, 0xff};
	obj_push_back(&env->objects, obj);
}

void	face_d(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori = vector_add(vector_add(vector_add(env->objects->ori, vector_scale(env->objects->dir, env->objects->len1)), vector_scale(env->objects->dir2, env->objects->len2)), vector_scale(env->objects->dir3, env->objects->len3));
	obj->dir = vector_negative(env->objects->dir);
	obj->dir2 = vector_negative(env->objects->dir2);
	obj->len1 = env->objects->len1;
	obj->len2 = env->objects->len2;
	obj->color = (t_vector){0xff, 0x00, 0xff};
	obj_push_back(&env->objects, obj);
}

void	face_c(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori.x = env->objects->ori.x;
	obj->ori.y = env->objects->ori.y;
	obj->ori.z = env->objects->ori.z;
	obj->dir = env->objects->dir2;
	obj->dir2 = env->objects->dir3;
	obj->len2 = env->objects->len2;
	obj->len3 = env->objects->len3;
	obj->color = (t_vector){0xff, 0xff, 0x00};
	obj_push_back(&env->objects, obj);
}

void	face_b(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori.x = env->objects->ori.x;
	obj->ori.y = env->objects->ori.y;
	obj->ori.z = env->objects->ori.z;
	obj->dir = env->objects->dir;
	obj->dir2 = env->objects->dir3;
	obj->len1 = env->objects->len1;
	obj->len3 = env->objects->len3;
	obj->color = (t_vector){0x00, 0xff, 0xff};
	obj_push_back(&env->objects, obj);
}

void	face_a(t_env *env)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 5;
	obj->ori.x = env->objects->ori.x;
	obj->ori.y = env->objects->ori.y;
	obj->ori.z = env->objects->ori.z;
	obj->dir = env->objects->dir;
	obj->dir2 = env->objects->dir2;
	obj->len1 = env->objects->len1;
	obj->len2 = env->objects->len2;
	obj->color = (t_vector){0xff, 0x00, 0xff};
	obj_push_back(&env->objects, obj);
}

void	create_cube(t_env *e)
{
	face_a(e);
	face_b(e);
	face_c(e);
	face_d(e);
	face_e(e);
	face_f(e);
}
