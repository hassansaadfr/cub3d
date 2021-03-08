/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:06:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/08 22:14:39 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_vars *v, t_float_pos pos, char **map)
{
	int		x;
	int		y;

	x = (pos.x / TILE_SIZE);
	y = (pos.y / TILE_SIZE);
	if (x >= 0 && y >= 0 && x < v->map_size.x && y < v->map_size.y)
		return (map[y][x] == '0');
	else
		return (0);
}

void		move_north(t_vars *vars)
{
	t_float_pos	temp;
	float		pdx;
	float		pdy;

	pdx = (vars->player.pdx / TILE_SIZE) * SPEED_MOVE;
	pdy = (vars->player.pdy / TILE_SIZE) * SPEED_MOVE;
	temp.x = vars->player.p_pos.x + pdx;
	temp.y = vars->player.p_pos.y + pdy;
	if (is_wall(vars, temp, vars->c->map))
	{
		vars->player.p_pos.x = temp.x;
		vars->player.p_pos.y = temp.y;
		draw_frame(vars);
	}
	vars->c->player_pos->x = vars->player.p_pos.x;
	vars->c->player_pos->y = vars->player.p_pos.y;
}

void		move_south(t_vars *vars)
{
	t_float_pos	temp;
	float		pdx;
	float		pdy;

	pdx = (vars->player.pdx / TILE_SIZE) * SPEED_MOVE;
	pdy = (vars->player.pdy / TILE_SIZE) * SPEED_MOVE;
	temp.x = vars->player.p_pos.x - pdx;
	temp.y = vars->player.p_pos.y - pdy;
	if (is_wall(vars, temp, vars->c->map))
	{
		vars->player.p_pos.x = temp.x;
		vars->player.p_pos.y = temp.y;
		draw_frame(vars);
	}
	vars->c->player_pos->x = vars->player.p_pos.x;
	vars->c->player_pos->y = vars->player.p_pos.y;
}

void		move_side(t_vars *vars, int direction)
{
	float		pdx;
	float		pdy;
	t_float_pos temp;

	if (direction == EAST_DIRECTION)
	{
		pdx = (cos(vars->player.pa - PI / 2) / TILE_SIZE) * SPEED_MOVE;
		pdy = (sin(vars->player.pa - PI / 2) / TILE_SIZE) * SPEED_MOVE;
	}
	else
	{
		pdx = (cos(vars->player.pa + PI / 2)) / TILE_SIZE * SPEED_MOVE;
		pdy = (sin(vars->player.pa + PI / 2)) / TILE_SIZE * SPEED_MOVE;
	}
	temp.x = vars->player.p_pos.x + pdx;
	temp.y = vars->player.p_pos.y + pdy;
	if (is_wall(vars, temp, vars->c->map))
	{
		vars->player.p_pos.x = temp.x;
		vars->player.p_pos.y = temp.y;
		draw_frame(vars);
	}
	vars->c->player_pos->x = vars->player.p_pos.x;
	vars->c->player_pos->y = vars->player.p_pos.y;
}

void		turn_camera(t_vars *vars, int direction)
{
	float	rot_speed;

	rot_speed = 0.1;
	if (direction == WEST_DIRECTION)
	{
		vars->player.pa += rot_speed;
		if (vars->player.pa > PI * 2)
			vars->player.pa -= 2 * PI;
		vars->player.pdx = cos(vars->player.pa);
		vars->player.pdy = sin(vars->player.pa);
	}
	else
	{
		vars->player.pa -= rot_speed;
		if (vars->player.pa < 0)
			vars->player.pa += 2 * PI;
		vars->player.pdx = cos(vars->player.pa);
		vars->player.pdy = sin(vars->player.pa);
	}
	draw_frame(vars);
	vars->c->player_pos->x = vars->player.p_pos.x;
	vars->c->player_pos->y = vars->player.p_pos.y;
}
