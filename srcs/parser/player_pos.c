/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:31:19 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/02 19:34:01 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_if_player_pos_already_exist(int exist)
{
	if (exist > 1)
		return (ft_print_err("Multiple player position."));
	if (exist < 0)
		return (ft_print_err("Cant find player starting position"));
	return (1);
}

int			ft_get_player_pos(t_config **config, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	(void)map;
	(*config)->player_pos->exist = 0;
	if (!(*config)->map)
		return (0);
	while ((*config)->map[y])
	{
		while ((*config)->map[y][x])
		{
			if (ft_strrchr("NSEW", (*config)->map[y][x]))
			{
				(*config)->player_pos->x = x;
				(*config)->player_pos->y = y;
				(*config)->player_pos->exist++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (check_if_player_pos_already_exist((*config)->player_pos->exist));
}
