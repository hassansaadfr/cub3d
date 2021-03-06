/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collisions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:09:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/06 11:22:27 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hit_wall(t_vars *v, int x, int y)
{
	return (v->c->map[y][x] == '1');
}

static void	calc_horizontal(t_ray *r, t_vars *v)
{
	int		size;

	size = TILE_SIZE;
	r->dof = 0;
	r->atan = -1 / tan(r->ra);
	if (r->ra > PI)
	{
		r->ryh = (((int)(v->player.p_pos.y) / size) * size) - 0.0001;
		r->rxh = (v->player.p_pos.y - r->ryh) * r->atan + (v->player.p_pos.x);
		r->yoh = -size;
		r->xoh = -r->yoh * r->atan;
	}
	else if (r->ra < PI)
	{
		r->ryh = (((int)(v->player.p_pos.y) / size) * size) + size;
		r->rxh = ((v->player.p_pos.y) - r->ryh) * r->atan + (v->player.p_pos.x);
		r->yoh = size;
		r->xoh = -r->yoh * r->atan;
	}
	else if (r->ra == 0 || r->ra == PI)
	{
		r->rxh = v->player.p_pos.x;
		r->ryh = v->player.p_pos.y;
		r->dof = v->map_size.y;
	}
}

static void	calc_vertical(t_ray *r, t_vars *v)
{
	int		size;

	size = TILE_SIZE;
	r->dof = 0;
	r->ntan = -tan(r->ra);
	if (r->ra > PI / 2 && r->ra < 3 * PI / 2)
	{
		r->rxv = (((int)(v->player.p_pos.x) / size) * size) - 0.0001;
		r->ryv = (v->player.p_pos.x - r->rxv) * r->ntan + (v->player.p_pos.y);
		r->xov = -size;
		r->yov = -r->xov * r->ntan;
	}
	if (r->ra < PI / 2 || r->ra > 3 * PI / 2)
	{
		r->rxv = (((int)(v->player.p_pos.x) / size) * size) + size;
		r->ryv = ((v->player.p_pos.x) - r->rxv) * r->ntan + (v->player.p_pos.y);
		r->xov = size;
		r->yov = -r->xov * r->ntan;
	}
	if (r->ra == 0 || r->ra == PI)
	{
		r->rxv = v->player.p_pos.x;
		r->ryv = v->player.p_pos.y;
		r->dof = v->map_size.x;
	}
}

void		horizontal_collision(t_vars *v, t_ray *r)
{
	calc_horizontal(r, v);
	while (r->dof < v->map_size.y)
	{
		r->impact_pos_h = 1;
		r->mxh = ((int)(r->rxh) / TILE_SIZE);
		r->myh = ((int)(r->ryh) / TILE_SIZE);
		if (r->mxh > 0 && r->myh >= 0 && r->mxh < v->map_size.x
		&& r->myh < v->map_size.y && hit_wall(v, r->mxh, r->myh))
		{
			r->hx = r->rxh;
			r->hy = r->ryh;
			r->disth = ray_dist(&v->player.p_pos, r->hx, r->hy);
			r->impact_pos_h = r->rxh / TILE_SIZE - r->mxh;
			r->dof = v->map_size.y;
		}
		else
		{
			r->rxh += r->xoh;
			r->ryh += r->yoh;
			r->dof += 1;
		}
	}
}

void		vertical_collision(t_vars *v, t_ray *r)
{
	calc_vertical(r, v);
	while (r->dof < v->map_size.x)
	{
		r->impact_pos_v = 1;
		r->mxv = ((int)(r->rxv) / TILE_SIZE);
		r->myv = ((int)(r->ryv) / TILE_SIZE);
		if (r->mxv >= 0 && r->myv >= 0 && r->mxv <= v->map_size.x
		&& r->myv < v->map_size.y && hit_wall(v, r->mxv, r->myv))
		{
			r->vx = r->rxv;
			r->vy = r->ryv;
			r->distv = ray_dist(&v->player.p_pos, r->vx, r->vy);
			r->impact_pos_v = ((r->ryv) / TILE_SIZE) - r->myv;
			r->dof = v->map_size.x;
		}
		else
		{
			r->rxv += r->xov;
			r->ryv += r->yov;
			r->dof += 1;
		}
	}
}
