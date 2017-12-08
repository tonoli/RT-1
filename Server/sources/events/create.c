/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:29:26 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/08 14:54:31 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	create_cone(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_CONE;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	obj->marblecolor = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = -1;
	obj->dir.z = 0;
	obj->radius = 0.2;
	obj->height = 30;
	obj_push_back(&e->objects, obj);
	e->selected = obj;
}

void	create_plane(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_PLANE;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	obj->marblecolor = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH)) - 10.0;
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = -1;
	obj->dir.z = 0;
	obj_push_back(&e->objects, obj);
	e->selected = obj;
}

void	create_cylinder(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_CYL;
	obj->radius = 30;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	obj->marblecolor = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = 1;
	obj->dir.z = 0;
	obj->height = 30;
	obj_push_back(&e->objects, obj);
	e->selected = obj;
}

void	create_sphere(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->radius = 100.0;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	obj->marblecolor = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj_push_back(&e->objects, obj);
	e->selected = obj;
}

void	create_torus(t_env *e)
{

}
