/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:06:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/06 00:13:49 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_player_can_move(t_float_pos pos, char **map)
{
	int		x;
	int		y;

	x = (pos.x / MAP_CUBE_SIZE);
	y = (pos.y / MAP_CUBE_SIZE);
	return (map[y][x] != '1');
}

void		move_north(t_vars *vars)
{
	int	x;
	int	y;

	vars->player.p_pos.x += (vars->player.pdx / MAP_CUBE_SIZE) * SPEED_MOVE;
	vars->player.p_pos.y += (vars->player.pdy / MAP_CUBE_SIZE) * SPEED_MOVE;
	x = vars->player.p_pos.x;
	y = vars->player.p_pos.y;
	if (ft_player_can_move(vars->player.p_pos, vars->c->map))
	{
		vars->c->player_pos->x = x;
		vars->c->player_pos->y = y;
		draw_player(vars);
	}
	else
	{
		vars->player.p_pos.x -= vars->player.pdx;
		vars->player.p_pos.y -= vars->player.pdy;
	}
}

void		move_south(t_vars *vars)
{
	int		x;
	int		y;

	vars->player.p_pos.x -= (vars->player.pdx / MAP_CUBE_SIZE) * SPEED_MOVE;
	vars->player.p_pos.y -= (vars->player.pdy / MAP_CUBE_SIZE) * SPEED_MOVE;
	x = vars->player.p_pos.x;
	y = vars->player.p_pos.y;
	if (ft_player_can_move(vars->player.p_pos, vars->c->map))
	{
		vars->c->player_pos->x = x;
		vars->c->player_pos->y = y;
		draw_player(vars);
	}
	else
	{
		vars->player.p_pos.x += vars->player.pdx;
		vars->player.p_pos.y += vars->player.pdy;
	}
}

void		move_east(t_vars *vars)
{
	float	rot_speed;

	rot_speed = 0.1;
	vars->player.pa -= rot_speed;
	normalize_angle(&vars->player.pa);
	vars->player.pdx = cos(vars->player.pa);
	vars->player.pdy = sin(vars->player.pa);
	draw_player(vars);
}

void		move_west(t_vars *vars)
{
	float	rot_speed;

	rot_speed = 0.1;
	vars->player.pa += rot_speed;
	normalize_angle(&vars->player.pa);
	vars->player.pdx = cos(vars->player.pa);
	vars->player.pdy = sin(vars->player.pa);
	draw_player(vars);
}
