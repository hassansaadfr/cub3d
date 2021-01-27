/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:12:58 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/27 18:44:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H

# define CONSTANTS_H

# define INVALID_ARGS "Usage : ./Cub3d [--save] <map.cub>"
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

#endif
