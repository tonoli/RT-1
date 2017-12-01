/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/30 22:30:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

////////////////////////////// main use /////////////////////////////////

void		marble(t_env *e, t_vector *color, t_obj *closest_obj)
{
	double col = turb(e, vector_scale(closest_obj->cross, 1.0)) * 8.0;

//	double ratio = (double)(sin(fabs(closest_obj->cross.y) * (closest_obj->marblesize * col)));
//	double ratio = (double)sin((closest_obj->cross.y / (double)10.0) * col);

//	double ratio = sin((10.0 * closest_obj->cross.z) + col);

	t_vector pute;

//	pute.x = 1;
//	pute.y = 1;
//	pute.z = 1;

//	pute = vector_scale(pute, 0.5 * (1.0 + sin((4.0 * closest_obj->cross.z) + col)));


	double width_scale = 0.5;

//	double ratio = (1.0 + sin((width_scale * closest_obj->cross.x) + col));
	double ratio = col;

//	color->x = pute.x;
//	color->y = pute.y;
//	color->z = pute.z;

	color->x -= (double)(color->x * ratio * 0.8);
	color->x += (double)(closest_obj->marblecolor.x * ratio * 0.8);
	color->y -= (double)(color->y * ratio * 0.8);
	color->y += (double)(closest_obj->marblecolor.y * ratio * 0.8);
	color->z -= (double)(color->z * ratio * 0.8);
	color->z += (double)(closest_obj->marblecolor.z * ratio * 0.8);
}

////////////////////////// init noise ///////////////////////////

double trilinear_interp(t_vector c[2][2][2], double u, double v, double w)
{
	double accum = 0;
	double uu = u * u * (3.0 - (2.0 * u));
	double vv = v * v * (3.0 - (2.0 * v));
	double ww = w * w * (3.0 - (2.0 * w));
	int i;
	int j;
	int k;
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			k = 0;
			while (k < 2)
			{
				t_vector weight;
				weight.x = u - i;
				weight.y = v - j;
				weight.z = w - k;

				accum +=	(i * uu + (1 - i) * (1 - uu)) *
							(j * vv + (1 - j) * (1 - vv)) *
							(k * ww + (1 - k) * (1 - ww)) *
							vector_dot(c[i][j][k], weight);
				k++;
			}
			j++;
		}
		i++;
	}
	return (accum);
}


double noise(t_env *e, t_vector cross)
{
	double u = cross.x - floor(cross.x);
	double v = cross.y - floor(cross.y);
	double w = cross.z - floor(cross.z);

	int i = floor(cross.x);
	int j = floor(cross.y);
	int k = floor(cross.z);

	t_vector c[2][2][2];

	int di;
	int dj;
	int dk;
	di = 0;
	while (di < 2)
	{
		dj = 0;
		while (dj < 2)
		{
			dk = 0;
			while (dk < 2)
			{
				c[di][dj][dk] = e->ranvec[
								 e->perm_x[(i + di) & 255] ^
								 e->perm_y[(j + dj) & 255] ^
								 e->perm_z[(k + dk) & 255]
											];
				dk++;
			}
			dj++;
		}
		di++;
	}
	return (trilinear_interp(c, u, v, w));// * (double)255.0);
}

double turb(t_env *e, t_vector cross)
{
	double accum = 0;
	t_vector tmp = cross;
	double weight = 1.0;

	int i = 0;
	while (i < 7)
	{
		accum += weight * noise(e, tmp);
		weight *= (double)0.5;
		tmp = vector_scale(tmp, 2);
		i++;
	}
	return (fabs(accum));
}
