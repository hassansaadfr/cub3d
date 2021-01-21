/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:57:44 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/21 19:39:57 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coord	*ft_get_player_pos(char **map, t_coord *player_pos)
{
	int		x;
	int		y;

	player_pos = malloc(sizeof(t_coord));
	if (!player_pos)
		return (player_pos);
	x = 0;
	y = 0;
	player_pos->exist = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (ft_strrchr("NSEW", map[y][x]))
			{
				player_pos->x = x;
				player_pos->y = y;
				player_pos->exist++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (player_pos);
}

static char		**ft_extract_map(char **map)
{
	int		i;
	char	**out;

	out = 0;
	i = 8;
	while (map[i])
	{
		out = ft_add_line_in_array(map[i], out);
		i++;
	}
	return (out);
}

void			ft_launch_game(char *path)
{
	char		**map_config;
	char		**map;
	t_config	*config;
	t_coord		*player_pos;

	map = 0;
	player_pos = 0;
	ft_check_ext(path);
	map_config = ft_open_and_read(path);
	config = ft_parse_map(map_config);
	if (!ft_check_config(config))
	{
		ft_free_config(&config);
		ft_errors("The map is invalid.");
	}
	else
	{
		ft_print_msg("Configuration OK", SUCCESS_MSG);
		map = ft_extract_map(map_config);
		ft_read_array_str(map);
		player_pos = ft_get_player_pos(map, player_pos);
	}
	ft_free_config(&config);
	free_array_str(map_config);
	free_array_str(map);
}
