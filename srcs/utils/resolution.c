/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:16:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 15:09:43 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_resolution(char *str)
{
	int		j;
	char	c;

	j = 0;
	while (str[j])
	{
		c = str[j];
		if (ft_isdigit(str[j]) || str[j] == ' ')
			j++;
		else
		{
			ft_print_msg("Invalid resolution", ERROR_MSG);
			return (0);
		}
	}
	return (1);
}

int		check_resolution_content(char **splitted, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (splitted[i][j])
		{
			if (!ft_isdigit(splitted[i][j]))
				return (ft_print_err("Invalid resolution"));
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
