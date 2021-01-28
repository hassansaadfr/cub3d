/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:09:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/28 23:50:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static char		*ft_extract_conf(char *line, int start)
{
	char	*tmp;
	char	*swap;

	tmp = 0;
	swap = 0;
	tmp = ft_strtrim(line, " \t");
	swap = ft_substr(tmp, start, ft_strlen(tmp));
	free(tmp);
	tmp = ft_strtrim(swap, " \t");
	free(swap);
	return (tmp);
}

static void		ft_parse_lines(t_config **config, char *map_line)
{
	char	*line;

	line = ft_strtrim(map_line, " \t");
	if (ft_strncmp("R ", line, 2) == 0)
		ft_parse_resolution(ft_extract_conf(line, 1), config);
	else if (ft_strncmp("S ", line, 2) == 0)
		(*config)->sprite_texture = ft_extract_conf(line, 1);
	else if (ft_strncmp("F ", line, 2) == 0)
		(*config)->f_color = ft_parse_color(line);
	else if (ft_strncmp("C ", line, 2) == 0)
		(*config)->c_color = ft_parse_color(line);
	else if (ft_strncmp("SO", line, 2) == 0)
		(*config)->so_texture = ft_extract_conf(line, 2);
	else if (ft_strncmp("NO", line, 2) == 0)
		(*config)->no_texture = ft_extract_conf(line, 2);
	else if (ft_strncmp("WE", line, 2) == 0)
		(*config)->we_texture = ft_extract_conf(line, 2);
	else if (ft_strncmp("EA", line, 2) == 0)
		(*config)->ea_texture = ft_extract_conf(line, 2);
	free(line);
}

int		ft_parse_map(t_config **config, char **map)
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
	(*config)->map = ft_extract_map(map);
	return (1);
}
