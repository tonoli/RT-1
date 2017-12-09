/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:05:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 17:53:30 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			is_mouse_in_rect(t_env *e, SDL_Rect *rect, int rect_len)
{
	int i;

	i = -1;
	while (++i < rect_len)
	{
		if (SDL_PointInRect(&e->mouse, &rect[i]))
			return i;
	}
	return -1;
}


static void (*g_left_btn[])(t_env *e) =
{
	create_sphere,
	create_cylinder,
	create_plane,
	create_torus,
	create_cone,
	create_cube,
	atom,
	dna,
	cube_with_spheres
};

void		is_mouse_in_rect_left(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->b_rect, 10);
	draw_all_button_left(e, 0);
	if (btn_i != -1)
	{
		state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : MOUSE;
		e->b_actif = (state == CLICK) ? btn_i : e->b_actif;
		draw_button_left(e, btn_i, state);
		if (state == CLICK)
		{
			set_live_edition_mode(e);
			g_left_btn[btn_i](e);
		}
	}

}

// input big boxes in the right
void		is_mouse_in_rect_right(t_env *e)
{
	int state;
	int btn_i;
	int btn_in;

	btn_i = is_mouse_in_rect(e, e->i_rect, 10);
	if (btn_i != -1)
	{
		if (btn_i != e->i_actif)
		{
			state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : 0;
			if (state == CLICK)
			{
				draw_input(e, e->i_actif, 0);
				e->i_actif = btn_i;
				e->it_actif = -1;
				draw_input(e, btn_i, state);
				//set_live_edition_mode(e);
			}
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			btn_in = is_mouse_in_rect(e, e->it_rect, 18);
			if (e->i_actif != (btn_in / 3) + 4)
			{
				draw_input(e, btn_i, 0);
				e->i_actif = -1;
				e->it_actif = -1;
			}
		}
	}
}

// input text boxes in the right
void		is_mouse_in_it_right(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->it_rect, 18);
	if (btn_i != -1 && btn_i > 5)
	{
		if (e->i_actif == (btn_i / 3) + 4)
		{
			state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : 0;
			if (state == CLICK)
			{
				e->it_actif = btn_i;
				printf("C'est beau la vie dans btn_i = %d\n", btn_i);
			}
		}
	}
}

void void_unused(t_env *e)
{

}

static void (*g_top_btn[])(t_env *e) =
{
	light_object,
	marble_object,
	switch_obj_tx,
	switch_tsp_tx,
	delete_object,
	switch_skybox,
	switch_filter,
	//save_scene,
	void_unused,
	set_render_edition_mode,
};

void		is_mouse_in_rect_top(t_env *e)
{
	int state;
	int btn_i;

	draw_all_button_top(e, 0);
	btn_i = is_mouse_in_rect(e, e->bt_rect, 9);
	if (btn_i != -1)
	{
		state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : MOUSE;
		draw_button_top(e, btn_i, state);
		if (state == CLICK)
		{
			if (btn_i != 7)
				set_live_edition_mode(e);
			g_top_btn[btn_i](e);
		}
	}
}

void		is_mouse_in_rect_top_input(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->topin_rect, 3);
	if (btn_i != -1)
	{
		if (btn_i != e->topin_actif)
		{
			state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : 0;
			if (state == CLICK)
			{
				draw_input_top(e, e->topin_actif, 0);
				e->topin_actif = btn_i;
				draw_input_top(e, btn_i, state);
			}
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			draw_input_top(e, btn_i, 0);
			e->topin_actif = -1;
		}
	}
}
