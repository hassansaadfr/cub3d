/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:57:44 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 15:04:39 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	ft_str_contain_others(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '0' || c == '1' || c == '2' || c == ' ' ||
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	check_double_map(char **map, int i)
{
	char	*trim;
	char	*trimnext;
	int		out;

	out = 1;
	trim = 0;
	if (ft_strlen(map[i]) == 0 && map[i + 1])
	{
		trim = ft_strtrim(map[i + 1], " \t");
		if (ft_strlen(trim) > 0)
		{
			if (map[i + 1])
			{
				trimnext = ft_strtrim(map[i + 1], " \t");
				if (ft_strlen(trimnext) > 0
					&& ft_str_contain_others(map[i]))
					out = ft_print_err("Map contain wrong characters");
				else
					out = ft_print_err("More than one map in file.");
				free(trimnext);
			}
		}
		free(trim);
	}
	return (out);
}

char		**ft_extract_map(char **map)
{
	int		i;
	int		map_size;
	char	**out;

	map_size = 0;
	out = 0;
	i = 8;
	while (map[map_size])
		map_size++;
	if (map_size <= i)
		return (ft_print_error("The file doesnt contain map"));
	while (map[i] && ft_strlen(map[i]) <= 1)
		i++;
	while (map[i])
	{
		if (!check_double_map(map, i) || ft_str_contain_others(map[i]))
		{
			free_array_str(out);
			return (ft_print_error("Map contain wrong characters"));
		}
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
	if (!ft_check_ext(path))
	{
		ft_free_config(config);
		exit(1);
	}
	if (!(map_config = ft_open_and_read(path)))
	{
		ft_print_msg("Map file is invalid", ERROR_MSG);
		ft_free_config(config);
		exit(1);
	}
	if (ft_all_checks(&config, map_config))
		init_window(config);
}

int			ft_all_checks(t_config **c, char **map)
{
	int		(*functions_arr[5])(t_config **c, char **map);
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
		result = (*functions_arr[i])(c, map);
		i++;
	}
	if (!result || !(result = try_load_textures(*c)) || !(*c)->map)
		ft_free_config(*c);
	else
		ft_print_msg("Configuration OK", SUCCESS_MSG);
	free_array_str(map);
	return (result);
}
