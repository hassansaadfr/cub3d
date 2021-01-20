/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:15:36 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 17:23:41 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char			*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*remaining;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	remaining = malloc(sizeof(char) * stot_len);
	if (!remaining)
		return (0);
	ft_memmove(remaining, s1, s1_len);
	ft_memmove(remaining + s1_len, s2, s2_len);
	remaining[stot_len - 1] = '\0';
	free((char *)s1);
	return (remaining);
}

int				get_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char			*get_rest(char *buff)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buff)
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (0);
	}
	if (!(remaining = malloc(sizeof(char) * ((ft_strlen(buff) - i) + 1))))
		return (0);
	i++;
	while (buff[i])
		remaining[j++] = buff[i++];
	remaining[j] = '\0';
	free(buff);
	return (remaining);
}
