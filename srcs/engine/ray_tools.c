/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:11:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/28 11:42:46 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ray_dist(t_float_pos *p, float wallx, float wally, float ang)
{
	float	d;

	(void)ang;
	d = sqrt((wallx - p->x) * (wallx - p->x) + (wally - p->y) * (wally - p->y));
	return (d);
}

float	degree_to_radian(float degree)
{
	float	out;

	out = degree * (PI / 180);
	return (out);
}

float	fix_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}
