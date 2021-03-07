/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:06:47 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 17:52:51 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		sprites_count(char **map)
{
	int		i;
	int		j;
	int		nb_sprites;

	i = 0;
	j = 0;
	nb_sprites = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '2')
				nb_sprites++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nb_sprites);
}

void			sort_sprites(t_sprite **arr, int n)
{
	int			i;
	int			j;
	t_sprite	*temp;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i]->dist < arr[j]->dist)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static t_sprite	*new_sprite_coord(float x, float y, t_float_pos *p)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->x = (x + 0.5) * TILE_SIZE;
	sprite->y = (y + 0.5) * TILE_SIZE;
	sprite->dist = ray_dist(p, sprite->x, sprite->y);
	return (sprite);
}

void			parse_map_sprites(t_vars *v)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	v->sprites_list = malloc(sizeof(t_sprite) * (sprites_count(v->c->map) + 1));
	if (!v->sprites_list)
		return ;
	v->nb_sprites = sprites_count(v->c->map);
	v->sprites_list[v->nb_sprites] = NULL;
	while (v->c->map[y])
	{
		while (v->c->map[y][x])
		{
			if (v->c->map[y][x] == '2')
				v->sprites_list[i++] = new_sprite_coord(x, y, &v->player.p_pos);
			x++;
		}
		x = 0;
		y++;
	}
}

int				sprite_pos_isvisible(t_vars *v, int x, int y)
{
	int		i;
	int		s_x;
	int		s_y;
	int		visible;

	i = 0;
	while (i < v->nb_sprites)
	{
		s_x = v->sprites_list[i]->x / TILE_SIZE;
		s_y = v->sprites_list[i]->y / TILE_SIZE;
		if (s_x == x && s_y == y)
		{
			visible = v->sprites_list[i]->visible;
			if (visible)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
