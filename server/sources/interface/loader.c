/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:49:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/05 21:58:21 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		loader_wait(t_env *e)
{
	create_rect(e->s_background, (SDL_Rect){415, 610, 465, 45}, 0xFF242424);
	while (e->nb_cli == 0)
	{
		e->s_tmp = TTF_RenderText_Shaded(e->font[1],
		"WAITING FOR CLIENTS TO CONNECT...",
		(SDL_Color){255, 255, 255, 255}, (SDL_Color){36, 36, 36, 255});
		SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background, &(SDL_Rect){442, 620,
		e->s_tmp->w, e->s_tmp->h});
		SDL_FreeSurface(e->s_tmp);
		sleep(3);
		e->nb_cli = 1;
	}
	SDL_BlitSurface(e->s_loader, &(SDL_Rect){415, 610, 465, 45},
					e->s_background, &(SDL_Rect){415, 610, 465, 45});
	return (1);
}
