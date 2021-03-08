/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:17:05 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/08 16:02:34 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->no.img);
	mlx_destroy_image(vars->mlx, vars->so.img);
	mlx_destroy_image(vars->mlx, vars->ea.img);
	mlx_destroy_image(vars->mlx, vars->we.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_config(vars->c);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	exit(1);
	return (1);
}

int			focus_window(t_vars *vars)
{
	vars->keys.north = 0;
	vars->keys.south = 0;
	vars->keys.rotate_east = 0;
	vars->keys.rotate_west = 0;
	vars->keys.move_east = 0;
	vars->keys.move_west = 0;
	return (1);
}

int			keypress(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		exit_game(vars);
	if (keycode == UP || keycode == W)
		vars->keys.north = 1;
	if (keycode == DOWN || keycode == S)
		vars->keys.south = 1;
	if (keycode == A)
		vars->keys.move_east = 1;
	if (keycode == D)
		vars->keys.move_west = 1;
	if (keycode == LEFT)
		vars->keys.rotate_east = 1;
	if (keycode == RIGHT)
		vars->keys.rotate_west = 1;
	return (keycode);
}

int			keyrelease(int keycode, t_vars *vars)
{
	if (keycode == UP || keycode == W)
		vars->keys.north = 0;
	if (keycode == DOWN || keycode == S)
		vars->keys.south = 0;
	if (keycode == A)
		vars->keys.move_east = 0;
	if (keycode == D)
		vars->keys.move_west = 0;
	if (keycode == LEFT)
		vars->keys.rotate_east = 0;
	if (keycode == RIGHT)
		vars->keys.rotate_west = 0;
	return (1);
}

int			loop_hook(t_vars *v)
{
	if (v->keys.north)
		move_north(v);
	if (v->keys.south)
		move_south(v);
	// if (v->keys.move_east)
	// 	move_side(v, EAST_DIRECTION);
	if (v->keys.rotate_east)
		turn_camera(v, EAST_DIRECTION);
	if (v->keys.rotate_west)
		turn_camera(v, WEST_DIRECTION);
	return (1);
}
