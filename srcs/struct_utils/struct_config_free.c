/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:20:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 00:23:30 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_free_config(t_config *config)
{
	free_array_str(config->map);
	ft_free_color(config->c_color);
	ft_free_color(config->f_color);
	ft_free_coord(config->resolution);
	ft_free_coord(config->player_pos);
	if (config->no_texture)
		free(config->no_texture);
	if (config->so_texture)
		free(config->so_texture);
	if (config->we_texture)
		free(config->we_texture);
	if (config->ea_texture)
		free(config->ea_texture);
	if (config->sprite_texture)
		free(config->sprite_texture);
	free(config);
}

void		ft_free_coord(t_coord *coord)
{
	free(coord);
	coord = 0;
}

void		ft_free_color(t_color *color)
{
	free(color);
	color = 0;
}
