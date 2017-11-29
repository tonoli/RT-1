#include "client.h"

int main(int argc,char **argv)
{
	ft_printf("client\n");

	if (argc != 3)
	{
		ft_printf("./client <addr> <port>\n");
		exit(EXIT_FAILURE);
	}

	int		port = ft_atoi(argv[2]);
	char	*addr = argv[1];
	int		client_socket;
	struct	sockaddr_in address;
	int 	valread;

	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("Create client_socket");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	inet_pton(AF_INET, addr, (void *)&address.sin_addr);
	address.sin_port = htons(port);

	if (connect(client_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}

	ft_printf("Connected to server\nWaiting for struct env.\n");

	t_env *e = (t_env *)ft_memalloc(sizeof(t_env));

	valread = recv(client_socket, (void *)e, sizeof(t_env), 0);

	if (valread == -1)
	{
		perror("recv");
		exit(EXIT_FAILURE);
	}
	else if (valread != sizeof(t_env))
	{
		ft_dprintf(2, "Invalid data received t_env: [%d] vs data: [%d]\n", sizeof(t_env), valread);
	 	exit(EXIT_FAILURE);
	}

	if (e->magic != MAGIC)
	{
		ft_printf("Corrupted env data received\n");
		exit(EXIT_FAILURE);
	}

	ft_printf("Received data env magic: [%#lX]\n", e->magic);
	ft_printf("Object to sync : %d\n", e->object_count);

	e->objects = NULL;

	int i = 0;
	t_obj *obj = NULL;

	while (i < e->object_count)
	{
		obj = new_obj();
		valread = recv(client_socket, (void *)obj, sizeof(t_obj), 0);
		obj->next = NULL;
		obj_push_back(&e->objects, obj);
		i++;
	}


	/////////////////////////////////
	obj = e->objects;
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
}
