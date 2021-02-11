/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:12:58 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/10 20:25:59 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H

# define CONSTANTS_H

# define INVALID_ARGS "Usage : ./cub3d [--save] <map.cub>"
# define TOO_MUCH_ARGS "Too much args"
# define INVALID_MAP "Invalid map"
# define WRONG_FILE_NAME "Not a valid .cub file."
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

# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

# define WHITE 0xffffff
# define BLACK 0x0
# define RED 0xff0000
# define GREEN 0xff00
# define YELLOW 0xffff00
# define ORANGE 0xffa500
# define BLUE 0xff
# define LIGHT_GRAY 0xd3d3d3

# define MAP_CUBE_SIZE 9
# define MAP_PLAYER_SIZE (MAP_CUBE_SIZE / 2)

#endif
