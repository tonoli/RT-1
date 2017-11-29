#ifndef server_h
# define server_h

# include "rt_clu.h"

/*
**	MISCELANEOUS
*/

double		randb(void);
//t_vector	random_unit_sphere(void);
//t_vector	adjust_color(t_vector c);
//t_vector	diffuse_sky(t_env *e, double t);
//void		damier(t_obj *closest_obj);

/*
**	INIT
*/

void		init_render_env(t_env *e);
//void		init_skyboxes_tx_sources(t_env *e);
//void		init_color_tx_sources(t_env *e);
//void		init_transparency_tx_sources(t_env *e);

/*
**	MARBLE
*/

void		marble(t_env *e, t_vector *color, t_obj *closest_obj);
double		noise(t_env *e, t_vector cross);
double		turb(t_env *e, t_vector cross);
void		perlin_generate(t_env *e);
void		perlin_generate_perm(int *);

/*
**	PARSER
*/

void		random_spheres(t_env *e);
t_obj		*new_obj(void);
void		obj_push_back(t_obj **list, t_obj *cur);
void		parse_error(char *msg, char *tag, char *content);
void		parser(t_env *e);
void		get_input(t_env *e);
void		remove_ws(char **str);
char		*get_xml_tag(char *line, char **ptr, char **tag);
char		*get_xml_opening_tag(char *line);
char		*get_xml_closing_tag(char *line);
char		*closing_tag(char *opening);
void		parse_object(t_env *e, t_obj *obj, char *object_tag, char *line);
void		parse_camera(t_env *e, char *object_tag, char *line);
t_vector	parse_origin(char *content);
double		parse_radius(char *content);
t_vector	parse_color(char *content);
double		parse_angle(char *content);
int			parse_type(char *content);
t_vector	parse_direction(char *content);
double		parse_double(char *content);
void   		parse_skybox(t_env *e, char *content);

#endif
