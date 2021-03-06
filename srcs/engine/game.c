/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:04:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 18:51:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			load_texture(t_vars *v, t_tex *t, char *path)
{
	t->img = mlx_xpm_file_to_image(v->mlx, path, &t->width, &t->height);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
						&t->line_length, &t->endian);
}

void			draw_frame(t_vars *vars)
{
	vars->c->player_pos->x = vars->player.p_pos.x;
	vars->c->player_pos->y = vars->player.p_pos.y;
	raycast(vars);
	recalc_sprites_dist(vars);
	ft_draw_img(vars, 0, 0);
}

void			init_game_config(t_vars *vars)
{
	char	direction;
	t_coord	*player_pos;

	player_pos = vars->c->player_pos;
	direction = vars->c->map[player_pos->y][player_pos->x];
	vars->player.p_pos.x = (player_pos->x + 0.5) * TILE_SIZE;
	vars->player.p_pos.y = (player_pos->y + 0.5) * TILE_SIZE;
	vars->c->map[player_pos->y][player_pos->x] = '0';
	if (direction == 'N')
		vars->player.pa = 3 * (PI / 2);
	if (direction == 'S')
		vars->player.pa = (PI / 2);
	if (direction == 'E')
		vars->player.pa = 2 * PI;
	if (direction == 'W')
		vars->player.pa = PI;
	vars->player.pdx = cos(vars->player.pa) * 5;
	vars->player.pdy = sin(vars->player.pa) * 5;
	init_sprites_list(vars);
	draw_frame(vars);
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
	load_texture(&vars, &vars.sprite_tex, vars.c->sprite_texture);
	load_texture(&vars, &vars.no, vars.c->no_texture);
	load_texture(&vars, &vars.so, vars.c->so_texture);
	load_texture(&vars, &vars.ea, vars.c->ea_texture);
	load_texture(&vars, &vars.we, vars.c->we_texture);
	init_game_config(&vars);
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 3, 1L << 1, keyrelease, &vars);
	mlx_hook(vars.win, 10, 1L << 21, focus_window, &vars);
	mlx_hook(vars.win, 33, 1L << 17, exit_game, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
}
