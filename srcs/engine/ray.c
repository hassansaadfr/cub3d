/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/22 00:07:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_rays_line_map(t_vars *v, t_ray *r)
{
	t_coord	ray_impact;
	t_coord	player_pos;

	if (DEBUG == 1)
	{
		player_pos.x = v->player.p_pos.x;
		player_pos.y = v->player.p_pos.y;
		if (r->disth < r->distv)
		{
			ray_impact.x = r->hx;
			ray_impact.y = r->hy;
		}
		if (r->disth > r->distv)
		{
			ray_impact.x = r->vx;
			ray_impact.y = r->vy;
		}
		drawline(&player_pos, &ray_impact, RED, v);
	}
}

static void	set_angle(t_ray *r)
{
	if (r->ra < 0)
		r->ra += 2 * PI;
	if (r->ra >= 2 * PI)
		r->ra -= 2 * PI;
}

static void	draw_walls(t_vars *v, t_ray *r, int color, int ray_nb)
{
	t_wall	wall;
	t_coord	start;
	t_coord	end;
	int screen;

	screen = v->c->resolution->y / 2 / (tan(30 * DR));
	wall.lineH = MAP_CUBE_SIZE / r->final_dist * screen;
	// wall.lineH = (v->map_size.x * v->c->resolution->y) / r->final_dist;
	if (wall.lineH > v->c->resolution->y)
		wall.lineH = v->c->resolution->y;
	wall.lineO = (v->c->resolution->y / 2) - wall.lineH / 2;
	start.x = ray_nb;
	start.y = wall.lineO;
	end.x = ray_nb;
	end.y = wall.lineH + wall.lineO;
	drawline(&start, &end, color, v);
}

static void	get_longuest_ray(t_vars *v, t_ray *r, int ray_nb)
{
	float	fisheye;
	int		color;

	if (r->disth < r->distv)
	{
		r->final_dist = r->disth;
		color = BLUE;
	}
	if (r->disth > r->distv)
	{
		r->final_dist = r->distv;
		color = DARK_BLUE;
	}
	fisheye = v->player.pa - r->ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	if (fisheye > 2 * PI)
		fisheye -= 2 * PI;
	r->final_dist = r->final_dist * cos(fisheye);
	draw_rays_line_map(v, r);
	draw_walls(v, r, color, ray_nb);
}

static float	degree_to_radian(float degree)
{
	float	out;

	out = degree * (PI / 180);
	return (out);
}

void		draw_ray_lines(t_vars *v)
{
	t_ray	r;
	int		i;

	i = 0;
	r.ra = v->player.pa - (DR * 30);
	set_angle(&r);
	while (i < v->c->resolution->x)
	{
		r.disth = 1000000;
		r.distv = 1000000;
		vertical_collision(v, &r);
		horizontal_collision(v, &r);
		get_longuest_ray(v, &r, i);
		r.ra += degree_to_radian(60.0 / (float)v->c->resolution->x);
		set_angle(&r);
		i++;
	}
}
