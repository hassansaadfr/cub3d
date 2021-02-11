/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:06:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/11 09:02:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_north(t_vars *vars)
{
	t_coord	*pos;
	char	c;

	vars->player.player_pos.y -= 1;
	pos = ft_calc_pos_in_map(vars);
	c = vars->c->map[pos->y][pos->x];
	if (c == '0')
	{
		vars->c->player_pos = pos;
		draw_minimap(vars);
		draw_player(vars, &vars->player.player_pos);
		ft_draw_img(vars, 0, 0);
	}
	else
		vars->player.player_pos.y += 1;
}

void	move_south(t_vars *vars)
{
	t_coord	*pos;
	char	c;

	vars->player.player_pos.y += MAP_PLAYER_SIZE + 1;
	pos = ft_calc_pos_in_map(vars);
	c = vars->c->map[pos->y][pos->x];
	if (c == '0')
	{
		vars->player.player_pos.y -= MAP_PLAYER_SIZE;
		vars->c->player_pos = pos;
		draw_minimap(vars);
		draw_player(vars, &vars->player.player_pos);
		ft_draw_img(vars, 0, 0);
	}
	else
		vars->player.player_pos.y -= MAP_PLAYER_SIZE + 1;
}

void	move_east(t_vars *vars)
{
	t_coord	*pos;
	char	c;

	vars->player.player_pos.x -= 1;
	pos = ft_calc_pos_in_map(vars);
	c = vars->c->map[pos->y][pos->x];
	if (c == '0')
	{
		vars->c->player_pos = pos;
		draw_minimap(vars);
		draw_player(vars, &vars->player.player_pos);
		ft_draw_img(vars, 0, 0);
	}
	else
		vars->player.player_pos.x += 1;
}

void	move_west(t_vars *vars)
{
	t_coord	*pos;
	char	c;

	vars->player.player_pos.x += MAP_PLAYER_SIZE + 1;
	pos = ft_calc_pos_in_map(vars);
	c = vars->c->map[pos->y][pos->x];
	if (c == '0')
	{
		vars->player.player_pos.x -= MAP_PLAYER_SIZE;
		vars->c->player_pos = pos;
		draw_minimap(vars);
		draw_player(vars, &vars->player.player_pos);
		ft_draw_img(vars, 0, 0);
	}
	else
		vars->player.player_pos.x -= MAP_PLAYER_SIZE + 1;
}
