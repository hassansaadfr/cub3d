/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/19 00:02:37 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	ray_dist(t_float_pos *p, float wallx, float wally, float ang)
{
	float	dist;

	(void)ang;
	dist = sqrt((wallx - p->x) * (wallx - p->x) + (wally - p->y) * (wally - p->y));
	return (dist);
}

static void	calc_horizontal(t_ray *r, t_vars *v)
{
	r->dof = 0;
	r->atan = -1 / tan(r->ra);
	if (r->ra > PI)
	{
		r->ryh = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
		r->rxh = (v->player.p_pos.y - r->ryh) * r->atan + (v->player.p_pos.x);
		r->yoh = -MAP_CUBE_SIZE;
		r->xoh = -r->yoh * r->atan;
	}
	else if (r->ra < PI)
	{
		r->ryh = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
		r->rxh = ((v->player.p_pos.y) - r->ryh) * r->atan + (v->player.p_pos.x);
		r->yoh = MAP_CUBE_SIZE;
		r->xoh = -r->yoh * r->atan;
	}
	else if (r->ra == 0 || r->ra == PI)
	{
		r->rxh = v->player.p_pos.x;
		r->ryh = v->player.p_pos.y;
		r->dof = v->map_size.y;
	}
}

static void calc_vertical(t_ray *r, t_vars *v)
{
	r->dof = 0;
	r->ntan = -tan(r->ra);
	if (r->ra > PI / 2 && r->ra < 3 * PI / 2)
	{
		r->rxv = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
		r->ryv = (v->player.p_pos.x - r->rxv) * r->ntan + (v->player.p_pos.y);
		r->xov = -MAP_CUBE_SIZE;
		r->yov = -r->xov * r->ntan;
	}
	if (r->ra < PI / 2  || r->ra > 3 * PI / 2)
	{
		r->rxv = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
		r->ryv = ((v->player.p_pos.x) - r->rxv) * r->ntan + (v->player.p_pos.y);
		r->xov = MAP_CUBE_SIZE;
		r->yov = -r->xov * r->ntan;
	}
	if (r->ra == 0 || r->ra == PI)
	{
		r->rxv = v->player.p_pos.x;
		r->ryv = v->player.p_pos.y;
		r->dof = v->map_size.x;
	}
}

static void	horizontal_ray(t_vars *v, t_ray *r)
{
	calc_horizontal(r, v);
	while (r->dof < v->map_size.y)
	{
		r->mxh = ((int)(r->rxh) / MAP_CUBE_SIZE);
		r->myh = ((int)(r->ryh) / MAP_CUBE_SIZE);
		if (r->mxh > 0 && r->myh >= 0 && r->mxh < v->map_size.x && r->myh < v->map_size.y && v->c->map[(int)r->myh][(int)r->mxh] == '1')
		{
			r->hx = r->rxh;
			r->hy = r->ryh;
			r->disth = ray_dist(&v->player.p_pos, r->hx, r->hy, r->ra);
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

void	vertical_ray(t_vars *v, t_ray *r)
{
	calc_vertical(r, v);
	while (r->dof < v->map_size.x)
	{
		r->mxv = ((int)(r->rxv) / MAP_CUBE_SIZE);
		r->myv = ((int)(r->ryv) / MAP_CUBE_SIZE);
		if (r->mxv >= 0 && r->myv > 0 && r->mxv < v->map_size.x && r->myv < v->map_size.y && v->c->map[(int)r->myv][(int)r->mxv] == '1')
		{
			r->vx = r->rxv;
			r->vy = r->ryv;
			r->distv = ray_dist(&v->player.p_pos, r->vx, r->vy, r->ra);
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

void	draw_ray_lines(t_vars *v)
{
	t_ray	r;
	int		i;
	t_coord	player_pos;
	t_coord	ray_impact;
	int color;

	i = 0;
	r.ra = v->player.pa - (DR * 30);
	if (r.ra < 0)
		r.ra += 2 * PI;
	if (r.ra >= 2 * PI)
		r.ra -= 2 * PI;
	player_pos.x = v->player.p_pos.x;
	player_pos.y = v->player.p_pos.y;
	while (i < 60)
	{
		r.disth = 1000000;
		r.distv = 1000000;
		vertical_ray(v, &r);
		horizontal_ray(v, &r);
		if (r.disth < r.distv)
		{
			ray_impact.x = r.hx;
			ray_impact.y = r.hy;
			r.final_dist = r.disth;
			color = DARK_BLUE;
		}
		if (r.disth > r.distv)
		{
			ray_impact.x = r.vx;
			ray_impact.y = r.vy;
			r.final_dist = r.distv;
			color = BLUE;
		}
		float fisheye = v->player.pa - r.ra;
		if (fisheye < 0)
			fisheye += 2 * PI;
		if (fisheye > 2 * PI)
			fisheye -= 2 * PI;
		r.final_dist = r.final_dist * cos(fisheye);
		float lineH = (v->map_size.x * v->c->resolution->y) / r.final_dist;
		if (lineH > v->c->resolution->y)
			lineH = v->c->resolution->y;
		float lineO = (v->c->resolution->y / 2) - lineH / 2;
		int sizew = v->c->resolution->x / 60;
		for (int w = 1; w <= sizew; w++)
		{
			if (sizew * i -w > 0)
				drawline(&(t_coord){sizew * i -w,lineO,0},&(t_coord){sizew * i -w,lineH + lineO,0},color, v);
		}
		drawline(&player_pos, &ray_impact, RED, v);
		r.ra += DR;
		if (r.ra < 0)
			r.ra += 2 * PI;
		if (r.ra > 2 * PI)
			r.ra -= 2 * PI;
		i++;
	}
}
