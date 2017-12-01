/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:59:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 02:59:21 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			g_srv_socket;
int			g_port;
t_vector	*g_buffer;
t_env		*g_e;

void	set_mode(t_env *e)
{
	struct timeval	t;
	double			secs;

	gettimeofday(&t, NULL);
	secs = (double)(t.tv_usec - e->last_event.tv_usec) / (double)1000000.0;
	secs += (double)(t.tv_sec - e->last_event.tv_sec);
	gettimeofday(&t, NULL);
	if (secs > e->wait)
		keyboard(SDLK_f, e);
	else
		e->sum = 1;
}

void	*loop(void *data)
{
	int		cs;
	t_env	*e;
	t_obj	*obj;

	e = g_e;
	cs = (int)data;
	while (42)
	{
		set_mode(e);
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
	get_options(e, argc, argv);
	init_globals(e);
	init_master_socket();
	if (pthread_create(&t, NULL, wait_client, NULL))
		fatal_quit("pthread_create");
	start_interface(e);
}
