/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:15:32 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 12:15:54 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

t_vector	vector_normalize(t_vector a)
{
	t_vector v;

	v = vector_scale(a, 1.0 / vector_magnitude(a));
	return (v);
}
