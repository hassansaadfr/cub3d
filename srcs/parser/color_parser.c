/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:32:35 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/09 22:42:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_check_color_validity(char *color)
{
	int		i;
	char	*tmp;
	int		out;

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
	out = ft_atoi(color);
	if (out >= 0 && out <= 255)
		return (out);
	return (-1);
}

int				ft_parse_color(char *str, t_color *color)
{
	int		i;
	char	**splitted;
	int		tmp;

	tmp = 0;
	i = 0;
	splitted = ft_split(str, ',');
	if (color->exist)
		return (0);
	while (splitted[i])
	{
		tmp = ft_check_color_validity(splitted[i] + (i == 0));
		if (i == 0)
			(color)->r = tmp;
		if (i == 1)
			(color)->g = tmp;
		if (i == 2)
			(color)->b = tmp;
		i++;
	}
	color->exist = 1;
	color->nb_val = i;
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
	if (color->exist != 1)
		return (ft_print_err("A color is missing"));
	if (color->nb_val != 3)
		return (ft_print_err("Color is incomplete"));
	if (!color_is_valid(color->r))
		return (ft_print_err("Red color is invalid"));
	if (!color_is_valid(color->g))
		return (ft_print_err("Green color is invalid"));
	if (!color_is_valid(color->b))
		return (ft_print_err("Blue color is invalid"));
	return (1);
}
