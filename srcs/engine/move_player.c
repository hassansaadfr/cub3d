/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:06:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/12 18:18:29 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_player_can_move(t_float_pos pos, char **map)
{
	int		x;
	int		y;

	x = pos.x / MAP_CUBE_SIZE;
	y = pos.y / MAP_CUBE_SIZE;
	return (map[y][x] == '0' || map[y][x] == '2');
}

void		move_north(t_vars *vars)
{
	int	x;
	int	y;

	vars->player.p_pos.x += vars->player.pdx;
	vars->player.p_pos.y += vars->player.pdy;
	x = vars->player.p_pos.x / MAP_CUBE_SIZE;
	y = vars->player.p_pos.y / MAP_CUBE_SIZE;
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

	vars->player.p_pos.x -= vars->player.pdx;
	vars->player.p_pos.y -= vars->player.pdy;
	x = vars->player.p_pos.x / MAP_CUBE_SIZE;
	y = vars->player.p_pos.y / MAP_CUBE_SIZE;
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
	int		i;

	i = 0;
	vars->player.pa -= 0.1;
	if (vars->player.pa < 0)
		vars->player.pa += 2 * PI;
	vars->player.pdx = cos(vars->player.pa) * 5;
	vars->player.pdy = sin(vars->player.pa) * 5;
	draw_player(vars);
}

void		move_west(t_vars *vars)
{
	int		i;

	i = 0;
	vars->player.pa += 0.1;
	if (vars->player.pa > PI * 2)
		vars->player.pa -= 2 * PI;
	vars->player.pdx = cos(vars->player.pa) * 5;
	vars->player.pdy = sin(vars->player.pa) * 5;
	draw_player(vars);
}
