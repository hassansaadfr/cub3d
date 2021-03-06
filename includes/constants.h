/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:12:58 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/11 11:29:38 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H

# define CONSTANTS_H

# define DEBUG 0

# define INVALID_ARGS "Usage : ./cub3d <map.cub> [--save]"
# define TOO_MUCH_ARGS "Too much args"
# define INVALID_MAP "Invalid map"
# define WRONG_FILE_NAME "Not a valid .cub file."
# define CANT_OPEN_FILE "Can't open file"
# define CANT_OPEN_MAP "Can't open the map"
# define MALLOC_ERROR "Error during memory allocation"

# define NO_UNDEFINED "Path to north texture is not defined"
# define SO_UNDEFINED "Path to south texture is not defined"
# define WE_UNDEFINED "Path to west texture is not defined"
# define EA_UNDEFINED "Path to east texture is not defined"
# define S_UNDEFINED "Path to sprite texture is not defined"
# define F_UNDEFINED "Floor color is not defined"
# define C_UNDEFINED "Ceiling color is not defined"
# define R_UNDEFINED "The map resolution is not defined"

# define F_INVALID "Floor color is not valid"
# define C_INVALID "Ceiling color is not valid"

# define START_MAP_PARSING_MSG "Parsing the map please wait"

# define STANDARD_MSG 2
# define SUCCESS_MSG 1
# define WARNING_MSG 0
# define ERROR_MSG -1
# define CLEAR_CONSOLE -2

# define EAST_DIRECTION 1
# define WEST_DIRECTION 2

# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define Z 122
# define Q 113
# define S 115
# define D 100
# define W 119
# define A 97

# define WHITE 0xffffff
# define BLACK 0x0
# define RED 0xff0000
# define GREEN 0xff00
# define YELLOW 0xffff00
# define ORANGE 0xffa500
# define BLUE 0x2F32FF
# define DARK_BLUE 0x2F327A
# define LIGHT_GRAY 0xd3d3d3

# define TILE_SIZE 8
# define MAP_TILE_SIZE 20
# define SPEED_MOVE 6

# define PI 3.1415926535
# define DR 0.0174533
# define FOV 1.0471975512

# define BYTES_FORMAT 24
# define BMP_FILE_NAME "save.bmp"

#endif
