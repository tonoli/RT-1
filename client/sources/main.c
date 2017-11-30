#include "client.h"

int		g_cli_socket;
char	*g_address;
int		g_port;
int		*g_buffer;

////////////////////////// QUIT ////////////////////////////////////

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "Fatal error : %s\n", msg);
	exit(EXIT_FAILURE);
}

void	fatal_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

////////////////////////// BUFFER //////////////////////////////////

void	buffer_set_color(int *buffer, int color)
{
	int i;

	i = -1;
	while (++i < (int)(F_WIDTH * F_HEIGHT))
		buffer[i] = color;
}

////////////////////////// SYNC //////////////////////////////////////

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

	buffer_set_color(g_buffer, 0xFF00FF00);
	ft_printf("Sending back image buffer\n");
	r = send(g_cli_socket, g_buffer, sizeof(int) * F_WIDTH * F_HEIGHT, 0);
	if (r == -1)
		fatal_quit("send buffer");
	ft_printf("Image sent\n");
}

/////////////////////////// MAIN //////////////////////////////////

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("./client <addr> <port>\n");
		exit(EXIT_FAILURE);
	}

	t_env	*e;

	g_port = ft_atoi(argv[2]);
	g_address = argv[1];
	connect_to_server();
	e = (t_env *)ft_memalloc(sizeof(t_env));
	g_buffer = (int *)ft_memalloc(sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT);
	sync_env(e);
	sync_objects(e);
	
	////////// OBJ STATS ///////////
	t_obj *obj = e->objects;
	int	total = 0;
	int	total_spheres = 0;
	int total_planes = 0;
	int total_cylinders = 0;
	int total_cones = 0;

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
	/////////////////////////////////

	sync_buffer();
}

