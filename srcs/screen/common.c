/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/03 16:14:20 by hsaadaou         ###   ########.fr       */
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

// static t_coord	*get_screen_size(void *mlx, t_coord *res)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	mlx_get_screen_size(mlx, &x, &y);
// 	if (res->x > x)
// 		res->x = x;
// 	if (res->y > y)
// 		res->y = y;
// 	return (res);
// }

int	dessine(void *param)
{
	t_vars *vars = ((t_vars*)&param);
	t_data *img = &vars->img;
	// t_vars *vars = param;
	// t_data *win= vars->win;
	my_mlx_pixel_put(qimg, 10, 101, create_trgb(0,255,200,0));
	my_mlx_pixel_put(img, 11, 102, create_trgb(0,255,20,0));
	my_mlx_pixel_put(img, 12, 103, create_trgb(0,255,20,0));
	my_mlx_pixel_put(img, 13, 104, create_trgb(0,1,20,0));
	my_mlx_pixel_put(img, 14, 105, create_trgb(0,0,200,0));
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	return (0);
}

void init_window(t_config *c)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, c->resolution->x,c->resolution->y, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, c->resolution->x, c->resolution->y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								 &vars.img.endian);
	// dessine_grille(map_size(c->map), c->resolution, &vars.img);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, dessine, &vars);
	mlx_loop(vars.mlx);
}
