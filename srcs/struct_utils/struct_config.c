/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/24 21:26:08 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_print_undefined_params(char *name)
{
	ft_print_msg(name, ERROR_MSG);
	return (0);
}

void		ft_free_config(t_config **config)
{
	free((*config)->resolution);
	if ((*config)->no_texture)
		free((*config)->no_texture);
	if ((*config)->so_texture)
		free((*config)->so_texture);
	if ((*config)->we_texture)
		free((*config)->we_texture);
	if ((*config)->ea_texture)
		free((*config)->ea_texture);
	if ((*config)->sprite_texture)
		free((*config)->sprite_texture);
	if ((*config)->floor_color)
		free((*config)->floor_color);
	if ((*config)->ceiling_color)
		free((*config)->ceiling_color);
	free(*config);
}

int			ft_check_config(t_config *c)
{
	int		res;

	res = 1;
	if (c->no_texture == NULL)
		res = ft_print_undefined_params(NO_UNDEFINED);
	if (c->so_texture == NULL)
		res = ft_print_undefined_params(SO_UNDEFINED);
	if (c->we_texture == NULL)
		res = ft_print_undefined_params(WE_UNDEFINED);
	if (c->ea_texture == NULL)
		res = ft_print_undefined_params(EA_UNDEFINED);
	if (c->sprite_texture == NULL)
		res = ft_print_undefined_params(S_UNDEFINED);
	if (c->floor_color == NULL)
		res = ft_print_undefined_params(F_UNDEFINED);
	if (c->ceiling_color == NULL)
		res = ft_print_undefined_params(C_UNDEFINED);
	if (c->resolution->exist == 0)
		res = ft_print_undefined_params(R_UNDEFINED);
	return (res);
}

int			ft_alloc_config(t_config **config)
{
	*config = malloc(sizeof(t_config));
	if (!*config)
		return (0);
	(*config)->resolution = ft_alloc_coord(0, 0);
	if (!(*config)->resolution)
		return (0);
	(*config)->resolution->exist = 0;
	(*config)->resolution->x = 0;
	(*config)->resolution->y = 0;
	(*config)->no_texture = NULL;
	(*config)->so_texture = NULL;
	(*config)->we_texture = NULL;
	(*config)->ea_texture = NULL;
	(*config)->sprite_texture = NULL;
	(*config)->floor_color = NULL;
	(*config)->ceiling_color = NULL;
	return (1);
}
