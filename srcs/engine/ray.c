/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/23 21:43:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_rays_line_map(t_vars *v, t_ray *r)
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

static float	fix_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

static void		draw_walls(t_vars *v, t_ray *r, int color, int ray_nb)
{
	t_wall	wall;
	t_coord	wall_pos[2];
	int		screen;

	screen = v->c->resolution->y / 2 / (tan(30 * DR));
	wall.lineH = MAP_CUBE_SIZE / r->final_dist * screen;
	if (wall.lineH > v->c->resolution->y)
		wall.lineH = v->c->resolution->y;
	wall.lineO = (v->c->resolution->y / 2) - wall.lineH / 2;
	wall_pos[0].x = ray_nb;
	wall_pos[0].y = wall.lineO;
	wall_pos[1].x = ray_nb;
	wall_pos[1].y = wall.lineH + wall.lineO;
	drawline(&wall_pos[0], &wall_pos[1], color, v);
	drawline(&(t_coord){ray_nb, 0, 0}, &(t_coord){ray_nb, wall_pos[0].y, 0},
	create_color(v->c->c_color), v);
	drawline(&(t_coord){ray_nb, wall_pos[1].y, 0}, &(t_coord){ray_nb,
	v->c->resolution->y, 0}, create_color(v->c->f_color), v);
}

static void		get_longuest_ray(t_vars *v, t_ray *r, int ray_nb)
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
	fisheye = fix_angle(fisheye);
	r->final_dist = r->final_dist * cos(fisheye);
	draw_rays_line_map(v, r);
	draw_walls(v, r, color, ray_nb);
}

void			draw_ray_lines(t_vars *v)
{
	t_ray	r;
	int		i;

	i = 0;
	r.ra = v->player.pa - (DR * 30);
	r.ra = fix_angle(r.ra);
	while (i < v->c->resolution->x)
	{
		r.disth = 1000000;
		r.distv = 1000000;
		vertical_collision(v, &r);
		horizontal_collision(v, &r);
		get_longuest_ray(v, &r, i);
		r.ra += degree_to_radian(60.0 / (float)v->c->resolution->x);
		r.ra = fix_angle(r.ra);
		i++;
	}
}
