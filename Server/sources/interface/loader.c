/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:49:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		loader_wait(t_env *e)
{

	if (e->loader == 1)
	{
		SDL_BlitSurface(e->s_slave, &(SDL_Rect){0 + (120 * e->slave), 0, 120,
			190}, e->s_background, &(SDL_Rect){580, 490, 120, 190});
		// e->slave++;
		// sleep(1);
		if (e->slave == 13)
			e->slave = 0;
		if (e->nb_cli == 0)
		{
			e->s_tmp = TTF_RenderText_Shaded(e->font[1],
			"WAITING FOR CLIENTS TO CONNECT...",
			(SDL_Color){255, 255, 255, 255}, COLOR_BT);
			SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
			e->s_tmp->h}, e->s_background, &(SDL_Rect){490, 670,
			e->s_tmp->w, e->s_tmp->h});
			SDL_FreeSurface(e->s_tmp);

		}
		else if (e->nb_cli > 0)
		{
			create_rect(e->s_background, (SDL_Rect){490, 670, 500, 30}, 0x242424);
			sprintf(e->txt[22], "%d - CLIENTS CONNECTED TO THE SERVER", e->nb_cli);
			e->s_tmp = TTF_RenderText_Shaded(e->font[0], e->txt[22],
						COLOR_W, COLOR_BT);
			SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
			e->s_tmp->h}, e->s_background, &(SDL_Rect){485, 670,
			e->s_tmp->w, e->s_tmp->h});
			SDL_FreeSurface(e->s_tmp);
			// Alterner entre deux textes
			// create_rect(e->s_background, (SDL_Rect){490, 670, 500, 30}, 0x242424);
			// sprintf(e->txt[23], "   PRESS ANY KEY TO START...   ");
			// e->s_tmp = TTF_RenderText_Shaded(e->font[0], e->txt[23],
			// 			COLOR_W, COLOR_BT);
			// SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
			// e->s_tmp->h}, e->s_background, &(SDL_Rect){485, 670,
			// e->s_tmp->w, e->s_tmp->h});
			// SDL_FreeSurface(e->s_tmp);
			// sleep(1);
		}
	}
}
