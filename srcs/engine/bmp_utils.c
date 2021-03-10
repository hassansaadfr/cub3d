/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:07:16 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 18:56:18 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		exit_free(t_vars *vars)
{
	int		i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->no.img);
	mlx_destroy_image(vars->mlx, vars->so.img);
	mlx_destroy_image(vars->mlx, vars->ea.img);
	mlx_destroy_image(vars->mlx, vars->we.img);
	mlx_destroy_image(vars->mlx, vars->sprite_tex.img);
	mlx_destroy_display(vars->mlx);
	ft_free_config(vars->c);
	free(vars->mlx);
	while (i < vars->nb_sprites)
	{
		free(vars->sprites_list[i]);
		i++;
	}
	free(vars->sprites_list);
	exit(1);
	return (1);
}

int				bmp(t_config *c)
{
	t_vars	vars;

	vars.c = c;
	vars.mlx = mlx_init();
	init_keys_struct(&vars);
	get_map_dimensions(&vars);
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
	if (save_bmp(&vars.img, *vars.c->resolution))
		ft_print_msg("file save.bmp created.", SUCCESS_MSG);
	exit_free(&vars);
	return (1);
}

t_bmp			convert_trgb_to_bmp(t_data *img, int x, int y)
{
	t_bmp		pixel_color;
	int			color;
	char		*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	pixel_color.r = (color & 0xFFFF00) >> 16;
	pixel_color.g = (color & 0xFF00) >> 8;
	pixel_color.b = color & 0xFF;
	return (pixel_color);
}

int				get_correction_byte(int image_width)
{
	char	correction_byte[4];

	correction_byte[0] = 0;
	correction_byte[1] = 3;
	correction_byte[2] = 2;
	correction_byte[3] = 1;
	return (correction_byte[(int)(3 * image_width) % 4]);
}
