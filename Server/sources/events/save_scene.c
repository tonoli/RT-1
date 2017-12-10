/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:47:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 19:43:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*g_filter[] =
{
	NULL,
	"sepia",
	"greyscale",
	"negative"
};

static void	ft_save_filter(char **str)
{
	char *tmp;

	asprintf(&tmp, "\t<filter>%s</filter>\n",
			g_filter[g_e->filter]);
	*str = ft_post_realloc_str(*str, tmp);
	ft_strdel(&tmp);
}

static void	ft_save_skybox(char **str)
{
	char	*tmp;

	asprintf(&tmp, "\t<skybox>%s</skybox>\n",
			g_skybox_sources[g_e->skybox_index].name);
	*str = ft_post_realloc_str(*str, tmp);
	ft_strdel(&tmp);
}

static void	ft_save_transparent(char **str, t_obj *obj)
{
	char	*tmp;

	asprintf(&tmp, "\t<transparent>%s</transparent>\n",
			g_tsp_sources[obj->tsp_index].name);
	*str = ft_post_realloc_str(*str, tmp);
	ft_strdel(&tmp);
}

static void	ft_save_texture(char **str, t_obj *obj)
{
	char	*tmp;
	char	*tmp2;

	asprintf(&tmp, "\t<texture>%s</texture>\n",
			g_color_sources[obj->texture_index].name);
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

	asprintf(&tmp, "\t<marblesize>%f</marblesize>\n\t<marblecolor>0x%.2X, 0x%.2X, \
0x%.2X</marblecolor>\n", obj->marblesize, (int)(obj->marblecolor.x * 255.0),
	(int)(obj->marblecolor.y * 255.0), (int)(obj->marblecolor.z * 255.0));
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

	asprintf(&tmp, "\t<reflection>%d</reflection>\n", obj->reflection);
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
%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f</lenght2>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
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

static void	ft_save_torus(t_obj *obj, char **buf)
{
	char	*str;

	asprintf(&str, "<object>\n\t<type>torus</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<small_radius>%f</small_radius>\n\t<color>0x%.2X,\
0x%.2X, 0x%.2X</color>\n",
	obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y,
	obj->dir.z, sqrt(obj->radius), sqrt(obj->small_r),
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
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<height>%f</height>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	obj->dir.x, obj->dir.y, obj->dir.z, sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0), (int)(obj->color.z * 255.0));
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
</origin>\n\t<radius>%f</radius>\n\t<height>%f</height>\n\t<color>\
0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	sqrt(obj->radius), sqrt(obj->height), (int)(obj->color.x * 255.0),
	(int)(obj->color.y * 255.0), (int)(obj->color.z * 255.0));
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
	if (obj->tsp_index > -1)
		ft_save_transparent(&str, obj);
	if (obj->texture_index > -1)
		ft_save_texture(&str, obj);
	*buf = ft_strdup(str);
}

static void	ft_save_camera(t_obj *cam, char **buf)
{
	asprintf(buf, "<camera>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, \
%f, %f</direction>\n", cam->ori.x, cam->ori.y,
	cam->ori.z, cam->dir.x, cam->dir.y, cam->dir.z);
	if (g_e->skybox_index > -1)
		ft_save_skybox(buf);
	if (g_e->skybox_index > 0 && g_e->skybox_index < 4)
		ft_save_filter(buf);
}

char	*name_file(void)
{
	char			*buffer;
	struct tm		*tm_info;
	struct timeval	tv;

	buffer = ft_strnew(30);
	gettimeofday(&tv, NULL);
	tm_info = localtime(&tv.tv_sec);
	strftime(buffer, 30, "%Y%m%d_%H%M%S", tm_info);
	return (buffer);
}


void  save_scene(t_env *env)
{
	char  *buf;
	int    file_xml;
	int    file_bmp;
	t_obj  *tmp;

	// int scene_folder = mkdir("./scenes");
	char *name = name_file();
	char *name_xml = ft_post_realloc_str(name, ".xml");
	file_xml  = open(name_xml, O_RDWR | O_CREAT | O_TRUNC, O_MODE);

	// XML
	ft_save_camera(&env->camera, &buf);
	write(file_xml, buf, strlen(buf));
	write(file_xml, "</camera>\n\n", ft_strlen("</camera>\n\n"));
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
		if (env->objects->type == OBJ_TORUS)
			ft_save_torus(env->objects, &buf);
		if (buf != NULL)
		{
			write(file_xml, buf, strlen(buf));
			ft_strdel(&buf);
			write(file_xml, "</object>", 9);
			write(file_xml, "\n\n", 2);
			env->objects = env->objects->next;
		}
	}
	env->objects = tmp;

	// BMP
	// int bmp_folder = makdir("./saved_images")
	char *names = name_file();
	char *name_bmp = ft_post_realloc_str(names, ".bmp");
	file_bmp = open(name_bmp, O_RDWR | O_CREAT | O_TRUNC, O_MODE);
	if ((SDL_SaveBMP(env->s_raytracer, name_bmp) < 0))
		fatal_quit("Save PNG");
	char *sys;
	char *namess = name_file();
	asprintf(&sys, "sips -s format png %s --out %s.png", name_bmp, namess);
	system(sys);
	//SDL_FreeSurface(env->s_tmp);
}
