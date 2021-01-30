/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:17:05 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/30 12:23:52 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("hook %d\n", keycode);
	if (keycode == ESCAPE)
	{
		 mlx_destroy_window(vars->mlx, vars->win);
		 system("leaks cub3D");
	}
	if (keycode == 126)
	{
		int i = 0;
		int j = 0;
		while (i < 900)
		{
			my_mlx_pixel_put(&(vars->img), i, j, create_trgb(0,255,100,10));
			i++;
			j++;
		}
	}
	return (keycode);
}
