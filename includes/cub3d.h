/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:07 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/29 14:35:29 by hsaadaou         ###   ########.fr       */
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

# include "../libft/libft.h"

# include "constants.h"

# include <mlx.h>

# define DEBUG 1

typedef struct	s_coord {
	int			x;
	int			y;
	int			exist;
}				t_coord;

typedef struct	s_color {
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;
typedef struct	s_config {
	t_coord		*resolution;
	t_coord		*player_pos;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sprite_texture;
	t_color		*f_color;
	t_color		*c_color;
	char		**map;
}				t_config;

void			ft_errors(char	*err);
void			ft_print_msg(char *str, int color);
void			ft_check_ext(char *path);
int				ft_check_colors(const char *color);
t_color			*ft_parse_color(char *str);
void			ft_launch_game(char *path);
char			**ft_open_and_read(char *path);
void			free_array_str(char **arr);
int				ft_parse_map(t_config **config, char **map);
void			ft_read_array_str(char **array);
char			**ft_add_line_in_array(char *line, char **array);
int				ft_flood_fill(t_config **config, char **map);
int				ft_all_checks(t_config **config, char **map);

int				ft_check_config(t_config **config, char **map);
void			ft_free_config(t_config *config);
t_config		*ft_alloc_config(void);
t_coord			*ft_alloc_coord(int x, int y);
t_color			*ft_alloc_color(void);
void			ft_free_coord(t_coord *coord);
void			ft_free_color(t_color *color);
int				get_array_size(char **arr);
char			**ft_copy_arr(char **original);
char			**ft_extract_map(char **map);

int				create_trgb(int t, int r, int g, int b);

#endif
