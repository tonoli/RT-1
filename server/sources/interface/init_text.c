/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:58:12 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/06 00:22:45 by itonoli-         ###   ########.fr       */
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
    while (++i < 18)
    {
        if (i % 3 == 0)  // Colonne de gauche - R
        {
            e->it_rect[i].x = 1138;
            y = 371 + (66 * (i - 6) / 3);
        }
        else if (i % 2 == 0)  // Colonne de droite - B
            e->it_rect[i].x = 1232;
        else
            e->it_rect[i].x = 1185; // Colonne centre - G
        e->it_rect[i].y = y;
        e->it_rect[i].w = 42;
        e->it_rect[i].h = 19;
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
    init_txt_rect_right(e);
    //init_txt_rect_top(t_env *e);
}
