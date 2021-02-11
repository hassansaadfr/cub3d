/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/10 16:25:06 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_coord	*get_screen_size(void *mlx, t_coord *res)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(mlx, &x, &y);
	if (res->x > x)
		res->x = x;
	if (res->y > y)
		res->y = y;
	return (res);
}

void init_window(t_config *c)
{
	t_vars	vars;
	int		res_x;
	int		res_y;

	vars.c = c;
	res_x = vars.c->resolution->x;
	res_y = vars.c->resolution->y;
	vars.mlx = mlx_init();
    c->resolution = get_screen_size(vars.mlx, vars.c->resolution);
	vars.win = mlx_new_window(vars.mlx, res_x, res_y, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, res_x, res_y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
						&vars.img.line_length, &vars.img.endian);
	ft_init_minimap(&vars);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
