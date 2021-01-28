# Cubd3D

## Build the project
	- make
	- ./Cub3d maps/valid_maps/map_1920_1080.cub

## Todolist before the game can start

	- Check arg numbers return 0 or 1.
	- Check extension file return 0 or 1.
	- Check if map can be read return 0 or arr of str.
		- Read each lines of the map.
		- return each lines in arr of str.
	- Parse arr of str and return 1.
		- if any error occured during this process return 0
		- if everything is OK return t_config with all params.
	- Get the player initial position.
		- if i found multiple position or if there is no position specified return 0.
		- else return 1.
	- Check the map using flood_fill return 0 or 1.
	- free not needed variables of course.
-> GO !
