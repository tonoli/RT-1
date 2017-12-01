/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:46:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/01 01:17:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int 		is_mouse_in_rect(t_env *e, SDL_Rect rect[], int rect_len)
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

void		is_mouse_in_rect_top(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->bt_rect, 8);
	if (btn_i != -1)
	{
		state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : MOUSE;
		draw_button_top(e, btn_i, state);
	}
	else
		draw_button_top(e, btn_i, 0);
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
			draw_button_top(e, btn_i, state);
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			draw_input(e, btn_i, 0);
			e->i_actif = -1;
		}
	}
}

void		is_mouse_in_rect_left(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (SDL_PointInRect(&e->mouse, &e->b_rect[i]))
		{
			if (i != e->b_actif)
			{
				draw_button_left(e, i, 1);
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					printf("Bouton clik %d\n", i);
					draw_button_left(e, i, 2);
					e->b_actif = i;
				}
			}
			else
			{
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					draw_button_left(e, i, 1);
					e->b_actif = -1;
				}
			}

		}
		else if (i != e->b_actif)
			draw_button_left(e, i, 0);

	}
	if (SDL_PointInRect(&e->mouse, &e->b_rect[8]) && e->event.type == SDL_MOUSEBUTTONDOWN)
	{
		printf("HELP!!\n");
		e->help_actif = 1;
		SDL_BlitSurface(e->s_ui, &e->help_rect, e->s_background, &(SDL_Rect){405, 190, 350, 400});
	}
}

void	is_mouse_in_render(t_env *e)
{
	int i;
	int j;

	i = e->mouse.x;
	j = e->mouse.y;
	if (i > 82 && i < 82 + F_WIDTH)
		if (j > 72 && j < 72 + F_WIDTH)
		{
			// create_rect(e->s_ui, (SDL_Rect){80, 70, F_WIDTH + 4, 2}, 0xFFFF0000);
			// create_rect(e->s_ui, (SDL_Rect){80, 70, 40, F_HEIGHT + 4}, 0xFFFF00FF);
			//create_rect(e->s_background, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
			//create_rect(e->s_background, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);

			select_obj(i - 82, j - 72, e);
			printf("SELECTED : %p\n", (void *)e->selected);
		}
}

