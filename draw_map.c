/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/28 14:45:59 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This is the function where you'll be incrementing or decrementing your player position (x, y) depending on the key
void	update(void)
{
	float x;
	float y;
	float moveStep;
	
	g_player.rotationAngle += g_player.turnDirection * g_player.turnSpeed;
	
	moveStep = g_player.walkDirection * g_player.walkSpeed;
	
	x = g_player.x + cos(g_player.rotationAngle) * moveStep;
	y = g_player.y + sin(g_player.rotationAngle) * moveStep;
	if (!is_wall(x, y))
	{
		g_player.x = x;
		g_player.y = y;
	}

	printf("|%f| |%f|\n",g_player.x,g_player.y);
}


int		key_hook(void)
{
	//w :13 a: 0 s : 1 d : 2 left : 123 right : 124 up : 126 down :125
	//mlx_hook(g_vars.win, 2, 0, key_pressed, 0);
//	mlx_hook(g_vars.win, 3, 0, key_released, 0);

	/*
	** TO-DO:
	** 1 - start using images instead of pixels
	** 2 - destroy the image using mlx_destroy_image
	** 3 - clear the window using mlx_clear_window
	** 4 - create a new image and fill your data.
	** 5 - draw the player and map again (done)
	** 6 - Then call the update function at last (done)
	**/

	// The piece of code you need will need to be written here from now, wether for drawing rays or sprites...
	// Any function that draw something will be here since, this is inside a loop as I specified on get_parameters.c


	
	// Don't touch below
	
	update();
	draw_map();
	int r = 0;
	while (r < 10)
	{
		draw_circle(g_player.y, g_player.x, r, 0xEB3EF3);
			r++;
	}
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, img.img, 0, 0);
	//mlx_destroy_image(g_vars.mlx, img.img);
	//mlx_clear_window(g_vars.mlx, g_vars.win);
	//draw_map();
	// Raycasting();
	// Sprites();
	
	
	return (0);
}


 int draw_player(void)
{
	{
	int		x;
	int		y;
	
	x = 0;
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == 'N')
			{
				g_player.x = x * tile_size;
				g_player.y = y * tile_size;
				g_player.rotationAngle = M_PI / 2;
				g_player.walkSpeed = 3;
				g_player.turnDirection = 0;
				g_player.turnSpeed = 2 * (M_PI / 180);
				g_player.walkDirection = 0;
				//g_player.fov;
				
			}
			y++;
		}
		x++;
	}
	return(0);
}
	return (0);
}

int		draw_map(void)
{
	img.img = mlx_new_image(g_vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln,
                                 &img.endian);
	int		x;
	int		y;
	int		r;
	
	r = 0;
	x = 0;
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == '1' || g_map.all_map[x][y] == ' ')
				draw_rec(y * tile_size, x * tile_size);
			y++;
		}
		x++;
	}
	return (0);
}
int play()
{
	mlx_hook(g_vars.win, 2, 0, key_pressed, 0);
	key_hook();
	mlx_hook(g_vars.win, 3, 0, key_released, 0);
	return(0);
}