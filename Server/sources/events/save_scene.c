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

static char		*g_filter[] =
{
	NULL,
	"sepia",
	"greyscale",
	"negative"
};

static void		ft_save_filter(FILE *file)
{
	fprintf(file, "\t<filter>%s</filter>\n", g_filter[g_e->filter]);
}

static void		ft_save_skybox(FILE *file)
{
	fprintf(file, "\t<skybox>%s</skybox>\n",
			g_skybox_sources[g_e->skybox_index].name);
}

static void		ft_save_transparent(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<transparent>%s</transparent>\n",
			g_tsp_sources[obj->tsp_index].name);
}

static void		ft_save_texture(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<texture>%s</texture>\n",
			g_color_sources[obj->texture_index].name);
}

static void		ft_save_light(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<light>%f</light>\n", obj->light);
}

static void		ft_save_damier(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<damier>%d</damier>\n\t<damier1>0x%.2X, 0x%.2X, 0x%.2X\
</damier1>\n\t<damier2>0x%.2X, 0x%.2X, 0x%.2X</damier2>\n",
	obj->damier, (int)(obj->damier1.x * 255.0),
	(int)(obj->damier1.y * 255.0), (int)(obj->damier1.z * 255.0),
	(int)(obj->damier2.x * 255.0), (int)(obj->damier2.y * 255.0),
	(int)(obj->damier2.z * 255.0));
}

static void		ft_save_marble(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<marblesize>%f</marblesize>\n\t<marblecolor>0x%.2X, \
0x%.2X, 0x%.2X</marblecolor>\n", obj->marblesize,
		(int)(obj->marblecolor.x * 255.0),
	(int)(obj->marblecolor.y * 255.0), (int)(obj->marblecolor.z * 255.0));
}

static void		ft_save_fuzz(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<fuzz>%f</fuzz>", obj->fuzz);
}

static void		ft_save_refraction(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<refraction>%f</refraction>", obj->refraction);
}

static void		ft_save_reflection(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<reflection>%d</reflection>\n", obj->reflection);
}

static void		ft_save_square(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>square</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f</lenght2>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
	obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z,
	obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->len1, obj->len2,
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_triangle(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>triangle</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f\
</lenght2>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
	obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z,
	obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->len1, obj->len2,
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_cone(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>cone</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X\
</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x,
	obj->dir.y, obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_cylinder(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>cylinder</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\
\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y,
	obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_torus(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>torus</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<small_radius>%f</small_radius>\n\t<color>0x%.2X,\
0x%.2X, 0x%.2X</color>\n",
	obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y,
	obj->dir.z, sqrt(obj->radius), sqrt(obj->small_r),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_plane(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>plane</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<height>%f</height>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	obj->dir.x, obj->dir.y, obj->dir.z, sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
		(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->damier != 0)
		ft_save_damier(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

static void		ft_save_sphere(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>sphere</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<radius>%f</radius>\n\t<height>%f</height>\n\t<color>\
0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	sqrt(obj->radius), sqrt(obj->height), (int)(obj->color.x * 255.0),
	(int)(obj->color.y * 255.0), (int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
	if (obj->tsp_index > -1)
		ft_save_transparent(obj, file);
	if (obj->texture_index > -1)
		ft_save_texture(obj, file);
}

static void		ft_save_camera(t_obj *cam, FILE *file)
{
	fprintf(file, "<camera>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, \
%f, %f</direction>\n", cam->ori.x, cam->ori.y,
	cam->ori.z, cam->dir.x, cam->dir.y, cam->dir.z);
	if (g_e->skybox_index > -1)
		ft_save_skybox(file);
	if (g_e->skybox_index > 0 && g_e->skybox_index < 4)
		ft_save_filter(file);
}

char			*new_name(void)
{
	char			*buffer;
	struct tm		*tm_info;
	struct timeval	tv;

	buffer = ft_strnew(42);
	gettimeofday(&tv, NULL);
	tm_info = localtime(&tv.tv_sec);
	strftime(buffer, 42, "%Y%m%d_%H%M%S", tm_info);
	return (buffer);
}

static void		(*g_print_obj[255])(t_obj *obj, FILE *file) =
{
	[OBJ_SPHERE] = ft_save_sphere,
	[OBJ_CYL] = ft_save_cylinder,
	[OBJ_CONE] = ft_save_cone,
	[OBJ_PLANE] = ft_save_plane,
	[OBJ_TRI] = ft_save_triangle,
	[OBJ_SQUARE] = ft_save_square,
	[OBJ_TORUS] = ft_save_torus
};

void			save_xml(t_env *e, char *base)
{
	FILE	*file_xml;
	t_obj	*obj;
	char	*name_xml;

	name_xml = PRE("./scenes/", POST(ft_strdup(base), ".xml"));
	if (!(file_xml = fopen(name_xml, "wb")))
	{
		perror("fopen");
		return ;
	}
	printf("XML - TRYING TO OPEN %s : %p\n", name_xml, file_xml);
	ft_save_camera(&e->camera, file_xml);
	fprintf(file_xml, "</camera>\n\n");
	obj = e->objects;
	while (obj)
	{
		g_print_obj[e->objects->type](obj, file_xml);
		fprintf(file_xml, "</object>\n\n");
		obj = obj->next;
	}
	fclose(file_xml);
}

void			write_image(t_env *e, FILE *file)
{
	int			x;
	int			y;
	t_vector	color;

	fprintf(file, "P3\n%d %d\n255\n", (int)F_WIDTH, (int)F_HEIGHT);
	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			color = g_buffer[x * (int)F_HEIGHT + y];
			fprintf(file, "%d %d %d\n", (int)color.x / e->sum,
				(int)color.y / e->sum, (int)color.z / e->sum);
		}
	}
}

void			save_img(t_env *e, char *base)
{
	FILE	*file_img;
	char	*name_ppm;
	char	*name_png;
	char	*sys;

	name_ppm = PRE("./images/", POST(ft_strdup(base), ".ppm"));
	name_png = PRE("./images/", POST(base, ".png"));
	if ((file_img = fopen(name_ppm, "wb")) < 0)
	{
		perror("open");
		return ;
	}
	printf("IMG - TRYING TO OPEN %s : %p\n", name_ppm, (void *)file_img);
	write_image(e, file_img);
	asprintf(&sys, "sips -s format png %s --out %s >&- \
&& rm %s && echo \"File successfully saved.\"",
	name_ppm, name_png, name_ppm);
	system(sys);
	free(sys);
	sys = NULL;
}

void			save_scene(t_env *e)
{
	int		folder;
	char	*base_name;

	folder = mkdir("./scenes/", 0700);
	folder = mkdir("./images/", 0700);
	base_name = new_name();
	save_xml(e, base_name);
	save_img(e, base_name);
}
