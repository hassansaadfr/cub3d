/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:59:36 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/23 16:27:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

int					get_next_line(int fd, char **line);
int					get_nl(char *str);

char				*join_str(const char *s1, const char *s2);
char				*get_rest(char *buff);

#endif
