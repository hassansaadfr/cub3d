/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:13:36 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 15:52:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**ft_add_line_in_array(char *line, char **array)
{
	char	**out;
	int		i;

	i = 0;
	while (array && array[i])
		i++;
	out = malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (array && array[i])
	{
		out[i] = ft_strdup(array[i]);
		i++;
	}
	out[i] = ft_strdup(line);
	out[i + 1] = 0;
	free_array_str(array);
	return (out);
}

void		ft_read_array_str(char **array)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			c = array[i][j];
			if (c == 'X')
				ft_printf("\033[1;32m%c\033[1;39m", c);
			else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				ft_printf("\033[1;31m%c\033[1;39m", c);
			else
				ft_printf("\033[1;33m%c\033[1;39m", c);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void		free_array_str(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

int			get_array_size(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char		**ft_copy_arr(char **original)
{
	int		i;
	char	**copy;

	i = 0;
	copy = 0;
	copy = malloc(sizeof(char*) * (get_array_size(original) + 1));
	if (!copy)
		return (NULL);
	while (original && original[i])
	{
		copy[i] = ft_strdup(original[i]);
		i++;
	}
	copy[i] = 0;
	return (copy);
}
