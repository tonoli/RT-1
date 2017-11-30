#include "server.h"

int		server_socket;
int		client_socket;

unsigned long checksum(void *data, size_t len)
{
	unsigned char *c = (unsigned char *)data;
	unsigned long total = 5381;

	size_t i = 0;
	while (i < len)
	{
		total = ((total << 5) + total) + *c;
		c++;
		i++;
	}
	return (total);
}

void	quit(int sig)
{
	close(client_socket);
	close(server_socket);
	exit(EXIT_SUCCESS);
}

void	*loop(void *data)
{
	int 	cs = (int)data;
	char	buffer[100];

	while (1)
	{
		sprintf(buffer, "Sending on CS %3d\n           ", cs);
		if (send(cs, buffer, strlen(buffer), 0) == -1)
		{
//			perror("send");
//			exit(EXIT_FAILURE);
		}
		ft_printf("Still connected to %d\n", cs);
	}
}

int		get_port(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			return (ft_atoi(argv[i + 1]));
		i++;
	}
	ft_dprintf(2, "Please provide a port argument -p <port>\n");
	exit(EXIT_FAILURE);
	return (-1);
}

char	*get_scene(int argc, char **argv)
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

int		get_options(t_env *e, int argc, char **argv)
{
	int port;

	port = get_port(argc, argv);
	e->scene_file = get_scene(argc, argv);
	if (!e->scene_file)
		random_spheres(e);
	else
		parser(e);
	return (port);
}

int main(int argc, char **argv)
{
	ft_printf("server\n");

	t_env *e = (t_env *)ft_memalloc(sizeof(t_env));
	init_render_env(e);

	int port;

	port = get_options(e, argc, argv);

	ft_printf("PORT : %d\n", port);
	ft_printf("SCENE : %s\n", e->scene_file);

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

	socklen_t			cslen;
	struct sockaddr		csin;

	ft_printf("Waiting for client...\n");
	cslen = sizeof(csin);
	if ((client_socket = accept(server_socket, (struct sockaddr *)&csin, &cslen)) < 0)
	{
		perror("Client socket\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Connected\nSending env...\n");

	struct timeval	start;
	struct timeval	end;
	int				total_send = 0;

	gettimeofday(&start, NULL);

	//ENV E
	send(client_socket, (void *)e, sizeof(t_env), 0);
	total_send += sizeof(t_env);

	//OBJECTS
	obj = e->objects;

	while (obj)
	{
		send(client_socket, (void *)obj, sizeof(t_obj), 0);
		total_send += sizeof(t_obj);
		obj = obj->next;
	}

	gettimeofday(&end, NULL);

	double delta = 0;
	delta = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
	delta += (end.tv_usec - start.tv_usec) / 1000.0;   // us to ms

	printf("%f kilobytes sent over %f seconds\n", total_send / 1024.0, delta / 1000.0);

	unsigned long checksum_total = 0;

	checksum_total += checksum((void *)e, sizeof(t_env));

	obj = e->objects;
	while (obj)
	{
		checksum_total += checksum((void *)obj, sizeof(t_obj));
		obj = obj->next;
	}

	printf("Checksum for total sync objects : %lx\n", checksum_total);

	close(client_socket);
	close(server_socket);
}
