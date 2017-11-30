#include "client.h"

void	connect_to_server(void)
{
	struct	sockaddr_in address;

	ft_printf("Connecting to server\n");
	if ((g_cli_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		fatal_quit("Create client_socket");
	address.sin_family = AF_INET;
	inet_pton(AF_INET, g_address, (void *)&address.sin_addr);
	address.sin_port = htons(g_port);
	if (connect(g_cli_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
		fatal_quit("connect");
	ft_printf("Connected to server\n");
}

void	sync_env(t_env *e)
{
	ssize_t	r;
	ssize_t	os;

	ft_printf("Waiting for struct env.\n");
	os = 0;
	while (os < sizeof(t_env))
	{
		r = recv(g_cli_socket, (void *)e + os, sizeof(t_env) - os, 0);
		if (r == -1)
			fatal_quit("recv env structure");
		os += r;
	}
	if (e->magic != MAGIC)
		custom_quit("Corrupted env data received. Invalid magic.");
}

void	sync_objects(t_env *e)
{
	ssize_t	r;
	ssize_t	os;
	int 	i;
	t_obj	*obj;

	e->objects = NULL;
	obj = NULL;
	i = -1;
	while (++i < e->object_count)
	{
		obj = new_obj();
		os = 0;
		while (os < sizeof(t_obj))
		{
			r = recv(g_cli_socket, (void *)obj + os, sizeof(t_obj) - os, 0);
			if (r == -1)
				fatal_quit("recv object structure");
			os += r;
		}
		obj->next = NULL;
		obj_push_back(&e->objects, obj);
	}
}

void	sync_buffer(void)
{
	ssize_t r;

	ft_printf("Sending back image buffer\n");
	r = send(g_cli_socket, g_buffer, sizeof(int) * F_WIDTH * F_HEIGHT, 0);
	if (r == -1)
		fatal_quit("send buffer");
	ft_printf("Image sent\n");
}
