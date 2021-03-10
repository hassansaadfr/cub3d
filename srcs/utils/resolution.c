/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:16:48 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/10 01:19:41 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_resolution(char *str)
{
	int		j;

	j = 0;
	while (str[j])
	{
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
