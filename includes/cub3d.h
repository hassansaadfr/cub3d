/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:07 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/14 16:36:13 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "constants.h"
# include "struct.h"

# define DEBUG 1

void			ft_errors(char	*err);
void			ft_print_msg(char *str, int color);
void			ft_check_ext(char *path);
int				ft_check_colors(const char *color);
int				ft_parse_color(char *str, t_color *color);
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
int				get_array_size(char **arr);
char			**ft_copy_arr(char **original);
char			**ft_extract_map(char **map);
int				ft_check_struct_color(t_color *color);

int				create_trgb(int t, int r, int g, int b);
int				add_shade(double shade, int color);

void			init_window(t_config *c);
int				key_hook(int keycode, t_vars *vars);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_draw_img(t_vars *vars, int x, int y);
void			ft_set_bg(t_vars *vars);

void			move_north(t_vars *vars);
void			move_south(t_vars *vars);
void			move_east(t_vars *vars);
void			move_west(t_vars *vars);

void			draw_minimap(t_vars *vars);
void			draw_player(t_vars *vars);
void			ft_init_minimap(t_vars *vars);
t_coord			*ft_calc_pos_in_map(t_vars *vars);
void			draw_ray_lines(t_vars *v);
void			draw_cube(t_coord *pos, int size, int color, t_data *img);

void			ft_display_info(t_vars *mlx);


void			drawline(t_coord *start, int end_x, int end_y, t_vars *vars);

#endif
