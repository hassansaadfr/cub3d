/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:13:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/06 15:22:07 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_cube(t_coord *pos, int size, int color, t_data *img)
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

void			draw_minimap(t_vars *vars)
{
	int		i;
	int		j;
	char	**line;
	t_coord	cube;
	char *l;

	i = 0;
	j = 0;
	line = vars->c->map;
	while (line[i] && DEBUG == 2)
	{
		l = line[i];
		while (line[i][j])
		{
			cube.x = MAP_TILE_SIZE * j;
			cube.y = MAP_TILE_SIZE * i;
			if (line[i][j] == '1')
				draw_cube(&cube, MAP_TILE_SIZE, BLACK, &vars->img);
			if (line[i][j] == '0')
				draw_cube(&cube, MAP_TILE_SIZE, WHITE, &vars->img);
			if (line[i][j] == '2')
				draw_cube(&cube, MAP_TILE_SIZE, sprite_pos_isvisible(vars, j, i) ? RED : ORANGE, &vars->img);
			if (j < (int)ft_strlen(line[i]) - 1)
				j++;
			else
				break ;
		}
		j = 0;
		i++;
	}
}

void			draw_player(t_vars *vars)
{
	t_coord coord;

	coord.x = vars->player.p_pos.x;
	coord.y = vars->player.p_pos.y;
	draw_ray_lines(vars);
	recalc_sprites_dist(vars);
	ft_display_info(vars);
	ft_draw_img(vars, 0, 0);
	printf("pa %f\n",vars->player.pa);
	if (DEBUG == 2)
	{
		coord.x = (vars->player.p_pos.x / TILE_SIZE) * MAP_TILE_SIZE;
		coord.y = (vars->player.p_pos.y / TILE_SIZE) * MAP_TILE_SIZE;
		draw_cube(&coord, MAP_TILE_SIZE / 2, RED, &vars->img);
	}
}

void			ft_init_minimap(t_vars *vars)
{
	char	direction;
	t_coord	*player_pos;

	init_sprites_list(vars);
	player_pos = vars->c->player_pos;
	direction = vars->c->map[player_pos->y][player_pos->x];
	vars->player.p_pos.x = (player_pos->x + 0.5) * TILE_SIZE;
	vars->player.p_pos.y = (player_pos->y + 0.5) * TILE_SIZE;
	vars->c->map[player_pos->y][player_pos->x] = '0';
	if (direction == 'N')
		vars->player.pa = 3 * (PI / 2);
	if (direction == 'S')
		vars->player.pa = (PI / 2);
	if (direction == 'E')
		vars->player.pa = 2 * PI;
	if (direction == 'W')
		vars->player.pa = PI;
	vars->player.pdx = cos(vars->player.pa) * 5;
	vars->player.pdy = sin(vars->player.pa) * 5;
	draw_player(vars);
}
