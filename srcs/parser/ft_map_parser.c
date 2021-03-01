/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:09:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/01 14:02:45 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_parse_resolution(char *str, t_config **config)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	(*config)->resolution->x = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	(*config)->resolution->y = ft_atoi(str + i);
	(*config)->resolution->exist = 1;
	free(str);
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

static void		ft_parse_lines(t_config **config, char *map_line)
{
	char	*line;

	line = ft_strtrim(map_line, " \t");
	if (ft_strncmp("R ", line, 2) == 0)
		ft_parse_resolution(ft_extract_conf(line), config);
	else if (ft_strncmp("S ", line, 2) == 0)
		(*config)->sprite_texture = ft_extract_conf(line);
	else if (ft_strncmp("F ", line, 2) == 0)
		ft_parse_color(line, (*config)->f_color);
	else if (ft_strncmp("C ", line, 2) == 0)
		ft_parse_color(line, (*config)->c_color);
	else if (ft_strncmp("SO", line, 2) == 0)
		(*config)->so_texture = ft_extract_conf(line);
	else if (ft_strncmp("NO", line, 2) == 0)
		(*config)->no_texture = ft_extract_conf(line);
	else if (ft_strncmp("WE", line, 2) == 0)
		(*config)->we_texture = ft_extract_conf(line);
	else if (ft_strncmp("EA", line, 2) == 0)
		(*config)->ea_texture = ft_extract_conf(line);
	free(line);
	line = 0;
}

int				ft_parse_map(t_config **config, char **map)
{
	int			i;

	i = 0;
	if (!config)
		return (0);
	while (map[i])
	{
		ft_parse_lines(config, map[i]);
		i++;
	}
	if (!ft_check_struct_color((*config)->c_color))
		return (0);
	if (!ft_check_struct_color((*config)->f_color))
		return (0);
	if ((*config)->resolution->x < 0 || (*config)->resolution->y < 0)
	{
		ft_print_msg("Invalid resolution", ERROR_MSG);
		return (0);
	}
	(*config)->map = ft_extract_map(map);
	return (1);
}
