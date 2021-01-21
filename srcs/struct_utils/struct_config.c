/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/21 19:24:09 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_free(char *str)
{
	if (str == NULL)
		return ;
	free(str);
}

static int	ft_print_undefined_params(char *name)
{
	ft_print_msg(name, ERROR_MSG);
	return (0);
}

void		ft_free_config(t_config **config)
{
	free((*config)->resolution);
	ft_free((*config)->no_texture);
	ft_free((*config)->so_texture);
	ft_free((*config)->we_texture);
	ft_free((*config)->ea_texture);
	ft_free((*config)->sprite_texture);
	ft_free((*config)->floor_color);
	ft_free((*config)->ceiling_color);
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
	(*config)->resolution = malloc(sizeof(t_coord));
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
