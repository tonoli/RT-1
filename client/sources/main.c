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


	/////////////////// CALCULUS ////////////////////
	e->color_array = (t_vector **)ft_memalloc(sizeof(t_vector *) * (F_HEIGHT + 1));
	e->frame_array = (int **)ft_memalloc(sizeof(t_vector *) * (F_HEIGHT + 1));
	int i = -1;
	while (++i < (int)F_HEIGHT)
	{
		e->color_array[i] = (t_vector *)ft_memalloc(sizeof(t_vector) * F_WIDTH);
		e->frame_array[i] = (int *)ft_memalloc(sizeof(int) * F_WIDTH);
	}

	draw_screen(e);
	/////////////////////////////////////////////////

	sync_buffer();
}

