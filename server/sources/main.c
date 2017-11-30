#include "server.h"

int		g_srv_socket;
int		g_cli_socket;
int		g_port;
int		*g_buffer;

//////////////////////////// QUIT ////////////////////////////////////

void	quit(int sig)
{
	(void)sig;
	close(g_cli_socket);
	close(g_srv_socket);
	exit(EXIT_SUCCESS);
}

void	fatal_quit(char *msg)
{
	perror(msg);
	quit(0);
}

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "Fatal error : %s\n", msg);
	quit(0);
}

/////////////////////////// ARGUMENTS //////////////////////////////

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

void	get_options(t_env *e, int argc, char **argv)
{
	g_port = get_port(argc, argv);
	e->scene_file = get_scene(argc, argv);
	if (!e->scene_file)
		random_spheres(e);
	else
		parser(e);
}


//////////////////////////// SYNC ///////////////////////////////////

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

/////////////////////////// DISPLAY ///////////////////////////////////////

void	copy_image_to_sdl(SDL_Surface *win, int *image)
{
	short	x;
	short	y;

	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			*((unsigned *)(win->pixels + y * win->pitch + x * win->format->BytesPerPixel)) = image[x * (int)F_HEIGHT + y];
		}
	}
	printf("created rect\n");
}


void	display_buffer(t_env *e)
{
	ft_printf("Displaying buffer image\n");

	SDL_Init(SDL_INIT_VIDEO);
	if (!(e->win = SDL_CreateWindow("RayTracer Server", SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED, F_WIDTH, F_HEIGHT, 0)))
		custom_quit("SDL Create Window");
	e->s_background = SDL_GetWindowSurface(e->win);
	copy_image_to_sdl(e->s_background, g_buffer);
	while (1)
	{
		SDL_UpdateWindowSurface(e->win);
		if (SDL_PollEvent(&e->event))
			;
	}
}

//////////////////////////////////// MAIN /////////////////////////////////

int main(int argc, char **argv)
{
	t_env *e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	g_buffer = (int *)ft_memalloc(sizeof(int) * F_WIDTH * F_HEIGHT);
	init_render_env(e);
	get_options(e, argc, argv);

	/////////////////////////////////
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

	e->object_count = total;
	/////////////////////////////////

	init_master_socket();
	g_cli_socket = connect_to_client();
	sync_env_obj(e);
	sync_buffer();
	display_buffer(e);
}
