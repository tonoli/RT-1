/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:05:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/05 18:37:38 by tdelmas          ###   ########.fr       */
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

///////////////////////////////////// LEFT ///////////////////////////////////

static void (*g_left_btn[])(t_env *e) =
{
	create_sphere,
	create_cylinder,
	create_plane,
	create_torus,
	create_cone,
	atom,
	dna,
	cube_with_spheres
};

void		is_mouse_in_rect_left(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->b_rect, 9);
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

void		is_mouse_in_rect_right(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->i_rect, 10);
	if (btn_i != -1)
	{
		if (btn_i != e->i_actif)
		{
			state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : 0;
			e->i_actif = (state == CLICK) ? btn_i : e->i_actif;
			draw_input(e, btn_i, state);
			if (state == CLICK)
			{
				set_live_edition_mode(e);
				//call
			}
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			draw_input(e, btn_i, 0);
			e->i_actif = -1;
		}
	}
}

static void (*g_top_btn[])(t_env *e) =
{
	light_object,
	marble_object,
	switch_obj_tx,
	save_scene,
	switch_skybox,
	switch_tsp_tx,
	delete_object,
	switch_filter,
	set_render_edition_mode
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
		printf("Just draw button %d at state %d\n", btn_i, state);
		if (state == CLICK)
		{
			set_live_edition_mode(e);
			g_top_btn[btn_i](e);
		}
	}
}

void		is_mouse_in_render(t_env *e)
{
	int i;
	int j;

	i = e->mouse.x;
	j = e->mouse.y;
	if (i > 82 && i < 82 + F_WIDTH && (j > 72 && j < 72 + F_WIDTH))
	{
		create_border(e, 1);
		select_obj(i - 82, j - 72, e);
	}
	else
	{
		create_border(e, 0);
	}
}

