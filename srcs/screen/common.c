/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/14 16:36:29 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_map_dimensions(t_vars *vars)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (vars->c->map[y])
	{
		while (vars->c->map[y][i])
			i++;
		if (i > x)
			x = i;
		i = 0;
		y++;
	}
	vars->map_size.x = x;
	vars->map_size.y = y;
}

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

void			init_window(t_config *c)
{
	t_vars	vars;
	int		res_x;
	int		res_y;

	vars.c = c;

	vars.mlx = mlx_init();
	get_map_dimensions(&vars);
	c->resolution = get_screen_size(vars.mlx, vars.c->resolution);
		res_x = vars.c->resolution->x;
	res_y = vars.c->resolution->y;
	vars.win = mlx_new_window(vars.mlx, res_x, res_y, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, res_x, res_y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
						&vars.img.line_length, &vars.img.endian);
	ft_init_minimap(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
