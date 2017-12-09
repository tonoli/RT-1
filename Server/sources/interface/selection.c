/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:32:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/09 01:39:17 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        draw_selected(t_env *e)
{
    if (e->selected)
    {
        create_rect(e->s_background,
            (SDL_Rect){1126, 80, 160, 530}, 0xFF2b2b2b);
        if (e->i_actif == -1)
            SDL_BlitSurface(e->s_ui, &(SDL_Rect){1126, 80, 160, 530},
                       e->s_background, &(SDL_Rect){1126, 80, 160, 530});
        is_mouse_in_it_right(e);
        is_mouse_in_rect_right(e);
        write_right_text_top(e);
        write_right_text(e);
    }
    else
    {
        create_rect(e->s_background,
            (SDL_Rect){1126, 80, 160, 530}, 0xFF2b2b2b);
        e->i_actif = -1;
    }

}
