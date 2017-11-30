#include "server.h"

void	init_master_socket(void)
{
	struct sockaddr_in	address;

	signal(SIGINT, quit);
	signal(SIGPIPE, quit);
	if ((g_srv_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fatal_quit("Create server_socket");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(g_port);
	if (bind(g_srv_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
		fatal_quit("bind");
	if (listen(g_srv_socket, 42) < 0)
		fatal_quit("listen");
}

int		connect_to_client(void)
{
	socklen_t			cslen;
	struct sockaddr		csin;
	int					cs;

	ft_printf("Waiting for client...\n");
	cslen = sizeof(csin);
	if ((cs = accept(g_srv_socket, (struct sockaddr *)&csin, &cslen)) < 0)
		fatal_quit("accept");
	ft_printf("Connected to client\n");
	return (cs);
}

void	sync_env_obj(t_env *e)
{
	t_obj	*obj;

	if (send(g_cli_socket, (void *)e, sizeof(t_env), 0) < 0)
		fatal_quit("send");
	obj = e->objects;
	while (obj)
	{
		if (send(g_cli_socket, (void *)obj, sizeof(t_obj), 0) < 0)
			fatal_quit("send");
		obj = obj->next;
	}
}

void	sync_buffer(void)
{
	ssize_t r;
	ssize_t os;

	ft_printf("Receiving image buffer\n");
	os = 0;
	while (os < (sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT))
	{
		r = recv(g_cli_socket, (void *)g_buffer + os,
				 (sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT) - os, 0);
		if (r == -1)
			fatal_quit("recv");
		os += r;
	}
}
