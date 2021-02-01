/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:17:05 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/01 01:22:12 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("hook %d\n", keycode);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// mlx_loop_end(vars->mlx); Only for linux
	}
	if (keycode == DOWN)
	{
		int i = 100;
		int j = 100;
		while (i < 900)
		{
			my_mlx_pixel_put(&(vars->img), i, j, create_trgb(0,255,100,10));
			i++;
			j++;
		}
	}
	return (keycode);
}
