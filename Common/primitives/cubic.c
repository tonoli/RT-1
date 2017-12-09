/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:45:52 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

void	init_cubic(t_cubic *cu, double c[4])
{
	cu->A = c[2] / c[3];
	cu->B = c[1] / c[3];
	cu->C = c[0] / c[3];
	cu->sq_A = cu->A * cu->A;
	cu->p = 1.0 / 3 * (-1.0 / 3 * cu->sq_A + cu->B);
	cu->q = 1.0 / 2 * (2.0 / 27 * cu->A * cu->sq_A - 1.0 / 3
				* cu->A * cu->B + cu->C);
	cu->cb_p = cu->p * cu->p * cu->p;
	cu->D = cu->q * cu->q + cu->cb_p;
}

void	zero_d(t_cubic *cu, double s[3])
{
	double	u;

	if (IsZero(cu->q))
	{
		s[0] = 0;
		cu->num = 1;
	}
	else
	{
		u = cbrt(-cu->q);
		s[0] = 2 * u;
		s[1] = -u;
		cu->num = 2;
	}
}

void	negative_d(t_cubic *cu, double s[3])
{
	double	phi;
	double	t;

	phi = 1.0 / 3 * acos(-cu->q / sqrt(-cu->cb_p));
	t = 2 * sqrt(-cu->p);
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + M_PI / 3);
	s[2] = -t * cos(phi - M_PI / 3);
	cu->num = 3;
}

void	positive_d(t_cubic *cu, double s[3])
{
	double	sqrt_d;
	double	u;
	double	v;

	sqrt_d = sqrt(cu->D);
	u = cbrt(sqrt_d - cu->q);
	v = -cbrt(sqrt_d + cu->q);
	s[0] = u + v;
	cu->num = 1;
}

int		solve_cubic(double c[4], double s[3])
{
	t_cubic	cu;

	if (IsZero(c[3]))
		return (solve_quadric(c, s));
	init_cubic(&cu, c);
	if (IsZero(cu.D))
		zero_d(&cu, s);
	else if (cu.D < 0)
		negative_d(&cu, s);
	else
		positive_d(&cu, s);
	cu.sub = 1.0 / 3 * cu.A;
	cu.i = -1;
	while (++cu.i < cu.num)
		s[cu.i] -= cu.sub;
	return (cu.num);
}
