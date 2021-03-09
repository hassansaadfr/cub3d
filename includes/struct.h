/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:00:56 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/09 13:10:07 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct	s_coord {
	int			x;
	int			y;
	int			exist;
}				t_coord;

typedef struct	s_pos {
	float		x;
	float		y;
}				t_float_pos;

typedef struct	s_color {
	int			r;
	int			g;
	int			b;
	int			a;
	int			nb_val;
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

typedef struct	s_tex
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	char		*path;
}				t_tex;

typedef struct	s_wall
{
	float		line_h;
	float		line_o;
}				t_wall;

typedef struct	s_player {
	float		pa;
	float		pdx;
	float		pdy;
	t_float_pos	p_pos;
	t_wall		wall;
}				t_player;

typedef struct	s_keys {
	int			north;
	int			south;
	int			rotate_east;
	int			rotate_west;
	int			move_east;
	int			move_west;
}				t_keys;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		dist;
	float		angle;
	int			visible;
	float		sprite_h;
	float		sprite_w;
	float		sprite_top_y;
	float		sprite_bottom_y;
	float		sprite_angle;
	float		sprite_pos_x;
	float		sprite_left_x;
	float		sprite_right_x;
	int			texture_w;
	int			texture_h;
	float		texel_width;
	float		perp_dist;
}				t_sprite;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_config	*c;
	t_player	player;
	t_sprite	**sprites_list;
	int			nb_sprites;
	t_coord		map_size;
	t_keys		keys;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
	t_tex		sprite_tex;
	float		*distances_walls;
}				t_vars;

typedef struct	s_ray {
	float		atan;
	float		ntan;
	int			dof;
	float		ra;
	int			mxh;
	int			myh;
	float		rxh;
	float		ryh;
	float		xoh;
	float		yoh;
	int			mxv;
	int			myv;
	float		rxv;
	float		ryv;
	float		xov;
	float		yov;
	float		disth;
	float		hx;
	float		hy;
	float		distv;
	float		vx;
	float		vy;
	float		final_dist;
	float		impact_pos_v;
	float		impact_pos_h;
	float		actual_impact_pos;
}				t_ray;

typedef struct	s_dda_line
{
	t_coord		delta;
	t_float_pos	inc;
	int			steps;
	float		x;
	float		y;
}				t_dda_line;

#endif
