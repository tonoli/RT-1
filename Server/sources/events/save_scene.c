/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:47:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/09 20:08:15 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_save_transparent(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<transparent>%s</transparent>\n", g_tsp_sources[obj->tsp_index].name);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_texture(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<texture>%s</texture>\n", g_color_sources[obj->texture_index].name);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_light(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<light>%f</light>\n", obj->light);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}
static void	ft_save_damier(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<damier>%d</damier>\n\t<damier1>0x%.2X, 0x%.2X, 0x%.2X\
				</damier1>\n\t<damier2>0x%.2X, 0x%.2X, 0x%.2X</damier2>\n",
				obj->damier, (int)(obj->damier1.x * 255.0),
				(int)(obj->damier1.y * 255.0), (int)(obj->damier1.z * 255.0),
				(int)(obj->damier2.x * 255.0), (int)(obj->damier2.y * 255.0),
				(int)(obj->damier2.z * 255.0));
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_marble(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<marblesize>%f</marblesize>\n\t<marblecolor>%.2f, %.2f, \
				%.2f</marblecolor>\n", obj->marblesize, (obj->marblecolor.x
			   	* 255.0), (obj->marblecolor.y * 255.0), 
				 (obj->marblecolor.z * 255.0));
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_fuzz(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<fuzz>%f</fuzz>", obj->fuzz);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_refraction(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<refraction>%f</refraction>", obj->refraction);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_reflection(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

		asprintf(&tmp, "\t<reflection>%d</reflection>", obj->reflection);
		tmp2 = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
}

static void	ft_save_square(t_obj *obj, char **buf)
{
	char	*str;

	asprintf(&str, "<object>\n\t<type>square</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
			%f, %f</direction2>\n\t<direction3>%f, %f, %f</direction3>\n\t\
			lenght1>%f</lenght1>\n\t<lenght2>%f</lenght2>\n\t<lenght>%f\
			</lenght>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
			obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z,
			obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->dir3.x, obj->dir3.y,
			obj->dir3.z, obj->len1, obj->len2, obj->len3,
			(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
			(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_triangle(t_obj *obj, char **buf)
{
	char	*str;
	
	asprintf(&str, "<object>\n\t<type>triangle</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
			%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f\
			</lenght2>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, 
			obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z, 
			obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->len1, obj->len2, 
			(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
			(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_cone(t_obj *obj, char **buf)
{
	char	*str;

	asprintf(&str, "<object>\n\t<type>cone</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
			</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X\
			</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x,
			obj->dir.y, obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
			(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
			(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_cylinder(t_obj *obj, char **buf)
{
	char	*str;
	
	asprintf(&str, "<object>\n\t<type>cylinder</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
			</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\
			\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, 
			obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
			(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
			(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_plane(t_obj *obj, char **buf)
{
	char	*str;
	
	asprintf(&str, "<object>\n\t<type>plane</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<direction>%f, %f, %f</direction>\n\t<color>0x%.2X,\
			0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, 
			obj->dir.x,obj->dir.y, obj->dir.z, (int)(obj->color.x * 255.0),
			(int)(obj->color.y * 255.0), (int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->damier != 0)
		ft_save_damier(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_sphere(t_obj *obj, char **buf)
{
	char	*str;
	
	asprintf(&str, "<object>\n\t<type>sphere</type>\n\t<origin>%f, %f, %f\
			</origin>\n\t<radius>%f</radius>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\
			\n", obj->ori.x, obj->ori.y, obj->ori.z, sqrt(obj->radius),
			(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
			(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(&str, obj);
	if (obj->refraction)
		ft_save_refraction(&str, obj);
	if (obj->fuzz)
		ft_save_fuzz(&str, obj);
	if (obj->marblesize)
		ft_save_marble(&str, obj);
	if (obj->light)
		ft_save_light(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_camera(t_obj *cam, char **buf)
{
	asprintf(buf, "<camera>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, \
			%f, %f</direction>\n</camera>\n\n", cam->ori.x, cam->ori.y, 
			cam->ori.z, cam->dir.x, cam->dir.y, cam->dir.z);
}

void	save_scene(t_env *env)
{
	char	*buf;
	int		file;
	t_obj	*tmp;

	file = open("save_scene.xml", O_RDWR | O_CREAT); // <height> && list modif
	ft_save_camera(&env->camera, &buf);
	write(file, buf, strlen(buf));
	tmp = env->objects;
	while (env->objects)
	{
		if (env->objects->type == OBJ_SPHERE)
			ft_save_sphere(env->objects, &buf);
		if (env->objects->type == OBJ_PLANE)
			ft_save_plane(env->objects, &buf);
		if (env->objects->type == OBJ_CYL)
			ft_save_cylinder(env->objects, &buf);
		if (env->objects->type == OBJ_CONE)
			ft_save_cone(env->objects, &buf);
		if (env->objects->type == OBJ_TRI)
			ft_save_triangle(env->objects, &buf);
		if (env->objects->type == OBJ_SQUARE)
			ft_save_square(env->objects, &buf);
		if (buf != NULL)
		{
			write(file, buf, strlen(buf));
			ft_strdel(&buf);
			write(file, "</object>", 9);
			write(file, "\n\n", 2);
			env->objects = env->objects->next;
		}
	}
	env->objects = tmp;
}
