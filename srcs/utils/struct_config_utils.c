/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_config_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:20:47 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 16:05:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_print_undefined_params(char *name)
{
	ft_print_msg(name, ERROR_MSG);
	return (0);
}

static int		ft_check_undefined_params(t_config *c)
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
	if (c->f_color == NULL)
		res = ft_print_undefined_params(F_UNDEFINED);
	if (c->c_color == NULL)
		res = ft_print_undefined_params(C_UNDEFINED);
	if (c->resolution->exist == 0)
		res = ft_print_undefined_params(R_UNDEFINED);
	return (res);
}

int				ft_check_config(t_config **config, char **map)
{
	(void)map;
	return (ft_check_undefined_params(*config));
}
