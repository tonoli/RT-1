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

	y = rect.y - 1;
	while (++y < rect.h)
	{
		x = (rect.x - 1);
		while (++x < rect.w)
		{
			*((unsigned *)(surf->pixels + y * surf->pitch + x *
			surf->format->BytesPerPixel)) = color;
		}
	}
}
