#include "server.h"

int		server_socket;

void quit(int sig)
{
	close(server_socket);
	exit(0);
}

void *loop(void *data)
{
	int cs = (int)data;

	while(1)
	{
		char buffer[100];
		sprintf(buffer, "Sending on CS %3d\n           ", cs);
		if (send(cs, buffer, strlen(buffer), 0) == -1)
		{
			//			perror("send");
			//			exit(EXIT_FAILURE);
		}
		printf("Still connected to %d\n", cs);
	}
}

int main(int argc, char **argv)
{
	ft_printf("server\n");

	t_env *e = (t_env *)ft_memalloc(sizeof(t_env));
	init_render_env(e);
	if (argc == 2)
	{
		e->scene_file = argv[1];
		parser(e);
	}
	else
		random_spheres(e);
	ft_printf("server initialised\n");

	/////////////////////////////////
	t_obj *obj = e->objects;
	int	total = 0;
	int	total_spheres = 0, total_planes = 0, total_cylinders = 0, total_cones = 0;

	while (obj)
	{
		(obj->type == OBJ_SPHERE) ? total_spheres++ : 0;
		(obj->type == OBJ_CONE) ? total_cones++ : 0;
		(obj->type == OBJ_CYL) ? total_cylinders++ : 0;
		(obj->type == OBJ_PLANE) ? total_planes++ : 0;
		total++;
		obj = obj->next;
	}

	ft_printf("%d objects loaded :\n", total);
	ft_printf(" - %d spheres\n", total_spheres);
	ft_printf(" - %d cones\n", total_cones);
	ft_printf(" - %d cylinders\n", total_cylinders);
	ft_printf(" - %d planes\n", total_planes);

	e->object_count = total;
	/////////////////////////////////


	int 				port = ft_atoi("1338");
	struct sockaddr_in	address;

	signal(SIGINT, quit);
	signal(SIGPIPE, quit);

	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Create server_socket");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if (listen(server_socket, 42) < 0)
	{
		perror("listen\n");
		exit(EXIT_FAILURE);
	}

	unsigned int		cslen;
	struct sockaddr		csin;
	int					cs;

	printf("Waiting for client...\n");
	cslen = sizeof(csin);
	if ((cs = accept(server_socket, (struct sockaddr *)&csin, &cslen)) < 0)
	{
		perror("Client socket\n");
	}
	printf("Connected\nSending env...\n");

	//ENV E
	send(cs, (void *)e, sizeof(t_env), 0);
//	send(cs, NULL, 0, 0);

//	//OBJECTS
//	obj = e->objects;
//
//	while (obj)
//	{
//		printf("Sending object...\n");
//		send(cs, (void *)obj, sizeof(t_obj), 0);
//		obj = obj->next;
//	}

	close(cs);
	close(server_socket);
}
