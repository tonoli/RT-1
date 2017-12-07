/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:34:06 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/07 16:10:19 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        right_text(t_env *e, char *str,
                        SDL_Rect rect, SDL_Color color_back)
{
    e->s_tmp = TTF_RenderText_Shaded(e->font[2], str, COLOR_W, color_back);
    SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
    e->s_tmp->h}, e->s_background,
    &(SDL_Rect){rect.x + 41 - e->s_tmp->w, rect.y + 2,
                rect.w, rect.h});
    SDL_FreeSurface(e->s_tmp);
}

void        write_top_text(t_env *e, int state)
{
    int i;
    char buff[100000];
    int precision;

    i = -1;
    precision = 2;
    //sprintf(buff_a, "%.*f", precision,  e->rebond);
    //sprintf(buff_b, "%.*f", precision, e->move_speed);
    sprintf(buff, "%.*f", precision, e->rot_speed);
    while (++i < 3)
    {
        if (state == 2)
            right_text(e, buff, e->tt_rect[i], COLOR_BT);
        else
            right_text(e, buff, e->tt_rect[i], COLOR_TXT);
    }
}
