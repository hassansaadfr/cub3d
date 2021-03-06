/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/06 11:41:20 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_coord	*get_ray_line_minimap(t_ray *r)
{
	t_coord	*ray_impact;

	ray_impact = malloc(sizeof(t_coord));
	if (!ray_impact)
		return (NULL);
	if (r->disth < r->distv)
	{
		ray_impact->x = r->hx;
		ray_impact->y = r->hy;
	}
	if (r->disth > r->distv)
	{
		ray_impact->x = r->vx;
		ray_impact->y = r->vy;
	}
	return (ray_impact);
}

static void		texture_wall(t_vars *v, t_coord *pos, t_ray *r, t_wall *wall, int ray_nb)
{
	double		step;
	double		tex_pos;
	int			y;
	int			tex_y;
	int			screen;

	screen = v->c->resolution->y / 2 / (tan(30 * DR));
	wall->lineH = TILE_SIZE / r->final_dist * screen;
	y = pos[0].y;
	step = 1.0 * texture_choose(v, r).height / wall->lineH;
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
		tex_y = (int)tex_pos & (texture_choose(v, r).height - 1);
		tex_pos += step;
		if (ray_nb == v->c->resolution->x / 2)
			my_mlx_pixel_put(&v->img, pos[0].x, y, BLACK);
		else
			my_mlx_pixel_put(&v->img, pos[0].x, y,
			my_mlx_pixel_get(texture_choose(v, r), r->actual_impact_pos, tex_y));
		y++;
	}
}

static void		draw_walls(t_vars *v, t_ray *r, int ray_nb)
{
	t_wall	wall;
	t_coord	wall_pos[2];
	int		screen;

	screen = v->c->resolution->y / 2 / (tan(30 * DR));
	wall.lineH = TILE_SIZE / r->final_dist * screen;
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
}

void			draw_ray_lines(t_vars *v)
{
	t_ray	r;
	int		i;
	t_coord	**rays;

	rays = malloc(sizeof(t_coord) * (v->c->resolution->x) + 1);
	if (!rays)
		return ;
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
		rays[i] = get_ray_line_minimap(&r);
		r.ra += degree_to_radian(60 / (float)v->c->resolution->x);
		r.ra = fix_angle(r.ra);
		i++;
	}
	 draw_minimap(v);
	 i = 0;
	 t_coord *c;
	 t_coord	player_pos;
	 t_coord	r_p;
	player_pos.x = (v->player.p_pos.x / TILE_SIZE) * MAP_TILE_SIZE;
	player_pos.y =(v->player.p_pos.y / TILE_SIZE) * MAP_TILE_SIZE;
	 while (i < v->c->resolution->x)
	 {
		r_p.x = (rays[i]->x / TILE_SIZE) * MAP_TILE_SIZE +(MAP_TILE_SIZE);
		r_p.y = (rays[i]->y / TILE_SIZE) * MAP_TILE_SIZE +(MAP_TILE_SIZE);
		c = rays[i];
		if (i == 0 || i == v->c->resolution->x - 1)
			drawline(&player_pos, &r_p, RED, v);
		free(rays[i]);
		i++;
	 }
}
