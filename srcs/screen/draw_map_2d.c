/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:13:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/10 19:19:51 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_cube(t_coord *pos, int size, int color, t_data *img)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = pos->x;
	y = pos->y;
	while (i < size)
	{
		while (j < size)
		{
			if (j >= size - 1 || i >= size - 1 || j < 1 || i < 1)
				my_mlx_pixel_put(img, i + x, j +y, LIGHT_GRAY);
			else
				my_mlx_pixel_put(img, i + x, j + y, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void		draw_player(t_vars *vars, t_coord *pos)
{
	draw_cube(pos, MAP_PLAYER_SIZE, RED, &vars->img);
}

void			draw_minimap(t_vars *vars)
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
			if (ft_strchr("NSEW", line[i][j]))
				draw_cube(&cube, MAP_CUBE_SIZE, GREEN, &vars->img);

			j++;
		}
		j = 0;
		i++;
	}
}

t_coord		*ft_calc_pos_in_map(t_vars *vars)
{
	t_coord	*coord;

	coord = ft_alloc_coord(0, 0);
	coord->x = vars->player_pos.x / MAP_CUBE_SIZE;
	coord->y = vars->player_pos.y / MAP_CUBE_SIZE;
	return (coord);
}

void		ft_init_minimap(t_vars *vars)
{
	int		x_px;
	int		y_px;
	t_coord	*player_pos_map;

	x_px  = vars->c->player_pos->x;
	y_px = vars->c->player_pos->y;
	vars->player_pos.x = x_px * MAP_CUBE_SIZE + (MAP_CUBE_SIZE / 2);
	vars->player_pos.y = y_px * MAP_CUBE_SIZE + (MAP_CUBE_SIZE / 2);
	player_pos_map = ft_calc_pos_in_map(vars);
	vars->c->player_pos = player_pos_map;
	vars->c->map[vars->c->player_pos->y][vars->c->player_pos->x] = '0';
	draw_minimap(vars);
	draw_player(vars, &vars->player_pos);
	ft_draw_img(vars, 0, 0);
}
