/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:49:01 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 00:02:39 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**extract_map_data(int fd, char ***file)
{
	int		i;
	char	*line;
	char	*trimmed_line;

	i = 0;
	while (get_next_line(fd, &line))
	{
		trimmed_line = ft_strtrim(line, " \t");
		if (i < 8 && ft_strlen(trimmed_line) > 0)
			*file = ft_add_line_in_array(trimmed_line, *file);
		else if (i >= 8)
			*file = ft_add_line_in_array(line, *file);
		if (ft_strlen(line) > 0)
			i++;
		free(line);
		free(trimmed_line);
	}
	free(line);
	return (*file);
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

int			ft_can_open_file(char *path)
{
	int		fd;

	fd = 0;
	errno = 0;
	fd = open(path, O_RDWR | O_NOFOLLOW);
	if (errno != 0)
		return (ft_print_err(strerror(errno)));
	if (fd <= 0)
		return (ft_print_err(CANT_OPEN_MAP));
	return (fd);
}

char		**ft_open_and_read(char *path)
{
	int		fd;
	char	**file;

	file = 0;
	fd = ft_can_open_file(path);
	if (!fd)
		return (0);
	extract_map_data(fd, &file);
	close(fd);
	return (file);
}
