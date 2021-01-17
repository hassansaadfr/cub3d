/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:43:34 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/11/22 19:23:24 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		s_len;
	size_t		size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	size = s_len <= start ? 1 : len + 1;
	i = 0;
	if (!(str = ft_calloc(size, sizeof(char))))
		return (NULL);
	if (size == 1)
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
