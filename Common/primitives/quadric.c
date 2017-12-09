/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

int	solve_quadric(double c[3], double s[2])
{
	t_quadric	qd;

	if (IsZero(c[2]))
	{
		if (IsZero(c[1]))
			return (0);
		s[0] = -c[0] / c[1];
		return (1);
	}
	qd.p = c[1] / (2 * c[2]);
	qd.q = c[0] / c[2];
	qd.D = qd.p * qd.p - qd.q;
	if (IsZero(qd.D))
		s[0] = -qd.p;
	if (IsZero(qd.D))
		return (1);
	else if (qd.D < 0)
		return (0);
	else if (qd.D > 0)
	{
		s[0] = sqrt(qd.D) - qd.p;
		s[1] = -sqrt(qd.D) - qd.p;
		return (2);
	}
	return (0);
}
