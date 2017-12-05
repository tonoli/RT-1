/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:44:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/11/30 23:01:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	create_rect(SDL_Surface *surf, SDL_Rect rect, int color)
{
	int	x;
	int	y;
	int x_end;
	int y_end;

	y = rect.y - 1;
	y_end = rect.y + rect.h;
	while (++y < y_end)
	{
		x = (rect.x - 1);
		x_end = rect.x + rect.w;
		while (++x < x_end)
		{
			*((unsigned *)(surf->pixels + y * surf->pitch + x *
						   surf->format->BytesPerPixel)) = color;
		}
	}
}

void create_border(t_env *e,int active)
{
	if (active == 0)
	{
		create_rect(e->s_background,
					(SDL_Rect){80, 70, F_WIDTH + 4, 2}, 0xFF000000);
		create_rect(e->s_background,
					(SDL_Rect){80, 70, 2, F_HEIGHT + 4}, 0xFF000000);
		create_rect(e->s_background,
					(SDL_Rect){1106, 70, 2, F_HEIGHT + 4}, 0xFF000000);
		create_rect(e->s_background,
					(SDL_Rect){80, 720, F_WIDTH + 4, 2}, 0xFF000000);
	}
	else
	{
		create_rect(e->s_background,
					(SDL_Rect){80, 70, F_WIDTH + 4, 2}, 0xFF5bc4e6);
		create_rect(e->s_background,
					(SDL_Rect){80, 70, 2, F_HEIGHT + 4}, 0xFF5bc4e6);
		create_rect(e->s_background,
					(SDL_Rect){1106, 70, 2, F_HEIGHT + 4}, 0xFF5bc4e6);
		create_rect(e->s_background,
					(SDL_Rect){80, 720, F_WIDTH + 4, 2}, 0xFF5bc4e6);
	}
}
