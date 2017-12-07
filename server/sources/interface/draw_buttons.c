/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:43:16 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/07 20:05:26 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		draw_input_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;
	rect = e->topin_rect[bt_num];
	(state == 2) ? rect.y += 60 : 0;
	write_top_text(e, state);
	//write_right_text_top(e);
	//write_right_text(e);
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->topin_rect[bt_num]);
}

void		draw_button_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;
	if (bt_num != 8)
	{
		rect = e->bt_rect[bt_num];
		(state == 1) ? rect.y += 60 : 0;
		(state == 2) ? rect.y += 120 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->bt_rect[bt_num]);
	}
	else
	{
		rect = e->bt_rect[bt_num];
		(state == 1) ? rect.x -= 200 : 0;
		(state == 1) ? rect.y += 200 : 0;
		(state == 2) ? rect.x -= 400 : 0;
		(state == 2) ? rect.y += 200 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->bt_rect[bt_num]);
	}
}

void		draw_button_left(t_env *e, int b_num, int state)
{
	SDL_Rect rect;

	if (b_num != 9)
	{
		rect = e->b_rect[b_num];
		(state == 1) ? rect.x += 82 : 0;
		(state == 2) ? rect.x += 162 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->b_rect[b_num]);
	}
}

void 		draw_input(t_env *e, int i_num, int state)
{
	SDL_Rect rect;

	rect = e->i_rect[i_num];
	(state == 2) ? rect.x -= 750 : 0;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->i_rect[i_num]);
}

void		draw_all_button_top(t_env *e,  int state)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		SDL_BlitSurface(e->s_ui, &e->bt_rect[i], e->s_background, &e->bt_rect[i]);
	}
}

void		draw_all_button_left(t_env *e,  int state)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		SDL_BlitSurface(e->s_ui, &e->b_rect[i] , e->s_background, &e->b_rect[i]);
	}
}
