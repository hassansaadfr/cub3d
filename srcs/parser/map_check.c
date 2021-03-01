/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:49:01 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/01 14:20:19 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_color_validity(char *color)
{
	int		i;

	i = 0;
	if (ft_strlen(color) > 3 || ft_strlen(color) == 0)
		return (0);
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (0);
		i++;
	}
	i = ft_atoi(color);
	if (i > 255)
		return (0);
	return (1);
}

int			ft_check_colors(const char *color)
{
	char	**splitted;
	char	*current;
	int		i;

	i = 0;
	splitted = 0;
	splitted = ft_split(color, ',');
	while (splitted[i])
	{
		current = ft_strtrim(splitted[i], " \t");
		if (!ft_check_color_validity(current) || get_array_size(splitted) != 3)
		{
			free(current);
			free_array_str(splitted);
			return (0);
		}
		free(current);
		i++;
	}
	free_array_str(splitted);
	return (1);
}

int			ft_check_ext(char *path)
{
	char	**extension;
	int		name_size;
	int		ext_len;
	int		diff;

	name_size = 0;
	ext_len = 0;
	diff = 0;
	extension = ft_split(path, '.');
	while (extension[name_size])
		name_size++;
	ext_len = ft_strlen(extension[name_size - 1]);
	diff = ft_strncmp("cub", extension[name_size - 1], 4);
	free_array_str(extension);
	if (name_size < 2 || ext_len != 3 || diff != 0)
	{
		ft_print_msg(WRONG_FILE_NAME, ERROR_MSG);
		return (0);
	}
	ft_print_msg(START_MAP_PARSING_MSG, SUCCESS_MSG);
	return (1);
}

char		**ft_open_and_read(char *path)
{
	int		fd;
	char	**file;
	char	*line;
	char	*trimmed_line;

	fd = 0;
	file = 0;
	errno = 0;
	fd = open(path, O_RDWR);
	if (errno != 0)
	{
		ft_print_msg(strerror(errno), ERROR_MSG);
		return (0);
	}
	if (fd < 0)
	{
		ft_print_msg(CANT_OPEN_MAP, ERROR_MSG);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		if ((trimmed_line = ft_strtrim(line, " \t"))[0] != '\0')
			file = ft_add_line_in_array(line, file);
		free(line);
		free(trimmed_line);
	}
	free(line);
	close(fd);
	return (file);
}
