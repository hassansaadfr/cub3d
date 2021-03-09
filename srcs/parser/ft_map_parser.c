/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:09:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/09 17:03:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_parse_resolution(char *str, t_config **config)
{
	int		i;

	i = 0;
	if ((*config)->resolution->exist)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	(*config)->resolution->x = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	(*config)->resolution->y = ft_atoi(str + i);
	(*config)->resolution->exist = 1;
	free(str);
	return (1);
}

static char		*ft_extract_conf(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*out;

	i = 0;
	j = 0;
	len = 0;
	out = 0;
	while (ft_isalpha(line[i]) || ft_isspace(line[i]))
		i++;
	len = ft_strlen(line + i);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	while (j < len)
	{
		out[j] = line[i + j];
		j++;
	}
	out[j] = 0;
	return (out);
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
			return (0);
		i++;
	}
	*dest = ft_strdup(line);
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
		err = ft_parse_resolution(ft_extract_conf(line), config);
	else if (ft_strncmp("F ", line, 2) == 0)
		ft_parse_color(line, (*config)->f_color);
	else if (ft_strncmp("C ", line, 2) == 0)
		ft_parse_color(line, (*config)->c_color);
	else if (ft_strncmp("S ", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->sprite_texture, line);
	else if (ft_strncmp("SO", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->so_texture, line);
	else if (ft_strncmp("NO", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->no_texture, line);
	else if (ft_strncmp("WE", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->we_texture, line);
	else if (ft_strncmp("EA", line, 2) == 0)
		err = ft_parse_path_file(&(*config)->ea_texture, line);
	free(line);
	line = 0;
	return (err);
}

int				ft_parse_map(t_config **config, char **map)
{
	int			i;
	int			err;

	err = 4;
	i = 0;
	if (!config)
		return (0);
	while (map[i])
	{
		err = ft_parse_lines(config, map[i]);
		if (!err)
			return (ft_print_err("Double params"));
		i++;
	}
	if ((*config)->c_color->nb_val == 3 && (*config)->f_color->nb_val == 3)
	{
		if (!ft_check_struct_color((*config)->c_color))
			return (ft_print_err("Cant find ceiling color"));
		if (!ft_check_struct_color((*config)->f_color))
			return (ft_print_err("Cant find floor color"));
	}
	else
	{
		if ((*config)->c_color->nb_val != 3)
			return (ft_print_err("Invalid ceiling color"));
		if ((*config)->f_color->nb_val != 3)
			return (ft_print_err("Invalid floor color"));
	}
	if ((*config)->resolution->x < 0 || (*config)->resolution->y < 0)
		return (ft_print_err("Invalid resolution"));
	(*config)->map = ft_extract_map(map);
	return (1);
}
