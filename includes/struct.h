/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:00:56 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/27 12:19:19 by hsaadaou         ###   ########.fr       */
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

typedef struct	s_player {
	float		pa;
	float		pdx;
	float		pdy;
	t_float_pos	p_pos;
}				t_player;

typedef struct	s_keys {
	int		north;
	int		south;
	int		east;
	int		west;
}				t_keys;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_config	*c;
	t_player	player;
	t_coord		map_size;
	t_keys		keys;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
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

typedef struct s_wall
{
	float	lineH;
	float	lineO;
	int		wall_width;
	int		wall_height;
}				t_wall;

typedef struct s_dda_line
{
	t_coord		delta;
	t_float_pos	inc;
	int			steps;
	float		x;
	float		y;
}				t_dda_line;

#endif
