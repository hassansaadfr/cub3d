/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:20 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 19:31:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_sprite_angle(t_player *p, t_sprite *t)
{
	float	angle;
	float	pa;

	pa = p->pa;
	angle = pa - atan2(t->y - p->p_pos.y , t->x - p->p_pos.x);
	if (angle > PI)
		angle -= PI * 2;
	if (angle < -PI)
		angle += PI * 2;
	angle = fabs(angle);
	return (angle);
}

float	get_sprite_dist(t_player *p, t_sprite *sprite)
{
	return (ray_dist(&p->p_pos, sprite->x, sprite->y));
}

void	recalc_sprites_dist(t_vars *v)
{
	int			i;

	i = 0;
	while (i < v->nb_sprites)
	{
		v->sprites_list[i]->dist = get_sprite_dist(&v->player, v->sprites_list[i]) * cos(v->sprites_list[i]->angle);
		v->sprites_list[i]->angle = get_sprite_angle(&v->player, v->sprites_list[i]);
		if (v->sprites_list[i]->angle < (FOV / 2) + 0.2)
			v->sprites_list[i]->visible = 1;
		else
			v->sprites_list[i]->visible = 0;
		i++;
	}
	sort_sprites(v->sprites_list, v->nb_sprites);
	draw_sprites(v);
	free(v->distances_walls);
}

float	get_perp_dist(float dist, float angle)
{
	return (dist * cos(angle));
}
