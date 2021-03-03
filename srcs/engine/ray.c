/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/03 14:49:29 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_rays_line_map(t_vars *v, t_ray *r)
{
	t_coord	ray_impact;
	t_coord	player_pos;

	if (DEBUG == 2)
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

static void		texture_wall(t_vars *v, t_coord *pos, t_ray *r, t_wall *wall, int ray_nb)
{
	double		step;
	double		tex_pos;
	int			y;
	int			tex_y;
	int			screen;

	screen = v->c->resolution->y / 2 / (tan(30 * DR));
	wall->lineH = MAP_CUBE_SIZE / r->final_dist * screen;
	y = pos[0].y;
	step = 1.0 * v->ea.height / wall->lineH;
	tex_pos = ((float)pos[0].y - (float)v->c->resolution->y / 2 + wall->lineH / 2) * step;
	if (ray_nb == v->c->resolution->x / 2)
	{
		v->debug_tex_pos = tex_pos;
		v->debug_draw_start = pos[0].y;
		v->debug_lineH = wall->lineH;
		v->debug_step = step;
		v->debug_dist = r->final_dist;
	}

	while (y < pos[1].y)
	{
		tex_y = (int)tex_pos & (v->ea.height - 1);
		tex_pos += step;
		if (ray_nb == v->c->resolution->x / 2)
			my_mlx_pixel_put(&v->img, pos[0].x, y, BLACK);
		else
			my_mlx_pixel_put(&v->img, pos[0].x, y,
			my_mlx_pixel_get(v->ea, r->actual_impact_pos, tex_y));
		y++;
	}
}

static void		draw_walls(t_vars *v, t_ray *r, int ray_nb)
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
	if (ray_nb == v->c->resolution->x / 2)
		v->player.wall = wall;
	texture_wall(v, wall_pos, r, &wall, ray_nb);
	drawline(&(t_coord){ray_nb, 0, 0}, &(t_coord){ray_nb, wall_pos[0].y, 0},
	create_color(v->c->c_color), v);
	drawline(&(t_coord){ray_nb, wall_pos[1].y, 0}, &(t_coord){ray_nb,
	v->c->resolution->y, 0}, create_color(v->c->f_color), v);
}

static void		get_longuest_ray(t_vars *v, t_ray *r, int ray_nb)
{
	float	fisheye;

	if (r->disth < r->distv)
	{
		r->final_dist = r->disth;
		r->actual_impact_pos = r->impact_pos_h;
	}
	if (r->distv < r->disth)
	{
		r->final_dist = r->distv;
		r->actual_impact_pos = r->impact_pos_v;
	}
	fisheye = v->player.pa - r->ra;
	fisheye = fix_angle(fisheye);
	r->final_dist = r->final_dist * cos(fisheye);
	draw_walls(v, r, ray_nb);
	draw_rays_line_map(v, r);
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
