/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:34:13 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        change_rebond(t_env *e, int mode)
{
    if ((mode == INCREASE) && (e->rebond < 1))
        e->rebond += 0.01;
    else if((mode == DECREASE) && (e->rebond > 0))
        e->rebond -= 0.01;
}

void        change_rot_speed(t_env *e, int mode)
{
    if ((mode == INCREASE) && (e->rot_speed < 1))
        e->rot_speed += 0.01;
    else if((mode == DECREASE) && (e->rot_speed > 0))
        e->rot_speed -= 0.01;
}

void        change_move_speed(t_env *e, int mode)
{
    if ((mode == INCREASE) && (e->move_speed < 100))
        e->move_speed += 0.1;
    else if((mode == DECREASE) && (e->move_speed > 0))
        e->move_speed -= 0.1;
}
