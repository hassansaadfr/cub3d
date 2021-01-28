/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config_alloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:20:53 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 00:16:33 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord			*ft_alloc_coord(int x, int y)
{
	t_coord		*coord;

	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	coord->exist = 1;
	return (coord);
}

t_color			*ft_alloc_color(void)
{
	t_color		*color;

	color = malloc(sizeof(t_color));
	color->r = -1;
	color->g = -1;
	color->g = -1;
	color->a = 0;
	return (color);
}

t_config		*ft_alloc_config(void)
{
	t_config	*c;

	c = malloc(sizeof(t_config));
	if (!c)
		return (NULL);
	c->f_color = ft_alloc_color();
	c->c_color = ft_alloc_color();
	c->resolution = ft_alloc_coord(0, 0);
	c->player_pos = ft_alloc_coord(0, 0);
	if (!c->resolution || !c->player_pos || !c->f_color || !c->c_color)
		return (NULL);
	c->resolution->exist = 0;
	c->resolution->x = 0;
	c->resolution->y = 0;
	c->no_texture = NULL;
	c->so_texture = NULL;
	c->we_texture = NULL;
	c->ea_texture = NULL;
	c->sprite_texture = NULL;
	c->map = 0;
	return (c);
}
