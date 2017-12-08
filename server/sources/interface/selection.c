/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:32:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/08 13:31:40 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        draw_selected(t_env *e)
{
    if (e->loader == 0)
        create_rect(e->s_background,
           (SDL_Rect){1126, 80, 160, 530}, 0xFF2b2b2b);
    if (e->selected)
    {
        SDL_BlitSurface(e->s_ui, &(SDL_Rect){1126, 80, 160, 530},
                       e->s_background, &(SDL_Rect){1126, 80, 160, 530});
        write_right_text_top(e);
        write_right_text(e);
        //if (e->event.type == SDL_MOUSEMOTION || e->event.type == SDL_MOUSEBUTTONDOWN)
        is_mouse_in_rect_right(e);
    }
}
