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

void	sync_env_obj(t_env *e, int cs)
{
	t_obj	*obj;

	if (send(cs, (void *)e, sizeof(t_env), 0) < 0)
		fatal_quit("send");
	obj = e->objects;
	while (obj)
	{
		if (send(cs, (void *)obj, sizeof(t_obj), 0) < 0)
			fatal_quit("send");
		obj = obj->next;
	}
}

void	sync_buffer(int cs)
{
	ssize_t r;
	ssize_t os;
	int		*local_buffer;

	local_buffer = (int *)ft_memalloc(sizeof(int) * F_WIDTH * F_HEIGHT);
	ft_printf("Receiving image buffer\n");
	os = 0;
	while (os < (sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT))
	{
		r = recv(cs, (void *)local_buffer + os,
				 (sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT) - os, 0);
		if (r == -1)
			fatal_quit("recv");
		os += r;
	}

	short	x;
	short	y;
	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			int color = local_buffer[x * (int)F_HEIGHT + y];

			g_buffer[x * (int)F_HEIGHT + y].x += (color >> 16) & 255;
			g_buffer[x * (int)F_HEIGHT + y].y += (color >> 8) & 255;
			g_buffer[x * (int)F_HEIGHT + y].z += color & 255;
		}
	}
	free(local_buffer);
	local_buffer = NULL;
}

