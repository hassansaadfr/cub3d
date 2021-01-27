/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:49:01 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/27 18:09:11 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_check_ext(char *path)
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
		ft_errors(WRONG_FILE_NAME);
	ft_print_msg(START_MAP_PARSING_MSG, SUCCESS_MSG);
}

char		**ft_open_and_read(char *path)
{
	int		fd;
	char	**file;
	char	*line;
	char	*trimmed_line;

	fd = 0;
	file = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_errors(CANT_OPEN_MAP);
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
