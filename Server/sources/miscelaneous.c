/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscelaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:52:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

double		randb(void)
{
	return (rand() / (double)RAND_MAX);
}
