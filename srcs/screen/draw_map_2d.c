/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:13:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/22 00:20:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_cube(t_coord *pos, int size, int color, t_data *img)
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

void		draw_minimap(t_vars *vars)
{
	int		i;
	int		j;
	char	**line;
	t_coord	cube;

	i = 0;
	j = 0;
	line = vars->c->map;
	while (DEBUG == 1 && line[i])
	{
		while (line[i][j])
		{
			cube.x = MAP_CUBE_SIZE * j;
			cube.y = MAP_CUBE_SIZE * i;
			if (line[i][j] == '1')
				draw_cube(&cube, MAP_CUBE_SIZE, BLACK, &vars->img);
			if (line[i][j] == '0')
				draw_cube(&cube, MAP_CUBE_SIZE, WHITE, &vars->img);
			if (line[i][j] == '2')
				draw_cube(&cube, MAP_CUBE_SIZE, ORANGE, &vars->img);
			j++;
		}
		j = 0;
		i++;
	}
}

void		draw_player(t_vars *vars)
{
	t_coord coord;

	coord.x = vars->player.p_pos.x;
	coord.y = vars->player.p_pos.y;
	draw_minimap(vars);
	draw_ray_lines(vars);
	ft_draw_img(vars, 0, 0);
	if (DEBUG == 1)
	{
		ft_display_info(vars);
		coord.x = (vars->player.p_pos.x - MAP_CUBE_SIZE / 4);
		coord.y = (vars->player.p_pos.y - MAP_CUBE_SIZE / 4);
		draw_cube(&coord, MAP_PLAYER_SIZE, RED, &vars->img);
	}
}

void		ft_init_minimap(t_vars *vars)
{
	char	direction;
	t_coord	*player_pos;

	player_pos = vars->c->player_pos;
	direction = vars->c->map[player_pos->y][player_pos->x];
	vars->player.p_pos.x = (player_pos->x + 0.5) * MAP_CUBE_SIZE;
	vars->player.p_pos.y = (player_pos->y + 0.5) * MAP_CUBE_SIZE;
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
