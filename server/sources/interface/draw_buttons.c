/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:43:16 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/30 23:18:16 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		draw_button_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;

	rect = e->bt_rect[bt_num];
	(state == 1) ? rect.y += 60 : 0;
	(state == 2) ? rect.y += 120 : 0;
	SDL_BlitSurface(e->s_ui, &rect,
					e->s_background, &e->bt_rect[bt_num]);
}

void		draw_button_left(t_env *e, int b_num, int state)
{
	SDL_Rect rect;

	rect = e->b_rect[b_num];
	(state == 1) ? rect.x += 82 : 0;
	(state == 2) ? rect.x += 162 : 0;
	SDL_BlitSurface(e->s_ui, &rect,
					e->s_background, &e->b_rect[b_num]);
}

void 		draw_input(t_env *e, int i_num, int state)
{
	SDL_Rect rect;

	rect = e->i_rect[i_num];
	(state == 2) ? rect.x -= 750 : 0;
	SDL_BlitSurface(e->s_ui, &rect,
					e->s_background, &e->i_rect[i_num]);
}
