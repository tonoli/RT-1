/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:48:21 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 03:35:01 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
				e->it_actif = btn_i;
		}
	}
}

void		is_mouse_in_credit(t_env *e)
{
	int state;
	int btn_i;

	if (SDL_PointInRect(&e->mouse, &e->credit_rect)
    && e->event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e->credit_actif == 0)
        {
            e->credit_actif = 1;
            SDL_BlitSurface(e->s_credit, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}
            , e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
        }
        else
            e->credit_actif = 0;
    }
}
