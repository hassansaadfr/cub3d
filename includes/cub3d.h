/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:07 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 22:18:20 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/ft_printf/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

# include "constants.h"

typedef struct	s_coord {
	int		x;
	int		y;
}				t_coord;
typedef struct	s_config {
	t_coord	*resolution;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sprite_texture;
	char	*floor_color;
	char	*ceiling_color;
}				t_config;

void			ft_errors(char	*err);
void			ft_print_msg(char *str, int color);
void			ft_check_ext(char *path);
void			ft_launch_game(char *path);
char			**ft_open_and_read(char *path);
void			free_array_str(char **arr);
t_config		*ft_parse_map(char **map);

#endif
