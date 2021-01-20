/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:07:22 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 16:40:44 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_correct_line(char *str)
{
	int		i;
	char	*remaining;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(remaining = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		remaining[i] = str[i];
		i++;
	}
	remaining[i] = '\0';
	return (remaining);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*rem[4096];
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!get_nl(rem[fd]) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		rem[fd] = join_str(rem[fd], buff);
	}
	free(buff);
	*line = get_correct_line(rem[fd]);
	rem[fd] = get_rest(rem[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
