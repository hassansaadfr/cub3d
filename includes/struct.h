/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:00:56 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/30 12:11:29 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

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

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars {
    void		*mlx;
    void		*win;
	t_data		img;
}				t_vars;

#endif