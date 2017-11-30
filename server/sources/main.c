#include "server.h"

int			g_srv_socket;
int			g_port;
t_vector	*g_buffer;
t_env		*g_e;

//////////////////////////// QUIT ////////////////////////////////////

void	quit(int sig)
{
	(void)sig;
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

//////////////////////////////////// MAIN /////////////////////////////////

void *loop(void *data)
{
	t_env *e = g_e;
	int cs = (int) data;

	while (1)
	{
		/////////////////////////////////
		t_obj *obj = g_e->objects;
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

		sync_env_obj(g_e, cs);
		sync_buffer(cs);
		display_buffer(g_e);
		g_e->sum++;
	}

	//conected to socket
	return (NULL);
}

void *wait_client(void)
{
	pthread_t	t;
	int cs;

	while (1)
	{
		cs = connect_to_client();
		pthread_create(&t, NULL, loop, cs);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_env 		*e;
	pthread_t	t;

	g_e = (t_env *)ft_memalloc(sizeof(t_env));
	e = g_e;
	g_buffer = (t_vector *)ft_memalloc(sizeof(t_vector) * F_WIDTH * F_HEIGHT);
	init_render_env(e);
	get_options(e, argc, argv);

	init_master_socket();

	SDL_Init(SDL_INIT_VIDEO);
	if (!(e->win = SDL_CreateWindow("RayTracer Server", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, F_WIDTH, F_HEIGHT, 0)))
		custom_quit("SDL Create Window");
	e->s_background = SDL_GetWindowSurface(e->win);

	pthread_create(&t, NULL, wait_client, NULL);

	while (1)
	{
		SDL_UpdateWindowSurface(e->win);
		SDL_PollEvent(&e->event);
	}
}
