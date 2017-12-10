/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 03:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 03:13:59 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        set_helper(t_env *e)
{
    e->help_actif = (e->help_actif == 0) ? 1 : 0;
    if (e->help_actif)
    {
        SDL_BlitSurface(e->s_ui, &e->help_rect, e->s_background, &(SDL_Rect){405, 190, 350, 400});
    }
}
