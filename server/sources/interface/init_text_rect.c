/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:33:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/07 16:16:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        init_top_txt_rect_right(t_env *e)
{
    int i;

    i = -1;
    while (++i < 6)
    {
        e->it_rect[i].x = 1232;
        e->it_rect[i].y = 123 + (i * 37);
        e->it_rect[i].w = 42;
        e->it_rect[i].h = 19;
    }
}

void        init_txt_rect_right(t_env *e)
{
    int i;
    int y;

    i = 6;
    while (i < 18)
    {
        if (i % 3 == 0)
        {
            e->it_rect[i].x = 1138;
            y = 371 + (66 * (i - 6) / 3);
        }
        else if ((i + 1) % 3 == 0)
            e->it_rect[i].x = 1232;
        else
            e->it_rect[i].x = 1185;
        e->it_rect[i].y = y;
        e->it_rect[i].w = 42;
        e->it_rect[i++].h = 19;
    }
}

void        init_txt_rect_top(t_env *e)
{
    int i;

    i = -1;
    while (++i < 3)
    {
        e->tt_rect[i].x = 306 + (i * 98);
        e->tt_rect[i].y = 27;
        e->tt_rect[i].w = 42;
        e->tt_rect[i].h = 19;
    }
}

void        init_txt_rects(t_env *e)
{
    init_top_txt_rect_right(e);
    init_txt_rect_right(e);
    init_txt_rect_top(e);
}

void        create_txt_rect(t_env *e)
{

        // //////////////////////////////// TOP INPUT ///////////////////////////
        //
        // // 0
        // e->s_tmp = TTF_RenderText_Shaded(e->font[2], "25", COLOR_W, COLOR_BT);
        // SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        // e->s_tmp->h}, e->s_background,
        // &(SDL_Rect){e->tt_rect[0].x + 41 - e->s_tmp->w, e->tt_rect[0].y + 2,
        //             e->tt_rect[0].w, e->tt_rect[0].h});
        // SDL_FreeSurface(e->s_tmp);
        //
        // // 1
        // e->s_tmp = TTF_RenderText_Shaded(e->font[2], "10.0", COLOR_W, COLOR_BT);
        // SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        // e->s_tmp->h}, e->s_background,
        // &(SDL_Rect){e->tt_rect[1].x + 41 - e->s_tmp->w, e->tt_rect[1].y + 2,
        //             e->tt_rect[1].w, e->tt_rect[1].h});
        // SDL_FreeSurface(e->s_tmp);
        // // 2
        // e->s_tmp = TTF_RenderText_Shaded(e->font[2], "15.6", COLOR_W, COLOR_BT);
        // SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        // e->s_tmp->h}, e->s_background,
        // &(SDL_Rect){e->tt_rect[2].x + 41 - e->s_tmp->w, e->tt_rect[2].y + 2,
        //             e->tt_rect[2].w, e->tt_rect[2].h});
        // SDL_FreeSurface(e->s_tmp);

        //////////////////////////////// RIGHT ///////////////////////////

        // 0 TYPE
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "TRIANGLE", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[0].x + 41 - e->s_tmp->w, e->it_rect[0].y + 2,
                    e->it_rect[0].w, e->it_rect[0].h});
        SDL_FreeSurface(e->s_tmp);
        // 1 LIGHT
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "YES", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[1].x + 41 - e->s_tmp->w, e->it_rect[1].y + 2,
                    e->it_rect[1].w, e->it_rect[1].h});
        SDL_FreeSurface(e->s_tmp);
        // 2 Fuzz
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "NO", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[2].x + 41 - e->s_tmp->w, e->it_rect[2].y + 2,
                    e->it_rect[2].w, e->it_rect[2].h});
        SDL_FreeSurface(e->s_tmp);
        // 3 Reflection
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "YES", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[3].x + 41 - e->s_tmp->w, e->it_rect[3].y + 2,
                    e->it_rect[3].w, e->it_rect[3].h});
        SDL_FreeSurface(e->s_tmp);

        // 4 refraction
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "NO", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[4].x + 41 - e->s_tmp->w, e->it_rect[4].y + 2,
                    e->it_rect[4].w, e->it_rect[4].h});
        SDL_FreeSurface(e->s_tmp);
        // 5 Radius
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "15.8", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[5].x + 41 - e->s_tmp->w, e->it_rect[5].y + 2,
                    e->it_rect[5].w, e->it_rect[5].h});
        SDL_FreeSurface(e->s_tmp);


        // 6 Color R
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "150", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[6].x + 41 - e->s_tmp->w, e->it_rect[6].y + 2,
                    e->it_rect[6].w, e->it_rect[6].h});
        SDL_FreeSurface(e->s_tmp);

        // 7 Color G
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "151", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[7].x + 41 - e->s_tmp->w, e->it_rect[7].y + 2,
                    e->it_rect[7].w, e->it_rect[7].h});
        SDL_FreeSurface(e->s_tmp);
        // 8 Color B
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "152", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[8].x + 41 - e->s_tmp->w, e->it_rect[8].y + 2,
                    e->it_rect[8].w, e->it_rect[8].h});
        SDL_FreeSurface(e->s_tmp);

        // 9 Rotation X
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "15", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[9].x + 41 - e->s_tmp->w, e->it_rect[9].y + 2,
                    e->it_rect[9].w, e->it_rect[9].h});
        SDL_FreeSurface(e->s_tmp);
        // 10 Rotation Y
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "16", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[10].x + 41 - e->s_tmp->w, e->it_rect[10].y + 2,
                    e->it_rect[10].w, e->it_rect[10].h});
        SDL_FreeSurface(e->s_tmp);
        // 11 Rotation Z
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "17", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[11].x + 41 - e->s_tmp->w, e->it_rect[11].y + 2,
                    e->it_rect[11].w, e->it_rect[11].h});
        SDL_FreeSurface(e->s_tmp);

        // 12 MARBLE R
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "253", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[12].x + 41 - e->s_tmp->w, e->it_rect[12].y + 2,
                    e->it_rect[12].w, e->it_rect[12].h});
        SDL_FreeSurface(e->s_tmp);
        // 13 MARBLE G
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "254", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[13].x + 41 - e->s_tmp->w, e->it_rect[13].y + 2,
                    e->it_rect[13].w, e->it_rect[13].h});
        SDL_FreeSurface(e->s_tmp);
        // 14 MARBLE B
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "255", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[14].x + 41 - e->s_tmp->w, e->it_rect[14].y + 2,
                    e->it_rect[14].w, e->it_rect[14].h});
        SDL_FreeSurface(e->s_tmp);

        // 15 DAMIER 2 R
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "12", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[15].x + 41 - e->s_tmp->w, e->it_rect[15].y + 2,
                    e->it_rect[15].w, e->it_rect[15].h});
        SDL_FreeSurface(e->s_tmp);
        // 16 DAMIER 2 G
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "13", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[16].x + 41 - e->s_tmp->w, e->it_rect[16].y + 2,
                    e->it_rect[16].w, e->it_rect[16].h});
        SDL_FreeSurface(e->s_tmp);
        // 17 DAMIER 2 B
        e->s_tmp = TTF_RenderText_Shaded(e->font[2], "14", COLOR_W, COLOR_BT);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[17].x + 41 - e->s_tmp->w, e->it_rect[17].y + 2,
                    e->it_rect[17].w, e->it_rect[17].h});
        SDL_FreeSurface(e->s_tmp);

}
