/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:24:08 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/11/21 17:32:30 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	size;
	char			*start;
	char			*end;
	char			*dest;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	start = (char *)&s1[i];
	if ((i = ft_strlen((char*)s1) - 1) != -1)
		while (i >= 0 && ft_is_in_set(s1[i], set))
			i--;
	end = (char *)&s1[i];
	if (!*s1 || end == start)
		size = 2;
	else
		size = end - start + 2;
	if (!(dest = malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(dest, start, size);
	return (dest);
}
