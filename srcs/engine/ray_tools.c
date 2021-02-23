/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:11:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/23 21:42:14 by hsaadaou         ###   ########.fr       */
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
