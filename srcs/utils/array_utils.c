/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:13:36 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/26 20:26:00 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
