/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:13:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/11 09:07:34 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cube(t_coord *pos, int size, int color, t_data *img)
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

void		draw_player(t_vars *vars, t_float_pos *pos)
{
	t_coord coord;

	coord.x = (int)pos->x * MAP_CUBE_SIZE;
	coord.y = (int)pos->y * MAP_CUBE_SIZE;
	draw_cube(&coord, MAP_PLAYER_SIZE, RED, &vars->img);
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
	while (line[i])
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

void		ft_init_minimap(t_vars *vars)
{
	int		x_px;
	int		y_px;

	x_px = vars->c->player_pos->x;
	y_px = vars->c->player_pos->y;
	vars->player.p_pos.x =  vars->c->player_pos->x + 0.5;
	vars->player.p_pos.y =  vars->c->player_pos->y + 0.5;
	vars->c->map[vars->c->player_pos->y][vars->c->player_pos->x] = '0';
	draw_minimap(vars);
	draw_player(vars, &vars->player.p_pos);
	ft_draw_img(vars, 0, 0);
}
