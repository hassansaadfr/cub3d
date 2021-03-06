/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:50:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/06 16:38:33 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	get_angle(t_player *p, t_sprite *t)
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

static float	get_dist(t_player *p, t_sprite *sprite)
{
	return (ray_dist(&p->p_pos, sprite->x, sprite->y));
}

void	init_sprites_list(t_vars *v)
{
	v->nb_sprites = 0;
	v->sprites_list = NULL;
	parse_map_sprites(v);
	sort_sprites(v->sprites_list, v->nb_sprites);
}

void		draw_sprites(t_vars *v)
{
	float	sprite_h;
	float	sprite_w;
	float	sprite_top_y;
	float	sprite_bottom_y;
	float	tile_size;
	int		i;
	float	dist_proj_plane;
	float	sprite_angle;
	float	sprite_pos_x;
	float	sprite_left_x;
	float	sprite_right_x;
	int		texture_w;
	int		texture_h;


	dist_proj_plane = ((v->c->resolution->x / 2) / tan(FOV / 2));
	tile_size = 8;
	i = 0;
	while (i < v->nb_sprites)
	{
		if (v->sprites_list[i]->visible == 1)
		{
			sprite_h = (tile_size / v->sprites_list[i]->dist) * dist_proj_plane;
			sprite_w = sprite_h;
			sprite_top_y = ((v->c->resolution->y / 2) - sprite_h / 2);
			if (sprite_top_y < 0)
				sprite_top_y = 0;
			sprite_bottom_y = ((v->c->resolution->y / 2) + sprite_h / 2);
			if (sprite_bottom_y > v->c->resolution->y)
				sprite_bottom_y = v->c->resolution->y;
			sprite_angle = atan2(v->sprites_list[i]->y - v->player.p_pos.y, v->sprites_list[i]->x - v->player.p_pos.x) - v->player.pa;
			sprite_pos_x = tan(sprite_angle) * dist_proj_plane;
			sprite_left_x = v->c->resolution->x / 2 + sprite_pos_x;
			sprite_right_x = sprite_left_x + sprite_w;
			texture_w = v->sprite_tex.width;
			texture_h = v->sprite_tex.height;
			int	textureOffesetX;
			int	textureOffesetY;
			int colorpx;
			for (int x = sprite_left_x; x < sprite_right_x; x++)
			{
				float texelWidth = (texture_w / sprite_w);
				textureOffesetX = (x - sprite_left_x) * texelWidth;
				for (int y = sprite_top_y; y < sprite_bottom_y; y++)
				{
					int		distancefromtop = y + (sprite_h / 2) - (v->c->resolution->y / 2);
					textureOffesetY = distancefromtop * (texture_h / sprite_h);
					colorpx = my_mlx_pixel_get_sprite(v->sprite_tex, texture_w, textureOffesetY, textureOffesetX);
					if (x > 0 && x < v->c->resolution->x && y > 0 && y < v->c->resolution->y)
					{
						if (colorpx != BLACK)
							my_mlx_pixel_put(&v->img, x , y , colorpx);
					}
				}

			}
		}
		i++;
	}
}


void	recalc_sprites_dist(t_vars *v)
{
	int			i;

	i = 0;
	while (i < v->nb_sprites)
	{
		v->sprites_list[i]->dist = get_dist(&v->player, v->sprites_list[i]);
		v->sprites_list[i]->angle = get_angle(&v->player, v->sprites_list[i]);
		if (v->sprites_list[i]->angle < FOV / 2)
			v->sprites_list[i]->visible = 1;
		else
			v->sprites_list[i]->visible = 0;
		i++;
	}
	sort_sprites(v->sprites_list, v->nb_sprites);
	draw_sprites(v);
}
