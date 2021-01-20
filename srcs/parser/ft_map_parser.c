/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:09:21 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 23:28:42 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coord	*ft_parse_resolution(char *str)
{
	t_coord	*coord;
	int		i;

	coord = malloc(sizeof(t_coord));
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	coord->x = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	coord->y = ft_atoi(str + i);
	return (coord);
}

static void		ft_parse_lines(char *line, t_config **config)
{
	if (line[0] == 'R')
		(*config)->resolution = ft_parse_resolution(line + 1);
	else if (line[0] == 'S')
		(*config)->sprite_texture = ft_strtrim(line + 1, " \t");
	else if (line[0] == 'F')
		(*config)->floor_color = ft_strtrim(line + 1, " \t");
	else if (line[0] == 'C')
		(*config)->ceiling_color = ft_strtrim(line + 1, " \t");
	else if (ft_strncmp("SO", line, 2) == 0)
		(*config)->so_texture = ft_strtrim(line + 2, " \t");
	else if (ft_strncmp("NO", line, 2) == 0)
		(*config)->no_texture = ft_strtrim(line + 2, " \t");
	else if (ft_strncmp("WE", line, 2) == 0)
		(*config)->we_texture = ft_strtrim(line + 2, " \t");
	else if (ft_strncmp("EA", line, 2) == 0)
		(*config)->ea_texture = ft_strtrim(line + 2, " \t");
}

t_config		*ft_parse_map(char **map)
{
	t_config	*config;
	int			i;
	char		*line;

	i = 0;
	config = malloc(sizeof(t_config));
	if (!config)
	{
		free_array_str(map);
		ft_errors(MALLOC_ERROR);
	}
	while (map[i])
	{
		line = ft_strtrim(map[i], " \t");
		ft_parse_lines(line, &config);
		free(line);
		i++;
	}
	return (config);
}
