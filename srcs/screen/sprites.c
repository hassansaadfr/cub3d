/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:50:12 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/04 20:31:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites_list(t_vars *v)
{
	v->nb_sprites = 0;
	v->sprites_list = NULL;
	parse_map_sprites(v);
	sort_sprites(v->sprites_list, v->nb_sprites);
}

void	recalc_sprites_dist(t_vars *v)
{
	int i;
	float dist;
	t_float_pos sprites_pos;

	dist = 0;
	i = 0;
	while (i < v->nb_sprites)
	{
		sprites_pos.x = v->sprites_list[i]->x;
		sprites_pos.y = v->sprites_list[i]->y;
		dist = ray_dist(&v->player.p_pos, sprites_pos.x, sprites_pos.y);
		// dist *= dist;
		v->sprites_list[i]->dist = dist;
		i++;
	}
	sort_sprites(v->sprites_list, v->nb_sprites);
}

void	draw(t_vars *v)
{
	for (int i = 0; i < v->nb_sprites; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = v->sprites_list[0]->x - v->player.p_pos.x;
		double spriteY = v->sprites_list[0]->y - v->player.p_pos.y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (v->player.plane_x * v->player.pdy - v->player.pdx * v->player.plane_y); //required for correct matrix multiplication

		double transformX = invDet * (v->player.pdy * spriteX - v->player.pdx * spriteY);
		double transformY = invDet * (-v->player.plane_y * spriteX + v->player.plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int)((v->c->resolution->x / 2) * (1 + transformX / transformY));

		//calculate height of the sprite on screen
		int spriteHeight = abs((int)(v->c->resolution->y / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + v->c->resolution->y / 2;
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + v->c->resolution->y / 2;
		if (drawEndY >= v->c->resolution->y)
			drawEndY = v->c->resolution->y - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int)(v->c->resolution->y / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= v->c->resolution->x)
			drawEndX = v->c->resolution->x - 1;

		//loop through every vertical stripe of the sprite on screen
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * v->sprite_tex.width / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (transformY > 0 && stripe > 0 && stripe < v->c->resolution->x && transformY < v->z_buffer[stripe])
				for (int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y)*256 - v->c->resolution->y * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * v->sprite_tex.height) / spriteHeight) / 256;
					(void)texX;
					(void)texY;
					// int color = my_mlx_pixel_get(v->sprite_tex, texX, texY); // Sort de l'image wtf
					int color = RED;
					mlx_pixel_put(v->mlx, v->win, stripe, y, color);
					//   Uint32 color = texture[sprite[spriteOrder[i]].texture][v->sprite_tex.width * texY + texX]; //get current color from the texture
					//   if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
				}
		}
	}
}
