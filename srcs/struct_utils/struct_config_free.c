/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:20:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 16:05:33 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_free_config(t_config *config)
{
	free_array_str(config->map);
	free(config->c_color);
	free(config->f_color);
	free(config->resolution);
	free(config->player_pos);
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
