/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:21:25 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/11/18 19:46:18 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t nb)
{
	size_t		i;
	size_t		j;
	char		*string;

	string = (char*)str;
	i = 0;
	j = 0;
	if (find[0] == '\0')
		return (string);
	while (string[i])
	{
		while (j < nb && find[j] == string[i + j])
		{
			if (ft_strlen(find) + i > nb)
			{
				return (0);
			}
			if (find[j + 1] == '\0' || j == nb)
				return (string + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
