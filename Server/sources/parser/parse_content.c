/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			parse_type(char *content)
{
	if (ft_strequ(content, "sphere"))
		return (OBJ_SPHERE);
	else if (ft_strequ(content, "plane"))
		return (OBJ_PLANE);
	else if (ft_strequ(content, "cylinder"))
		return (OBJ_CYL);
	else if (ft_strequ(content, "cone"))
		return (OBJ_CONE);
	else if (ft_strequ(content, "triangle"))
		return (OBJ_TRI);
	else if (ft_strequ(content, "square"))
		return (OBJ_SQUARE);
	else
		parse_error("Unknown type object.", NULL, content);
	return (-1);
}

t_vector	parse_origin(char *content)
{
	t_vector	v;
	char		**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		parse_error("Bad direction - origin", NULL, content);
	v.x = ft_atod(split[0]);
	v.y = ft_atod(split[1]);
	v.z = ft_atod(split[2]);
	ft_free_array(split);
	return (v);
}

t_vector	parse_direction(char *content)
{
	t_vector v;

	v = parse_origin(content);
	return (v);
}

double		parse_radius(char *content)
{
	double r;

	r = ft_atod(content);
	return (r * r);
}

double		parse_angle(char *content)
{
	double a;

	a = ft_atod(content);
	a = (a * M_PI) / (double)180.0;
	return (a);
}

t_vector	parse_color(char *content)
{
	t_vector	c;
	char		**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		parse_error("Bad color\n", NULL, content);
	c.x = ft_xtoi(split[0]) / (double)255.0;
	c.y = ft_xtoi(split[1]) / (double)255.0;
	c.z = ft_xtoi(split[2]) / (double)255.0;
	ft_free_array(split);
	return (c);
}

double		parse_double(char *content)
{
	double	d;

	d = ft_atod(content);
	return (d);
}

//static const t_texture_sources g_skybox_sources[] =
//{
//	{"appartment", "./textures/skybox/appartment.jpg"},
//	{"bar", "./textures/skybox/bar.jpg"},
//	//	{"bedroom", "./textures/skybox/bedroom.jpg"},
//	//	{"clouds", "./textures/skybox/clouds.jpg"},
//	//	{"fractale", "./textures/skybox/fractale.jpg"},
//	//	{"snow", "./textures/skybox/snow.jpg"},
//	//	{"universe", "./textures/skybox/universe.png"},
//	//	{"aurore", "./textures/skybox/aurore.jpg"},
//	//	{"Notre-Dame", "./textures/skybox/Notre-Dame.jpg"},
//	//	{"mountain", "./textures/skybox/mountain.jpg"},
//	//	{"galaxy", "./textures/skybox/galaxy.jpg"},
//	{NULL, NULL}
//};

void		parse_skybox(t_env *e, char *content)
{
	int	i;

	i = 0;
	while (g_skybox_sources[i].name)
	{
		if (ft_strequ(content, g_skybox_sources[i].name))
		{
			e->skybox_index = i;
			e->skybox = 1;
			break ;
		}
		i++;
	}
}

//static const t_texture_sources g_color_sources[] =
//{
//	{"earth", "./textures/color/earth.png"},
//	{"moon", "./textures/color/moon.jpg"},
//	{"mars", "./textures/color/mars.jpg"},
//	{"sun", "./textures/color/sun.jpg"},
//	// {"football", "./textures/color/football.jpg"},
//	// {"baseball", "./textures/color/baseball.jpeg"},
//	// {"brick1", "./textures/color/brick1.jpg"},
//	// {"floor1", "./textures/color/floor1.jpg"},
//	// {"floor2", "./textures/color/floor2.png"},
//	// {"Metal(31)", "./textures/color/Metal(31).jpg"},
//	// {"Metal(32)", "./textures/color/Metal(32).jpg"},
//	// {"Metal(33)", "./textures/color/Metal(33).jpg"},
//	// {"Metal(34)", "./textures/color/Metal(34).jpg"},
//	// {"Metal(35)", "./textures/color/Metal(35).jpg"},
//	// {"Metal(36)", "./textures/color/Metal(36).jpg"},
//	// {"pavement2", "./textures/color/pavement2.jpg"},
//	// {"pavement3", "./textures/color/pavement3.jpg"},
//	// {"punisher", "./textures/color/punisher.jpeg"},
//	// {"raytracer", "./textures/color/raytracer.png"},
//	// {"rayure", "./textures/color/rayure.jpeg"},
//	// {"stone1", "./textures/color/stone1.jpg"},
//	// {"stone2", "./textures/color/stone2.jpg"},
//	// {"stone3", "./textures/color/stone3.jpg"},
//	// {"stone4", "./textures/color/stone4.jpg"},
//	// {"stone5", "./textures/color/stone5.jpg"},
//	// {"stone6", "./textures/color/stone6.jpg"},
//	// {"wood5", "./textures/color/wood5.jpg"},
//	// {"zebra", "./textures/color/zebra.jpeg"},
//	{NULL, NULL}
//};

int	parse_texture(char *content)
{
	int i;

	i = 0;
	while (g_color_sources[i].name)
	{
		if (ft_strequ(content, g_color_sources[i].name))
			return (i);
		i++;
	}
	return (-1);
}

//static const t_texture_sources g_tsp_sources[] =
//{
//	{"earth", "./textures/transparency/earth.png"},
//	{"zebra", "./textures/transparency/zebra.jpeg"},
//	{NULL, NULL}
//};

int	parse_tsp(char *content)
{
	int i;

	i = 0;
	while (g_tsp_sources[i].name)
	{
		if (ft_strequ(content, g_tsp_sources[i].name))
			return (i);
		i++;
	}
	return (-1);
}

