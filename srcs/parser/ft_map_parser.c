/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:09:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 15:09:56 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_check_valid_resolution(char *str)
{
	int		i;
	int		out;
	int		size;
	char	**splitted;

	i = 0;
	out = 0;
	size = 0;
	while (str[i] == ' ')
		i++;
	splitted = ft_split(str + i, ' ');
	size = get_array_size(splitted);
	if (size != 2)
	{
		free_array_str(splitted);
		return (ft_print_err("Invalid resolution"));
	}
	i = 0;
	out = check_resolution_content(splitted, size);
	free_array_str(splitted);
	return (out);
}

static int		ft_parse_resolution(char *str, t_config **config)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((*config)->resolution->exist == 1)
		return (0);
	tmp = ft_strtrim(str, " \t");
	if (!ft_check_valid_resolution(tmp))
	{
		free(tmp);
		return (-1);
	}
	(*config)->resolution->x = ft_atoi(tmp);
	while (ft_isspace(tmp[i]))
		i++;
	while (ft_isdigit(tmp[i]))
		i++;
	(*config)->resolution->y = ft_atoi(tmp + i);
	(*config)->resolution->exist = 1;
	free(tmp);
	return (1);
}

static int		ft_parse_path_file(char **dest, char *line)
{
	int		i;

	i = 0;
	if (*dest != NULL)
	{
		ft_print_msg("Too much parameters in map", ERROR_MSG);
		return (0);
	}
	line = ft_strtrim(line, " \t");
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			free(line);
			return (0);
		}
		i++;
	}
	*dest = ft_strdup(line);
	free(line);
	if (!dest)
		return (0);
	return (1);
}

static int		ft_parse_lines(t_config **config, char *map_line)
{
	char	*line;
	int		err;

	err = 1;
	line = ft_strtrim(map_line, " \t");
	if (ft_strncmp("R ", line, 2) == 0)
		err = ft_parse_resolution(line + 1, config);
	else if (ft_strncmp("F ", line, 2) == 0)
		err = ft_parse_color(line, (*config)->f_color);
	else if (ft_strncmp("C ", line, 2) == 0)
		err = ft_parse_color(line, (*config)->c_color);
	else if (ft_strncmp("S ", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->sprite_texture, line + 2);
	else if (ft_strncmp("SO", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->so_texture, line + 2);
	else if (ft_strncmp("NO", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->no_texture, line + 2);
	else if (ft_strncmp("WE", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->we_texture, line + 2);
	else if (ft_strncmp("EA", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->ea_texture, line + 2);
	free(line);
	line = 0;
	return (err);
}

int				ft_parse_map(t_config **c, char **map)
{
	int			i;
	int			err;

	err = 0;
	i = 0;
	if (!c)
		return (0);
	while (map[i])
	{
		err = ft_parse_lines(c, map[i]);
		if (err == 0)
			return (ft_print_err("Too much params in map."));
		if (err == -1)
			return (0);
		i++;
	}
	if (!check_color((*c)->c_color) || !check_color((*c)->f_color)
		|| !check_undefined_options(*c))
		return (0);
	if ((*c)->resolution->x < 1 || (*c)->resolution->y < 1)
		return (ft_print_err("Invalid resolution"));
	(*c)->map = ft_extract_map(map);
	if (!(*c)->map)
		return (ft_print_err("Invalid map"));
	return (1);
}
