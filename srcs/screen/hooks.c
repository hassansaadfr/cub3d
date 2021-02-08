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
	static int pos_x = 0;
	static int pos_y = 0;
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	if (keycode == UP)
	{
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y, create_trgb(0,0,0,0));
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y - 1, create_trgb(0,255,100,10));
		pos_y--;
	}
	if (keycode == DOWN)
	{
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y, create_trgb(0,0,0,0));
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y + 1, create_trgb(0,255,100,10));
		pos_y++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
	}

	if (keycode == RIGHT)
	{
		ft_printf("right", WARNING_MSG);
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y, create_trgb(0,0,0,0));
		my_mlx_pixel_put(&(vars->img), pos_x + 1, pos_y, create_trgb(0,255,100,10));
		pos_x++;
	}
	if (keycode == LEFT)
	{
		my_mlx_pixel_put(&(vars->img), pos_x, pos_y, create_trgb(0,0,0,0));
		my_mlx_pixel_put(&(vars->img), pos_x - 1, pos_y, create_trgb(0,255,100,10));
		pos_x--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);

	return (keycode);
}
