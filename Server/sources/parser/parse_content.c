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
	else if (ft_strequ(content, "torus"))
		return (OBJ_TORUS);
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

int		parse_filter(char *content)
{
	if (ft_strequ(content, "sepia"))
		return (1);
	if (ft_strequ(content, "greyscale"))
		return (2);
	if (ft_strequ(content, "negative"))
		return (3);
	return (0);
}
