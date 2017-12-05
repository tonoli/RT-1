/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_clu.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:47:25 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 20:05:24 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_clu_h
# define rt_clu_h

# include <math.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <signal.h>

# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"

# include "libft.h"
# include "rt_clu_structs.h"

# define WIN_W				1303
# define WIN_H				733
# define MID_W      		640
# define MID_H      		360

# define MOUSE				1
# define CLICK 				2

# define INCREASE			1
# define DECREASE			2

# define F_WIDTH			(double)1024
# define F_HEIGHT			(double)648
# define FOV				60

# define OBJ_UNDEF			0
# define OBJ_SPHERE			1
# define OBJ_PLANE			2
# define OBJ_CYL			3
# define OBJ_CONE			4

# define MOVE_SPEED			(double)10.0
# define ROT_SPEED			(double)0.1
# define PITCH				e->camera.dir.y
# define YAW				e->camera.dir.x

# define _A					(0xff000000)
# define _R					(0x00ff0000)
# define _G					(0x0000ff00)
# define _B					(0x000000ff)

# define MAGIC				(0xBAADA555)

# define TOTAL_SKYBOX		12
# define TOTAL_TX			5
# define TOTAL_TSP			1


/*
**	PRIMITIVES
*/

double		get_distance(t_env *e, t_obj *obj, t_ray ray);
double		hit_sphere(t_env *e, t_obj *obj, t_ray ray);
double		hit_plane(t_env *e, t_obj *obj, t_ray ray);
double		hit_cyl(t_env *e, t_obj *obj, t_ray ray);
double		hit_cone(t_env *e, t_obj *obj, t_ray ray);

/*
**	LIBVECTOR
*/

t_vector	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector	vector_cross(t_vector a, t_vector b);
t_vector	vector_mul(t_vector a, t_vector b);
t_vector	vector_negative(t_vector a);
double		vector_dot(t_vector a, t_vector b);
double		vector_cos_angle(t_vector a, t_vector b);
double		vector_angle(t_vector a, t_vector b);
double		vector_magnitude(t_vector v);
t_vector	vector_scale(t_vector a, double scale);
t_vector	vector_factor(t_vector a, double factor, t_vector b);
t_vector	vector_new(double x, double y, double z);
t_vector	vector_normalize(t_vector a);
t_vector	vector_normal(t_env *e, t_obj *closest_obj, t_ray ray);
t_vector	normal_sphere(t_obj *closest_obj);
t_vector	normal_cone(t_obj *closest_obj);
t_vector	normal_plane(t_obj *closest_obj, t_ray ray);
t_vector	normal_cyl(t_obj *closest_obj);

#endif
