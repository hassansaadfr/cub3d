/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:57:44 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 21:58:17 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_player_pos(t_config **config, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	(void)map;
	(*config)->player_pos->exist = 0;
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
	if ((*config)->player_pos->exist == 1)
		return (1);
	return (0);
}

char		**ft_extract_map(char **map)
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

void		ft_launch_game(char *path)
{
	char		**map_config;
	t_config	*config;

	config = ft_alloc_config();
	ft_check_ext(path);
	map_config = ft_open_and_read(path);
	if (ft_all_checks(&config, map_config))
	{
		init_window(config);
		ft_free_config(config);
	}
}

int			ft_all_checks(t_config **config, char **map)
{
	int		(*functions_arr[5])(t_config **config, char **map);
	int		result;
	int		i;

	result = 1;
	i = 0;
	functions_arr[0] = ft_parse_map;
	functions_arr[1] = ft_get_player_pos;
	functions_arr[2] = ft_check_config;
	functions_arr[3] = ft_flood_fill;
	functions_arr[4] = 0;
	while (functions_arr[i] && result == 1)
	{
		result = (*functions_arr[i])(config, map);
		i++;
	}
	if (!result)
		ft_free_config(*config);
	else
		ft_print_msg("Configuration OK", SUCCESS_MSG);
	free_array_str(map);
	return (result);
}
