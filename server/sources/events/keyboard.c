/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:12:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:31:01 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int g_key[] =
{
	SDLK_l,
//	SDLK_b,
	SDLK_n,
	SDLK_m,
	SDLK_p,
	SDLK_w,
	SDLK_a,
	SDLK_s,
	SDLK_d,
	SDLK_SPACE,
	SDLK_c,
	SDLK_LEFT,
	SDLK_RIGHT,
	SDLK_UP,
	SDLK_DOWN,
	SDLK_KP_MINUS,
	SDLK_KP_PLUS,
	SDLK_KP_8,
	SDLK_KP_4,
	SDLK_KP_6,
	SDLK_KP_2,
	0
};

static const int g_key_value[255] =
{
	['l'] = SDLK_l,
//	['b'] = SDLK_b,
	['n'] = SDLK_n,
	['m'] = SDLK_m,
	['p'] = SDLK_p,
	['w'] = SDLK_w,
	['a'] = SDLK_a,
	['s'] = SDLK_s,
	['d'] = SDLK_d,
	[' '] = SDLK_SPACE,
	['c'] = SDLK_c,
	[127 + 'l'] = SDLK_LEFT,
	[127 + 'r'] = SDLK_RIGHT,
	[127 + 'u'] = SDLK_UP,
	[127 + 'd'] = SDLK_DOWN,
	[127 + 'm'] = SDLK_KP_MINUS,
	[127 + 'p'] = SDLK_KP_PLUS,
	[127 + '8'] = SDLK_KP_8,
	[127 + '4'] = SDLK_KP_4,
	[127 + '6'] = SDLK_KP_6,
	[127 + '2'] = SDLK_KP_2
};

void	set_live_edition_mode(t_env *e)
{
	e->live = 1;
	e->increment = 4;
	e->recursion = 1;
	e->reset = 1;
}

void	set_render_edition_mode(t_env *e)
{
	e->live = 0;
	e->increment = 1;
	e->recursion = 10;
	e->reset = 1;
}

void	switch_render_mode(t_env *e)
{
	if (!e->live)
	{
		e->increment = 4;
		e->recursion = 1;
	}
	else
	{
		e->increment = 1;
		e->recursion = 10;
	}
	e->live = (e->live & 1) ^ 1;
	e->reset = 1;
}

static void (*g_key_func[255])(t_env *e) =
{
	['l'] = switch_render_mode,
//	['b'] = create_object,
	['n'] = switch_obj_tx,
	['m'] = switch_tsp_tx,
	['p'] = print_scene,
	['w'] = move_forward,
	['a'] = move_left,
	['s'] = move_backward,
	['d'] = move_right,
	[' '] = move_up,
	['c'] = move_down,
	[127 + 'l'] = yaw_left,
	[127 + 'r'] = yaw_right,
	[127 + 'u'] = pitch_up,
	[127 + 'd'] = pitch_down,
	[127 + 'm'] = move_ojbect_down,
	[127 + 'p'] = move_ojbect_up,
	[127 + '8'] = move_ojbect_forward,
	[127 + '4'] = move_ojbect_left,
	[127 + '6'] = move_ojbect_right,
	[127 + '2'] = move_ojbect_backward
};

int		is_acceptable_key(int key)
{
	int *all_keys;

	all_keys = g_key;
	while (*all_keys)
	{
		if (*all_keys == key)
			return (key);
		all_keys++;
	}
	return (0);
}

void	call_function(t_env *e, int key)
{
	int	i;

	if (!e->live)
		reset_screen(e);
	i = -1;
	while (++i < 255)
	{
		if (g_key_value[i] == key)
		{
			g_key_func[i](e);
			break ;
		}
	}
}

int		keyboard(int key, t_env *e)
{
	if (!is_acceptable_key(key))
		return (0);
	if (!e->live)
		switch_render_mode(e);
	call_function(e, key);
	return (0);
}
