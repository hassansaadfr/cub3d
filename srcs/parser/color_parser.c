/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:32:35 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 14:36:26 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		assign_color(t_color *color, int tmp, int i)
{
	if (i == 0)
		(color)->r = tmp;
	if (i == 1)
		(color)->g = tmp;
	if (i == 2)
		(color)->b = tmp;
}

static int		nb_commas(char *color)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (color[i])
	{
		if (color[i] == ',')
			nb++;
		i++;
	}
	return (nb);
}

static int		ft_check_color_validity(char *color)
{
	int		i;
	char	*tmp;
	int		out;

	i = 0;
	tmp = ft_strtrim(color, " \t");
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		return (-1);
	}
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
	if (color_is_valid(out))
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
	if (color->exist == 1 || nb_commas(str) != 2)
		return (0);
	splitted = ft_split(str, ',');
	while (splitted[i])
	{
		tmp = ft_check_color_validity(splitted[i] + (i == 0));
		assign_color(color, tmp, i);
		i++;
	}
	color->exist = 1;
	color->nb_val = i;
	free_array_str(splitted);
	if (i != 3)
	{
		color->exist = 0;
		color->nb_val = i;
		return (0);
	}
	return (1);
}

int				check_color(t_color *color)
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
