/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:12:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 21:26:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	get_port(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			return (ft_atoi(argv[i + 1]));
		i++;
	}
	ft_dprintf(2, "Please provide a port argument : -p <port>\n");
	exit(EXIT_FAILURE);
	return (-1);
}

static char	*get_scene(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			i += 2;
		else
			return (argv[i]);
	}
	return (NULL);
}

void		get_options(t_env *e, int argc, char **argv)
{
	g_port = get_port(argc, argv);
	e->scene_file = get_scene(argc, argv);
	if (!e->scene_file)
		random_spheres(e);
	else
		parser(e);
}
