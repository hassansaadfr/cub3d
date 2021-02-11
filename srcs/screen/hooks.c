/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:17:05 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/09 16:27:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_config(vars->c);
		mlx_loop_end(vars->mlx);
		exit(1);
	}
	if (keycode == UP)
		move_north(vars);
	if (keycode == DOWN)
		move_south(vars);
	if (keycode == RIGHT)
		move_west(vars);
	if (keycode == LEFT)
		move_east(vars);
	return (keycode);
}
