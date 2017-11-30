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
