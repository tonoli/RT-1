#ifndef client_h
# define client_h

# include "rt_clu.h"

# ifndef GLOBAL_CLI
#  define GLOBAL_CLI

extern int		g_cli_socket;
extern char		*g_address;
extern int		g_port;
extern int		*g_buffer;

# endif

/*
**	MAIN
*/

void		custom_quit(char *msg);
void		fatal_quit(char *msg);

/*
**	CONNEXION
*/

void		connect_to_server(void);
void		sync_env(t_env *e);
void		sync_objects(t_env *e);
void		sync_buffer(void);

/*
**	OBJECT ADD
*/

t_obj		*new_obj(void);
void		obj_push_back(t_obj **list, t_obj *cur);

/*
**	MISCELANEOUS
*/

double		randb(void);
t_vector	random_unit_sphere(void);
t_vector	adjust_color(t_vector c);
t_vector	diffuse_sky(t_env *e, double t);
void		damier(t_obj *closest_obj);

/*
**	DISPLAY
*/

void		reset_screen(t_env *e);
void		draw_screen(t_env *e);
void		*compute_block(void *data);
t_ray		cam_ray(t_env *e, double i, double j, double ratio);
void		init_copy(t_env *e, t_env *copy, int i);
void		release_copy(t_env **copy);

/*
**	CALCULUS
*/

t_vector	compute_objects(t_env *e, t_ray ray);
t_vector	reflection(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	refraction(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	diffuse(t_env *e, t_ray ray, t_obj *closest_obj);


/*
**	PRIMITIVES
*/

double		get_distance(t_env *e, t_obj *obj, t_ray ray);
double		hit_sphere(t_env *e, t_obj *obj, t_ray ray);
double		hit_plane(t_env *e, t_obj *obj, t_ray ray);
double		hit_cyl(t_env *e, t_obj *obj, t_ray ray);
double		hit_cone(t_env *e, t_obj *obj, t_ray ray);

/*
**	MARBLE
*/

void		marble(t_env *e, t_vector *color, t_obj *closest_obj);
double		noise(t_env *e, t_vector cross);
double		turb(t_env *e, t_vector cross);
void		perlin_generate(t_env *e);
void		perlin_generate_perm(int *);

#endif
