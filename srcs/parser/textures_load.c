/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:14:59 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/01 16:16:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	msg_load_texture(char *path, char *msg)
{
	int		err;

	err = 0;
	err = ft_can_open_file(path);
	if (!err)
	{
		ft_print_msg(msg, ERROR_MSG);
		return (0);
	}
	return (1);
}

int			try_load_textures(t_config *c)
{
	int		err;

	err = 0;
	err = msg_load_texture(c->no_texture, "Can't load north texture");
	if (!err)
		return (0);
	err = msg_load_texture(c->so_texture, "Can't load south texture");
	if (!err)
		return (0);
	err = msg_load_texture(c->ea_texture, "Can't load east texture");
	if (!err)
		return (0);
	err = msg_load_texture(c->we_texture, "Can't load west texture");
	if (!err)
		return (0);
	err = msg_load_texture(c->sprite_texture, "Can't load sprite texture");
	if (!err)
		return (0);
	return (1);
}
