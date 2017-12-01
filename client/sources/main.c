/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:51:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 02:51:04 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			g_cli_socket;
char		*g_address;
int			g_port;
int			*g_buffer;
int			**g_frame_array;
t_vector	**g_color_array;
t_mem		g_mem;

void	loop(t_env *e)
{
	while (42)
	{
		sync_env(e);
		sync_objects(e, NULL);
		draw_screen(e);
		sync_buffer(e);
		release_obj(e);
	}
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 3 || !ft_str_is_number(argv[2]))
	{
		ft_printf("./client <addr> <port>\n");
		exit(EXIT_FAILURE);
	}
	g_port = ft_atoi(argv[2]);
	g_address = argv[1];
	connect_to_server();
	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_globals();
	init_skyboxes_tx_sources(e);
	init_color_tx_sources(e);
	init_transparency_tx_sources(e);
	loop(e);
}
