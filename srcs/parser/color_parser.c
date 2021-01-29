/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:32:35 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 16:05:49 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		ft_check_color_validity(char *color)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(color, " \t");
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			free(tmp);
			return (-1);
		}
		i++;
	}
	free(tmp);
	return (ft_atoi(color));
}

int				ft_parse_color(char *str, t_color *color)
{
	int		i;
	char	**splitted;
	int		tmp;

	tmp = 0;
	i = 0;
	splitted = ft_split(str, ',');
	while (splitted[i])
	{
		if ((tmp = ft_check_color_validity(splitted[i] + 1)) == -1)
			break ;
		if (i == 0)
			(color)->r = tmp;
		if (i == 1)
			(color)->g = tmp;
		if (i == 2)
			(color)->b = tmp;
		i++;
	}
	free_array_str(splitted);
	return (1);
}

static int		color_is_valid(int c)
{
	if (c < 0 || c > 255)
		return (0);
	return (1);
}

int				ft_check_struct_color(t_color *color)
{
	if (!color_is_valid(color->r))
	{
		ft_print_msg("Red color is invalid", ERROR_MSG);
		return (0);
	}
	if (!color_is_valid(color->g))
	{
		ft_print_msg("Green color is invalid", ERROR_MSG);
		return (0);
	}
	if (!color_is_valid(color->r))
	{
		ft_print_msg("Blue color is invalid", ERROR_MSG);
		return (0);
	}
	return (1);
}
