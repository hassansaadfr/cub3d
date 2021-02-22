/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:17:05 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/22 14:41:27 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_config(vars->c);
	mlx_loop_end(vars->mlx);
	return (1);
}

int			focus_window(t_vars *vars)
{
	vars->keys.north = 0;
	vars->keys.south = 0;
	vars->keys.east = 0;
	vars->keys.west = 0;
	return (1);
}

int			keypress(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		exit_game(vars);
	if (keycode == UP)
		vars->keys.north = 1;
	if (keycode == DOWN)
		vars->keys.south = 1;
	if (keycode == LEFT)
		vars->keys.east = 1;
	if (keycode == RIGHT)
		vars->keys.west = 1;
	return (keycode);
}

int			keyrelease(int keycode, t_vars *v)
{
	if (keycode == UP)
		v->keys.north = 0;
	if (keycode == DOWN)
		v->keys.south = 0;
	if (keycode == LEFT)
		v->keys.east = 0;
	if (keycode == RIGHT)
		v->keys.west = 0;
	return (1);
}

int			loop_hook(t_vars *v)
{
	if (v->keys.north)
		move_north(v);
	if (v->keys.south)
		move_south(v);
	if (v->keys.east)
		move_east(v);
	if (v->keys.west)
		move_west(v);
	return (1);
}
