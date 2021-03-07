/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:50:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 19:50:15 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites_list(t_vars *v)
{
	v->nb_sprites = 0;
	v->sprites_list = NULL;
	parse_map_sprites(v);
	sort_sprites(v->sprites_list, v->nb_sprites);
}

static void	draw_without_transparancy(t_vars *v, int x, int y, int color)
{
	if (color != my_mlx_pixel_get(v->sprite_tex, 0, 0))
		my_mlx_pixel_put(&v->img, x , y , color);
}

void		draw_sprites2(t_vars *v, t_sprite *s)
{
	int		x;
	int		y;
	int		t_off_x;
	int		t_off_y;

	x = s->sprite_left_x;
	y = s->sprite_top_y;
	while (x < s->sprite_right_x)
	{
		s->texel_width = (s->texture_w / s->sprite_w);
		t_off_x = (x - s->sprite_left_x) * s->texel_width;
		while (y < s->sprite_bottom_y)
		{
			if (x >= 0 && x < v->c->resolution->x && y > 0 && y < v->c->resolution->y)
			{
				int distancefromtop = y + (s->sprite_h / 2) - (v->c->resolution->y / 2);
				t_off_y = distancefromtop * (s->texture_h / s->sprite_h);
				if (t_off_x < 0)
					t_off_x = 0;
				if (get_perp_dist(s->dist, s->angle) < v->distances_walls[x])
					draw_without_transparancy(v, x, y,
					get_sprite_pixel(v->sprite_tex, s->texture_w, t_off_y, t_off_x));
			}
			y++;
		}
		x++;
	}
}

void		draw_sprites(t_vars *v)
{
	float	sprite_h;
	float	sprite_w;
	float	sprite_top_y;
	float	sprite_bottom_y;
	int		i;
	float	dist_proj_plane;
	float	sprite_angle;
	float	sprite_pos_x;
	float	sprite_left_x;
	float	sprite_right_x;
	int		texture_w;
	int		texture_h;

	dist_proj_plane = ((v->c->resolution->x / 2) / tan(FOV / 2));
	i = 0;
	while (i < v->nb_sprites)
	{
		if (v->sprites_list[i]->visible == 1)
		{

			float perpdist = v->sprites_list[i]->dist * cos(v->sprites_list[i]->angle);
			sprite_h = (TILE_SIZE / (perpdist)) * dist_proj_plane;
			sprite_w = sprite_h;
			sprite_top_y = ((v->c->resolution->y / 2) - (sprite_h / 2));
			if (sprite_top_y < 0)
				sprite_top_y = 0;
			sprite_bottom_y = ((v->c->resolution->y / 2) + (sprite_h / 2));
			if (sprite_bottom_y > v->c->resolution->y)
				sprite_bottom_y = v->c->resolution->y;
			sprite_angle = atan2(v->sprites_list[i]->y - v->player.p_pos.y, v->sprites_list[i]->x - v->player.p_pos.x) - v->player.pa;
			sprite_pos_x = tan(sprite_angle) * dist_proj_plane;
			sprite_left_x = (v->c->resolution->x / 2) + sprite_pos_x - (sprite_w / 2);
			sprite_right_x = sprite_left_x + sprite_w;
			texture_w = v->sprite_tex.width;
			texture_h = v->sprite_tex.height;
			int	textureOffsetY;
			int colorpx;
			for (int x = sprite_left_x; x < sprite_right_x; x++)
			{
				float texelWidth = (texture_w / sprite_w);
				int textureOffsetX = (x - sprite_left_x) * texelWidth;
				for (int y = sprite_top_y; y < sprite_bottom_y; y++)
				{
					if (x >= 0 && x < v->c->resolution->x && y > 0 && y < v->c->resolution->y)
					{
						int distancefromtop = y + (sprite_h / 2) - (v->c->resolution->y / 2);
						textureOffsetY = distancefromtop * (texture_h / sprite_h);
						if (textureOffsetX < 0)
							textureOffsetX = 0;
						colorpx = get_sprite_pixel(v->sprite_tex, texture_w, textureOffsetY, textureOffsetX);
						if (colorpx != BLACK && perpdist < v->distances_walls[x])
							my_mlx_pixel_put(&v->img, x , y , colorpx);
					}
				}
			}
		}
		i++;
	}
}
