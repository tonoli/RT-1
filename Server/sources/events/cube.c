/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:41:45 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	scale_ori(t_env *e, t_obj *obj)
{
	obj->ori.x += e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y += e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z += e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
}

static void	face_f(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, -1, 0};
	obj->dir2 = (t_vector){0, 0, -1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}


static void	face_e(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){-1, 0, 0};
	obj->dir2 = (t_vector){0, 0, -1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void	face_d(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, -1, 0};
	obj->dir2 = (t_vector){-1, 0, 0};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void	face_c(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, 1, 0};
	obj->dir2 = (t_vector){0, 0, 1};
	obj->len2 = size;
	obj->len1 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void	face_b(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){1, 0, 0};
	obj->dir2 = (t_vector){0, 0, 1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void	face_a(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, 1, 0};
	obj->dir2 = (t_vector){1, 0, 0};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

void	create_cube(t_env *e)
{
	double	size;

	size = 42;
	face_a(e, size);
	face_b(e, size);
	face_c(e, size);
	face_d(e, size);
	face_e(e, size);
	face_f(e, size);
}
