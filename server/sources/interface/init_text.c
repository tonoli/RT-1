/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:58:12 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/06 18:35:32 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        init_txt_rect_right(t_env *e)
{
    int i;
    int y;

    i = -1;
    while (++i < 6)
    {
        e->it_rect[i].x = 1232;
        e->it_rect[i].y = 123 + (i * 37);
        e->it_rect[i].w = 42;
        e->it_rect[i].h = 19;
    }
    while (i < 18) //
    {
        if (i % 3 == 0)  // Colonne de gauche - R
        {
            e->it_rect[i].x = 1138;
            y = 371 + (66 * (i - 6) / 3);
        }
        else if (i % 2 == 0)  // Colonne de droite - B
            e->it_rect[i].x = 1232;
        else if (i % 3 != 0 && i % 2 != 0)
            e->it_rect[i].x = 1185; // Colonne centre - G
        e->it_rect[i].y = y;
        e->it_rect[i].w = 42;
        e->it_rect[i].h = 19;
        i++;
    }
}

void        init_txt_rect_top(t_env *e)
{
    int i;

    i = -1;
    while (++i < 3)
    {
        e->tt_rect[i].x = 306 + (i * 98); // init 306
        e->tt_rect[i].y = 27; // init 27
        e->tt_rect[i].w = 42;
        e->tt_rect[i].h = 19;
    }
}

void        init_txt_rects(t_env *e)
{
    init_txt_rect_right(e);
    init_txt_rect_top(e);
}

// SDL_Rect    center_txt(SDL_Rect *rect, int width)
// {
//     rect->x += 42 - width;
//     // if (len >= 6)
//     //     rect.x -= 2;
//     // if (len == 5)
//     //     rect.x += 6;
//     // if (len == 4)
//     //     rect.x += 8;
//     // if (len == 3)
//     //     rect.x += 13;
//     // if (len == 2)
//     //     rect.x += 14;
//     // if (len == 1)
//     //     rect.x += 19;
//     return (rect);
// }

void        create_txt_rect(t_env *e)
{

        //////////////////////////////// TOP INPUT ///////////////////////////

        // 0
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "25", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->tt_rect[0].x + 41 - e->s_tmp->w, e->tt_rect[0].y + 1,
                    e->tt_rect[0].w, e->tt_rect[0].h});
        SDL_FreeSurface(e->s_tmp);

        // 1
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "10.0", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->tt_rect[1].x + 41 - e->s_tmp->w, e->tt_rect[1].y + 1,
                    e->tt_rect[1].w, e->tt_rect[1].h});
        SDL_FreeSurface(e->s_tmp);
        // 2
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "15.6", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->tt_rect[2].x + 41 - e->s_tmp->w, e->tt_rect[2].y + 1,
                    e->tt_rect[2].w, e->tt_rect[2].h});
        SDL_FreeSurface(e->s_tmp);

        //////////////////////////////// RIGHT ///////////////////////////

        // 0 TYPE
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "SPHERE", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[0].x + 41 - e->s_tmp->w, e->it_rect[0].y + 1,
                    e->it_rect[0].w, e->it_rect[0].h});
        SDL_FreeSurface(e->s_tmp);
        // 1 LIGHT
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "YES", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[1].x + 41 - e->s_tmp->w, e->it_rect[1].y + 1,
                    e->it_rect[1].w, e->it_rect[1].h});
        SDL_FreeSurface(e->s_tmp);
        // 2 Fuzz
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "NO", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[2].x + 41 - e->s_tmp->w, e->it_rect[2].y + 1,
                    e->it_rect[2].w, e->it_rect[2].h});
        SDL_FreeSurface(e->s_tmp);
        // 3 Reflection
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "YES", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[3].x + 41 - e->s_tmp->w, e->it_rect[3].y + 1,
                    e->it_rect[3].w, e->it_rect[3].h});
        SDL_FreeSurface(e->s_tmp);

        // 4 refraction
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "NO", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[4].x + 41 - e->s_tmp->w, e->it_rect[4].y + 1,
                    e->it_rect[4].w, e->it_rect[4].h});
        SDL_FreeSurface(e->s_tmp);
        // 5 Radius
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "15.8", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[5].x + 41 - e->s_tmp->w, e->it_rect[5].y + 1,
                    e->it_rect[5].w, e->it_rect[5].h});
        SDL_FreeSurface(e->s_tmp);


        // 6 Color R
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "150", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[6].x + 41 - e->s_tmp->w, e->it_rect[6].y + 1,
                    e->it_rect[6].w, e->it_rect[6].h});
        SDL_FreeSurface(e->s_tmp);

        // 7 Color G
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "151", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[7].x + 41 - e->s_tmp->w, e->it_rect[7].y + 1,
                    e->it_rect[7].w, e->it_rect[7].h});
        SDL_FreeSurface(e->s_tmp);
        // 8 Color B
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "152", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[8].x + 41 - e->s_tmp->w, e->it_rect[8].y + 1,
                    e->it_rect[8].w, e->it_rect[8].h});
        SDL_FreeSurface(e->s_tmp);

        // 9 Rotation X
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "15", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[9].x + 41 - e->s_tmp->w, e->it_rect[9].y + 1,
                    e->it_rect[9].w, e->it_rect[9].h});
        SDL_FreeSurface(e->s_tmp);
        // 10 Rotation Y
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "16", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[10].x + 41 - e->s_tmp->w, e->it_rect[10].y + 1,
                    e->it_rect[10].w, e->it_rect[10].h});
        SDL_FreeSurface(e->s_tmp);
        // 11 Rotation Z
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "17", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[11].x + 41 - e->s_tmp->w, e->it_rect[11].y + 1,
                    e->it_rect[11].w, e->it_rect[11].h});
        SDL_FreeSurface(e->s_tmp);

        // 12 MARBLE R
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "253", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[12].x + 41 - e->s_tmp->w, e->it_rect[12].y + 1,
                    e->it_rect[12].w, e->it_rect[12].h});
        SDL_FreeSurface(e->s_tmp);
        // 13 MARBLE G
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "254", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[13].x + 41 - e->s_tmp->w, e->it_rect[13].y + 1,
                    e->it_rect[13].w, e->it_rect[13].h});
        SDL_FreeSurface(e->s_tmp);
        // 14 MARBLE B
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "255", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[14].x + 41 - e->s_tmp->w, e->it_rect[14].y + 1,
                    e->it_rect[14].w, e->it_rect[14].h});
        SDL_FreeSurface(e->s_tmp);

        // 15 DAMIER 2 R
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "12", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[15].x + 41 - e->s_tmp->w, e->it_rect[15].y + 1,
                    e->it_rect[15].w, e->it_rect[15].h});
        SDL_FreeSurface(e->s_tmp);
        // 16 DAMIER 2 G
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "13", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[16].x + 41 - e->s_tmp->w, e->it_rect[16].y + 1,
                    e->it_rect[16].w, e->it_rect[16].h});
        SDL_FreeSurface(e->s_tmp);
        // 17 DAMIER 2 B
        e->s_tmp = TTF_RenderText_Shaded(e->font[1], "14", COLOR_W, COLOR_BG);
        SDL_BlitSurface(e->s_tmp , &(SDL_Rect){0, 0, e->s_tmp->w,
        e->s_tmp->h}, e->s_background,
        &(SDL_Rect){e->it_rect[17].x + 41 - e->s_tmp->w, e->it_rect[17].y + 1,
                    e->it_rect[17].w, e->it_rect[17].h});
        SDL_FreeSurface(e->s_tmp);

}
