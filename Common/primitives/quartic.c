/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:24 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:45:24 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

int		init_quartic(t_quartic *q, double c[5])
{
	q->A = c[3] / c[4];
	q->B = c[2] / c[4];
	q->C = c[1] / c[4];
	q->D = c[0] / c[4];
	q->sq_A = q->A * q->A;
	q->p = -3.0 / 8 * q->sq_A + q->B;
	q->q = 1.0 / 8 * q->sq_A * q->A - 1.0 / 2 * q->A * q->B + q->C;
	q->r = -3.0 / 256 * q->sq_A * q->sq_A + 1.0 / 16 * q->sq_A * q->B
		- 1.0 / 4 * q->A * q->C + q->D;
	q->i = -1;
	return (1);
}

void	root_zero(t_quartic *q, double s[4])
{
	q->coeffs[0] = q->q;
	q->coeffs[1] = q->p;
	q->coeffs[2] = 0;
	q->coeffs[3] = 1;
	q->num = solve_cubic(q->coeffs, s);
	s[q->num++] = 0;
}

void	root_non_zero(t_quartic *q, double s[4])
{
	q->coeffs[0] = 1.0 / 2 * q->r * q->p - 1.0 / 8 * q->q * q->q;
	q->coeffs[1] = -q->r;
	q->coeffs[2] = -1.0 / 2 * q->p;
	q->coeffs[3] = 1;
	solve_cubic(q->coeffs, s);
	q->z = s[0];
	q->u = q->z * q->z - q->r;
	q->v = 2 * q->z - q->p;
}

void	solve_resolvant_quartic(t_quartic *q, double s[4])
{
	q->coeffs[0] = q->z - q->u;
	q->coeffs[1] = q->q < 0 ? -q->v : q->v;
	q->coeffs[2] = 1;
	q->num = solve_quadric(q->coeffs, s);
	q->coeffs[0] = q->z + q->u;
	q->coeffs[1] = q->q < 0 ? q->v : -q->v;
	q->coeffs[2] = 1;
	q->num += solve_quadric(q->coeffs, s + q->num);
}

int		solve_quartic(double c[5], double s[4])
{
	t_quartic	q;

	if (init_quartic(&q, c) && IsZero(q.r))
		root_zero(&q, s);
	else
	{
		root_non_zero(&q, s);
		if (IsZero(q.u))
			q.u = 0;
		else if (q.u > 0)
			q.u = sqrt(q.u);
		else
			return (0);
		if (IsZero(q.v))
			q.v = 0;
		else if (q.v > 0)
			q.v = sqrt(q.v);
		else
			return (0);
		solve_resolvant_quartic(&q, s);
	}
	q.sub = 1.0 / 4 * q.A;
	while (++q.i < q.num)
		s[q.i] -= q.sub;
	return (q.num);
}
