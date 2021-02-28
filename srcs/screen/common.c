/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/28 11:39:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		load_texture(t_vars *v, t_tex *t, char *path)
{
	t->img = mlx_xpm_file_to_image(v->mlx, path, &t->width, &t->height);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
						&t->line_length, &t->endian);
}

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

static void		init_keys_struct(t_vars *v)
{
	v->keys.north = 0;
	v->keys.south = 0;
	v->keys.east = 0;
	v->keys.west = 0;
}

void			init_window(t_config *c)
{
	t_vars	vars;

	vars.c = c;
	vars.mlx = mlx_init();
	init_keys_struct(&vars);
	get_map_dimensions(&vars);
	c->resolution = get_screen_size(vars.mlx, vars.c->resolution);
	vars.win = mlx_new_window(vars.mlx, vars.c->resolution->x,
	vars.c->resolution->y, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, vars.c->resolution->x,
	vars.c->resolution->y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
						&vars.img.line_length, &vars.img.endian);
	load_texture(&vars, &vars.no, vars.c->no_texture);
	load_texture(&vars, &vars.so, vars.c->so_texture);
	load_texture(&vars, &vars.ea, vars.c->ea_texture);
	load_texture(&vars, &vars.we, vars.c->we_texture);
	ft_init_minimap(&vars);
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L << 1, keyrelease, &vars);
	mlx_hook(vars.win, 10, 1L << 21, focus_window, &vars);
	mlx_hook(vars.win, 33, 1L << 17, exit_game, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
}
