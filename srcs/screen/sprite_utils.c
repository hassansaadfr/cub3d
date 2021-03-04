/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:06:47 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/04 16:52:15 by hsaadaou         ###   ########.fr       */
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

static void		swap_sprites(t_sprite *xp, t_sprite *yp)
{
	t_sprite temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void			sort_sprites(t_sprite **arr, int n)
{
	int		i;
	int		j;
	int		min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + i;
		while (j < n)
		{
			if (arr[j]->dist < arr[min_idx]->dist)
				min_idx = j;
			j++;
		}
		swap_sprites(arr[min_idx], arr[i]);
		i++;
	}
}

static t_sprite	*create_sprite_coord(float x, float y, t_player p)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->dist = ray_dist(&p.p_pos, sprite->x, sprite->y);
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
				v->sprites_list[i++] = create_sprite_coord(x, y, v->player);
			x++;
		}
		x = 0;
		y++;
	}
}
