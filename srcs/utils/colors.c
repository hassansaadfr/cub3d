/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:47:25 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 00:22:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			create_color(t_color *c)
{
	int	color;

	color = create_trgb(c->a, c->r, c->g, c->b);
	return (color);
}

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

int			color_is_valid(int c)
{
	if (c < 0 || c > 255)
		return (0);
	return (1);
}
