/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dna_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:53:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/04 21:42:18 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_cyl_side_b(int row, t_obj obj)
{
	double	tmp;
	double	tmp2;
	double	tmp3;

	if (row != 0)
	{
		obj->type = 3;
		obj->ori.x = -20 * cos(row * 0.25);
		obj->ori.y = -20 * sin(row * 0.25);
		obj->ori.z = 5 * row + 15 * c;
		tmp = (-20 * cos((row - 1) * 0.25)) - (-20 * cos(row * 0.25));
		obj->dir.x = tmp;
		tmp2 = (-20 * sin((row - 1) * 0.25)) - (-20 * sin(row * 0.25));
		obj->dir.y = tmp2;
		tmp3 = (5 * (row - 1) + 15 * (row - 1)) - (5 * row + 15 * row);
		obj->dir.z = tmp3
		obj->height = sqrt(tmp * tmp + tmp2 * tmp2 + tmp3 * tmp3);
		obj->radius = 4;
		obj->color.x = 0x330000;
		obj->color.y = 0x003300;
		obj->color.z = 0x0000ff;
	}
}

void	ft_cyl_side_a(int row, t_obj obj)
{
	double	tmp;
	double	tmp2;
	double	tmp3;

	if (row != 0)
	{
		obj->type = 3;
		obj->ori.x = 20 * cos(row * 0.25);
		obj->ori.y = 20 * sin(row * 0.25);
		obj->ori.z = 5 * row + 15 * c;
		tmp = (20 * cos((row - 1) * 0.25)) - (20 * cos(row * 0.25));
		obj->dir.x = tmp;
		tmp2 = (20 * sin((row - 1) * 0.25)) - (20 * sin(row * 0.25));
		obj->dir.y = tmp2;
		tmp3 = (5 * (row - 1) + 15 * (row - 1)) - (5 * row + 15 * row);
		obj->dir.z = tmp3
		obj->height = sqrt(tmp * tmp + tmp2 * tmp2 + tmp3 * tmp3);
		obj->radius = 4;
		obj->color.x = 0x330000;
		obj->color.y = 0x003300;
		obj->color.z = 0x0000ff;
	}
}

void	ft_cyl_b(int row, t_obj obj)
{
	obj->type = 3;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = 5 * row + 15 * c;
	obj->dir.x = -cos(row * 0.25);
	obj->dir.y = -sin(row * 0.25);
	obj->dir.z = 0;
	obj->radius = 2;
	obj->height = 20;
	obj->color.x = 0x000000;
	obj->color.y = 0x00cc00;
	obj->color.z = 0x000000;
}

void	ft_cyl_a(int row, t_obj obj)
{
	obj->type = 3;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = 5 * row + 15 * c;
	obj->dir.x = cos(row * 0.25);
	obj->dir.y = sin(row * 0.25);
	obj->dir.z = 0;
	obj->radius = 2;
	obj->height = 20;
	obj->color.x = 0xff0000;
	obj->color.y = 0x000000;
	obj->color.z = 0x000080;
}

void	ft_sphere_b(int row, t_obj obj)
{
	obj->type = 1;
	obj->ori.x = -20 * cos(row * 0.25);
	obj->ori.y = -20 * sin(row * 0.25);
	obj->ori.z = 5 * row + 15 * row;
	obj->radius = 7;
	obj->color.x = 0x330000;
	obj->color.y = 0x003300;
	obj->color.z = 0x0000ff;
}

void	ft_sphere_a(int row, t_obj obj)
{
	obj->type = 1;
	obj->ori.x = 20 * cos(row * 0.25);
	obj->ori.y = 20 * sin(row * 0.25);
	obj->ori.z = 5 * row + 15 * row;
	obj->radius = 7;
	obj->color.x = 0x330000;
	obj->color.y = 0x003300;
	obj->color.z = 0x0000ff;
}

void	ft_sphere_mid(int row, t_obj obj)
{
	obj->type = 1;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = 5 * row + 15 * c;
	obj->radius = 3.5;
	obj->color.x = 0x330000;
	obj->color.y = 0x003300;
	obj->color.z = 0x0000ff;
}

void	ft_add_dna(t_env *e)
{
	int		row;

	row = 0;
	while (row < 30)
	{
		ft_sphere_mid(row, e->object);
		e->object = e->object->next;
		ft_sphere_a(row, e->object);
		e->object = e->object->next;
		ft_sphere_b(row, e->object);
		e->object = e->object->next;
		ft_cyl_a(row, e->object);
		e->object = e->object->next;
		ft_cyl_b(row), e->object; 
		e->object = e->object->next;
		ft_cyl_side_a(row, e->object);
		e->object = e->object->next;
		ft_cyl_side_b(row, e->object);
		e->object = e->object->next;
		row++;
	}
}
