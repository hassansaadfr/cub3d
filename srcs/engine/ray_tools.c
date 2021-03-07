/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:11:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 21:31:38 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ray_dist(t_float_pos *player, float endx, float endy)
{
	float	distance;
	float	x;
	float	y;

	x = (endx - player->x) * (endx - player->x);
	y = (endy - player->y) * (endy - player->y);
	distance = sqrt(x + y);
	return (distance);
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
	angle = fabs(angle);
	return (angle);
}

t_tex	texture_choose(t_vars *v, t_ray *r)
{
	t_tex	tex;

	if (r->disth < r->distv)
	{
		if (r->ra < PI)
			tex = v->so;
		if (r->ra > PI)
			tex = v->no;
	}
	else
	{
		if (r->ra < PI / 2 || r->ra > 3 * PI / 2)
			tex = v->ea;
		if (r->ra > PI / 2 && r->ra < 3 * PI / 2)
			tex = v->we;
	}
	return (tex);
}
