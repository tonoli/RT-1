/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:59:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/04 23:01:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			g_srv_socket;
int			g_port;
t_vector	*g_buffer;
t_env		*g_e;

void	*loop(void *data)
{
	int		cs;
	t_env	*e;
	t_obj	*obj;

	e = g_e;
	cs = (int)data;
	while (42)
	{
		obj = e->objects;
		e->object_count = 0;
		while (obj)
		{
			e->object_count++;
			obj = obj->next;
		}
		sync_env_obj(e, cs);
		sync_buffer(cs, e);
		display_buffer(e);
	}
	return (NULL);
}

void	*wait_client(void *data)
{
	pthread_t	t;
	int64_t		cs;

	while (42)
	{
		cs = connect_to_client();
		pthread_create(&t, NULL, loop, (void *)cs);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_env		*e;
	pthread_t	t;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_render_env(e);

	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_TORUS;
	obj->ori = (t_vector){0, -5 -10};
	obj->dir = (t_vector){0, 1, 0};
	obj->color = (t_vector){1, 0, 0};
	obj->color_backup = obj->color;
	obj->big_r = 10;
	obj->small_r = 1;
	obj_push_back(&e->objects, obj);

	get_options(e, argc, argv);
	init_globals(e);
	init_master_socket();
	if (pthread_create(&t, NULL, wait_client, NULL))
		fatal_quit("pthread_create");
	start_interface(e);
}
