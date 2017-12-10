/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_clu_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:19:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 02:40:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_clu_structs_h
# define rt_clu_structs_h

typedef struct	s_mem
{
	//SKYBOX
	SDL_Surface		*s_skybox[12];
	SDL_Surface		*current_skybox;
	int				skybox_index;
	int				skybox_total;

	//OBJ COLOR TEXTURES
	SDL_Surface		*s_obj_tx[30];
	int				obj_tx_total;

	//TRANSPARENCY TEXTURES
	SDL_Surface		*s_tsp_tx[3];
	int				tsp_tx_total;
}				t_mem;

typedef struct 	s_texture_sources
{
	char		*name;
	char		*file_address;
}				t_texture_sources;

typedef	struct	s_xml
{
	int			tag;
	char		*value;
}				t_xml;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	ori;
	t_vector	dir;
}				t_ray;

typedef struct	s_cone_coef
{
	double		dot_a;
	t_vector	sca_a;
	t_vector	sub_a;
	double		dot_b;
	t_vector	sca_b;
	t_vector	sub_b;
	double		csq;
	double		ssq;
}				t_cone_coef;

typedef struct	s_obj
{
	int				type;
	t_vector		ori;
	t_vector		dir;
	t_vector		dir2;
	t_vector		dir3;
	double			len1;
	double			len2;
	double			len3;
	double			radius;
	double			small_r;
	double			height;
	int				reflection;
	double			refraction;
	double			marblesize;
	t_vector		color_backup;
	t_vector		marblecolor;
	int				damier;
	t_vector		damier1;
	t_vector		damier2;
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			t;
	double			u;
	double			v;
	double			t1;
	double			t2;
	t_vector		color;
	t_vector		cross;
	double			cross_distance;
	t_vector		normal;
	double			fuzz;
	int				emit;
	double			light;

	char			*tx_selected;
	SDL_Surface		*current_texture;
	int				texture_index;

	char			*tsp_selected;
	SDL_Surface		*current_tsp;
	int				tsp_index;

	struct s_obj	*next;
}				t_obj;

typedef struct	s_env
{
	SDL_Event     	event;
	SDL_Cursor		*cursor;
	SDL_Window		*win;
	SDL_Surface		*s_background;
	SDL_Surface		*w_icon;
	SDL_Surface		*s_tmp;
	SDL_Surface		*s_t2;
	SDL_Surface		*s_ui;
	SDL_Surface		*s_loader;
	SDL_Surface		*s_slave;
	SDL_Surface		*s_credit;
	SDL_Surface		*s_title;
	SDL_Surface		*s_raytracer;
	TTF_Font		**font;
	SDL_Rect		b_rect[10];
	SDL_Rect		bt_rect[9];
	SDL_Rect		i_rect[10];
	SDL_Rect		it_rect[18];
	SDL_Rect		topin_rect[3];
	SDL_Rect		tt_rect[3];
	SDL_Rect		help_rect;
	SDL_Rect		credit_rect;
	SDL_Point		mouse;
	void	        *img;
	int		        *img_data;
	void	        *gui;
	int		        *gui_data;
	int		        win_w;
	int		        win_h;
	int		        x;
	int		        y;
	int				slave;

	//Text
	char			txt[24][10000];

	//Segment
	char			loader;
	char			render;
	char			helper;
	char			live;

	//Buttons
	char			b_actif;
	char			i_actif;
	char			it_actif;
	char			help_actif;
	char			credit_actif;
	char			bt_actif;
	char			topin_actif;
	char			run;

	//TOP Rebond + Move + Rotate
	double			rebond;
	double			move_speed;
	double			rot_speed;
	//LIVE PREVIEW
	int				increment;
	int				reset;

	//MULTITHREADING
	int				threads;
	int				i;
	int				sum;

	//PARSER
	char			*scene_file;
	char			*input;

	//MAIN STORAGE DATA
	int				**frame_array;
	t_vector		**color_array;
	t_obj			camera;
	t_obj			*objects;
	int				lock;

	//CALCULUS
	t_obj			*avoid;
	double			t_min;
	double			t_max;
	double			ni_nt;
	int				depth;
	int				recursion;

	//LIVE EDITION
	t_obj			*selected;

	//PERLIN NOISE
	t_vector		ranvec[256];
	double			randouble[256];
	int				perm_x[256];
	int				perm_y[256];
	int				perm_z[256];

	//Filter
	int				filter;

	//SKYDIFFUSE
	double			vpos;

	//SKYBOX TEXTURES
	int				skybox;
	SDL_Surface		*s_skybox[12];
	SDL_Surface		*current_skybox;
	int				skybox_index;
	int				skybox_total;

	//OBJECTS TEXTURES
	SDL_Surface		*s_obj_tx[30];
	int				obj_tx_total;

	//TRANSPARENCY TEXTURES
	SDL_Surface		*s_tsp_tx[3];
	int				tsp_tx_total;

	//Transaction checkup
	unsigned int	magic;
	int				object_count;

	//Clients Clustering
	int				nb_cli;
	int				local_compute;
	pid_t			child;
}				t_env;

typedef struct		s_quartic
{
	double  		coeffs[4];
	double  		z;
	double			u;
	double			v;
	double			sub;
	double  		A;
	double			B;
	double			C;
	double			D;
	double 			sq_A;
	double			p;
	double			q;
	double			r;
	int    			i;
	int				num;
}					t_quartic;

typedef struct		s_cubic
{
	int				i;
	int				num;
	double			sub;
	double			A;
	double			B;
	double			C;
	double			sq_A;
	double			p;
	double			q;
	double			cb_p;
	double			D;
}					t_cubic;

typedef struct		s_quadric
{
	double			p;
	double			q;
	double			D;
}					t_quadric;

typedef struct		s_window
{
	SDL_Event     	event;
	int				activate;
	SDL_Window		*win;
	SDL_Surface		*s_background;
}					t_window;

typedef	struct		s_perlin
{
	int				i;
	int				j;
	int				k;
	double			u;
	double			v;
	double			w;
	double			uu;
	double			vv;
	double			ww;
	double			accum;
	t_vector		weight;
}					t_perlin;

#endif
