/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:50:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 21:27:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_sprites_list(t_vars *v)
{
	v->nb_sprites = 0;
	v->sprites_list = NULL;
	parse_map_sprites(v);
	sort_sprites(v->sprites_list, v->nb_sprites);
}

static void		draw_without_transparancy(t_vars *v, int x, int y, int color)
{
	if (color != my_mlx_pixel_get(v->sprite_tex, 0, 0))
		my_mlx_pixel_put(&v->img, x, y, color);
}

void			display_sprites(t_vars *v, t_sprite *s, t_coord *screen)
{
	int		x;
	int		y;
	t_coord	offset;
	int		dist_top;

	x = s->sprite_left_x;
	y = s->sprite_top_y;
	while (x++ < s->sprite_right_x)
	{
		s->texel_width = (s->texture_w / s->sprite_w);
		offset.x = (x - s->sprite_left_x) * s->texel_width;
		y = s->sprite_top_y;
		while (y++ < s->sprite_bottom_y)
		{
			if (x >= 0 && x < screen->x && y > 0 && y < screen->y)
			{
				dist_top = y + (s->sprite_h / 2) - (screen->y / 2);
				offset.y = dist_top * (s->texture_h / s->sprite_h);
				if (s->perp_dist < v->distances_walls[x])
					draw_without_transparancy(v, x, y,
					get_sprite_pixel(v->sprite_tex, s->texture_w, offset));
			}
		}
	}
}

/*
** fix fisheye or not ? perpdist instead of dist for var s->sprite_h
*/

static t_sprite	*calc_sprites(t_vars *v, t_sprite *s)
{
	float	dist_proj_plane;

	dist_proj_plane = ((v->c->resolution->x / 2) / tan(FOV / 2));
	s->perp_dist = s->dist * cos(s->angle);
	s->sprite_h = (TILE_SIZE / (s->dist)) * dist_proj_plane;
	s->sprite_w = s->sprite_h;
	s->sprite_top_y = ((v->c->resolution->y / 2) - (s->sprite_h / 2));
	if (s->sprite_top_y < 0)
		s->sprite_top_y = 0;
	s->sprite_bottom_y = ((v->c->resolution->y / 2) + (s->sprite_h / 2));
	if (s->sprite_bottom_y > v->c->resolution->y)
		s->sprite_bottom_y = v->c->resolution->y;
	s->sprite_angle = atan2(s->y - v->player.p_pos.y, s->x - v->player.p_pos.x);
	s->sprite_angle -= v->player.pa;
	s->sprite_pos_x = tan(s->sprite_angle) * dist_proj_plane;
	s->sprite_left_x = (v->c->resolution->x / 2);
	s->sprite_left_x += s->sprite_pos_x - (s->sprite_w / 2);
	s->sprite_right_x = s->sprite_left_x + s->sprite_w;
	s->texture_w = v->sprite_tex.width;
	s->texture_h = v->sprite_tex.height;
	return (s);
}

void			draw_sprites(t_vars *v)
{
	int		i;

	i = 0;
	while (i < v->nb_sprites)
	{
		if (v->sprites_list[i]->visible == 1)
		{
			v->sprites_list[i] = calc_sprites(v, v->sprites_list[i]);
			display_sprites(v, v->sprites_list[i], v->c->resolution);
		}
		i++;
	}
}
