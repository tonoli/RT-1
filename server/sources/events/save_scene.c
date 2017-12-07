/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:47:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/05 20:05:15 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_save_cone(t_obj *obj, char **buf)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	asprintf(&str, "<object>\n\t<type>cone</type>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f</radius>\n\t<height>%f</height>\n\t<color>0x%.02X, 0x%.02X, 0x%.02X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z, obj->radius, obj->height, obj->color.x, obj->color.y, obj->color.z);
	if (obj->reflection)
	{
		asprintf(&tmp, "\t<reflection>%f</reflection>", obj->reflection);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->refraction)
	{
		asprintf(&tmp, "\t<refraction>%f</refraction>", obj->refraction);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->fuzz)
	{
		asprintf(&tmp, "\t<fuzz>%f</fuzz>", obj->fuzz);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	*buf = ft_strdup(str);
}

static void	ft_save_cylinder(t_obj *obj, char **buf)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	
	asprintf(&str, "<object>\n\t<type>cylinder</type>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f</radius>\n\t<height>%f</height>\n\t<color>0x%.02X, 0x%.02X, 0x%.02X</color>\n",	obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z, obj->radius, obj->height, obj->color.x, obj->color.y, obj->color.z);
	if (obj->reflection)
	{
		asprintf(&tmp, "\t<reflection>%f</reflection>", obj->reflection);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->refraction)
	{
		asprintf(&tmp, "\t<refraction>%f</refraction>", obj->refraction);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->fuzz)
	{
		asprintf(&tmp, "\t<fuzz>%f</fuzz>", obj->fuzz);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	*buf = ft_strdup(str);
}

static void	ft_save_plane(t_obj *obj, char **buf)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	
	asprintf(&str, "<object>\n\t<type>plane</type>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, %f, %f</direction>\n\t<color>0x%.02X, 0x%.02X,0x%.02X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x,obj->dir.y, obj->dir.z, obj->color.x, obj->color.y, obj->color.z);
	if (obj->reflection)
	{
		asprintf(&tmp, "\t<reflection>%f</reflection>", obj->reflection);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->refraction)
	{
		asprintf(&tmp, "\t<refraction>%f</refraction>", obj->refraction);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->fuzz)
	{
		asprintf(&tmp, "\t<fuzz>%f</fuzz>", obj->fuzz);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	*buf = ft_strdup(str);
}

static void	ft_save_sphere(t_obj *obj, char **buf)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	
	asprintf(&str, "<object>\n\t<type>sphere</type>\n\t<origin>%f, %f, %f</origin>\n\t<radius>%f</radius>\n\t<color>0x%.02X, 0x%.02X, 0x%.02X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->radius, obj->color.x,	obj->color.y, obj->color.z);
	if (obj->reflection)
	{
		asprintf(&tmp, "\t<reflection>%f</reflection>", obj->reflection);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->refraction)
	{
		asprintf(&tmp, "\t<refraction>%f</refraction>", obj->refraction);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	if (obj->fuzz)
	{
		asprintf(&tmp, "\t<fuzz>%f</fuzz>", obj->fuzz);
		tmp2 = ft_strdup(str);
		ft_strdel(&str);
		str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	*buf = ft_strdup(str);
}

static void	ft_save_sphere(t_obj cam, char **buf)
{
	asprintf(buf, "<camera>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, %f, %f</direction>\n</camera>\n\n", cam->ori.x, cam->ori.y, cam->ori.z, cam->dir.x, cam->dir.y, cam->dir.z);
}

void	save_scene(t_env *env)
{
	char	*buf;
	int		file;

	file = open("save_scene.xml", O_RDWR | O_CREAT); // <height> && list modif && rand && marble effect
	ft_save_camera(env->camera, &buf);
	write(file, buf, strlen(buf));
	while (env->objects->next)
	{
		if (env->objects->type == 1)
			ft_save_sphere(env->objects, &buf);
		if (env->objects->type == 2)
			ft_save_plane(env->objects, &buf);
		if (env->objects->type == 3)
			ft_save_cylinder(env->objects, &buf);
		if (env->objects->type == 4)
			ft_save_cone(env->objects, &buf);
		if (*buf != NULL)
		{
			write(file, buf, strlen(buf));
			ft_strdel(&buf);
			write(file, "</object>", 9);
			write(file, "\n\n", 2);
			env->objects = env->objects->next;
		}
	}
}
