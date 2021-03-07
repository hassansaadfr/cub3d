/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:59:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 21:34:13 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_cube(t_coord *pos, int size, int color, t_data *img)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < size)
	{
		while (x < size)
		{
			if (x >= size - 1 || y >= size - 1 || x < 1 || y < 1)
				my_mlx_pixel_put(img, y + pos->x, x + pos->y, LIGHT_GRAY);
			else
				my_mlx_pixel_put(img, y + pos->x, x + pos->y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

static int		sprite_color(t_vars *v, int i, int j)
{
	if (sprite_pos_isvisible(v, j, i) == 1)
		return (RED);
	return (ORANGE);
}

static void		display_minimap(t_vars *vars)
{
	int		i;
	int		j;
	int		size;
	t_coord	cube;

	i = 0;
	j = 0;
	size = MAP_TILE_SIZE;
	while (vars->c->map[i] && DEBUG == 2)
	{
		while (vars->c->map[i][j])
		{
			cube.x = size * j;
			cube.y = size * i;
			if (vars->c->map[i][j] == '1')
				draw_cube(&cube, size, BLACK, &vars->img);
			if (vars->c->map[i][j] == '0')
				draw_cube(&cube, size, WHITE, &vars->img);
			if (vars->c->map[i][j] == '2')
				draw_cube(&cube, size, sprite_color(vars, i, j), &vars->img);
			j++;
		}
		j = 0;
		i++;
	}
}

static void		free_rays(t_vars *v, t_coord **rays)
{
	int		i;

	i = 0;
	while (i < v->c->resolution->x)
	{
		free(rays[i]);
		i++;
	}
	free(rays);
	rays = 0;
}

void			draw_minimap(t_vars *v, t_coord **rays)
{
	int		i;
	t_coord	*c;
	t_coord	coord;
	t_coord	r_p;

	if (DEBUG)
	{
		display_minimap(v);
		i = 0;
		coord.x = (v->player.p_pos.x / TILE_SIZE) * MAP_TILE_SIZE;
		coord.y = (v->player.p_pos.y / TILE_SIZE) * MAP_TILE_SIZE;
		while (i < v->c->resolution->x)
		{
			r_p.x = (rays[i]->x / TILE_SIZE) * MAP_TILE_SIZE + (MAP_TILE_SIZE);
			r_p.y = (rays[i]->y / TILE_SIZE) * MAP_TILE_SIZE + (MAP_TILE_SIZE);
			c = rays[i];
			if (DEBUG == 2)
				if (i == 0 || i == v->c->resolution->x - 1)
					drawline(&coord, &r_p, RED, v);
			i++;
		}
		draw_cube(&coord, MAP_TILE_SIZE / 2, RED, &v->img);
		ft_display_info(v);
	}
	free_rays(v, rays);
}
