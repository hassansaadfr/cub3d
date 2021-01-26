/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:07 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/26 20:51:39 by hsaadaou         ###   ########.fr       */
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
	int		exist;
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
void			ft_read_array_str(char **array);
char			**ft_add_line_in_array(char *line, char **array);
int				ft_flood_fill(t_coord *player_pos, char **map);

int				ft_check_config(t_config *c);
void			ft_free_config(t_config **config);
int				ft_alloc_config(t_config **config);
t_coord			*ft_alloc_coord(int x, int y);
void			ft_free_coord(t_coord *coord);
int				get_array_size(char **arr);
char			**ft_copy_arr(char **original);

int				ft_get_queue_size(t_coord **arr);
t_coord			*ft_get_last(t_coord **old);
void			ft_free_stack(t_coord **old);
t_coord			**add_to_coord_queue(t_coord **old, int x, int y);

#endif
