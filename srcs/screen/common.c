/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/07 16:34:55 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static t_coord	map_size(char **map)
// {
// 	t_coord size;
// 	int	max_x;
// 	int	total_y;
// 	int	i;

// 	i = 0;
// 	max_x = 0;
// 	total_y = get_array_size(map);
// 	while (map[i])
// 	{
// 		if ((int)ft_strlen(map[i]) > max_x)
// 			max_x = ft_strlen(map[i]);
// 		i++;
// 	}
// 	size.x = max_x;
// 	size.y = total_y;
// 	return (size);
// }

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

	vars.mlx = mlx_init();
    c->resolution = get_screen_size(vars.mlx, c->resolution);
	vars.win = mlx_new_window(vars.mlx, c->resolution->x,c->resolution->y, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, c->resolution->x, c->resolution->y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								 &vars.img.endian);
	//dessine_grille(map_size(c->map), c->resolution, &vars.img);
	draw_2d(c->map, &vars.img);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 30,30);
	//mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
