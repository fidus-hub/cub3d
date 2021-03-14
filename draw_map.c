/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/14 17:34:49 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	draw_rec(int x ,int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	while (x < x1 + 64)
	{
		y = y1;
		while (y < y1 + 64)
		{
			mlx_pixel_put(g_vars.mlx, g_vars.win, x, y, 0x1EE4ED);
			y++;
		}
		x++;
	}
}


void	draw_circle(int x, int y, int r, int color)
{
	float angle = 0.0;
	int x1;
	int y1;

	while (angle < 360.0)
	{
		x1 = cos(angle * rad) * r;
		y1 = sin(angle * rad) * r;
		mlx_pixel_put(g_vars.mlx, g_vars.win, x + x1, y + y1, color);
		angle += 0.1;
	}
	
}

 int draw_player(void)
{
	{
	int		x;
	int		y;
	int		r;
	int		color;
	
	r = 0;
	x = 0;
	color = 0xEB3EF3;
	
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == 'N')
			{	
				g_player.x = x * tile_size;
				g_player.y = y * tile_size;
			}
			y++;
		}
		x++;
	}
	while (r < 10)
	{
		draw_circle(g_player.y, g_player.x , r, color);
			r++;
	}
	
	return(0);
}
	 

	return (0);
}

// If we press a key, we enter this function
int		key_pressed(int keycode)
{
	printf("%d\n", keycode);
	if (keycode == 13)
		g_move.up = 1;
	return (0);
}

// When we release a key, we enter this function
int		key_released(int keycode)
{
	if (keycode == 13)
		g_move.up = 0;
	return (0);
}

// This is the function where you'll be incrementing or decrementing your player position (x, y) depending on the key
void	update(void)
{
	if (g_move.up == 1)
	{
		g_player.y += 20;
		g_player.x += 20;
	}
}


int		key_hook(void)
{
	//w :13 a: 0 s : 1 d : 2 left : 123 right : 124 up : 126 down :125
	mlx_hook(g_vars.win, 2, 0, key_pressed, 0);
	mlx_hook(g_vars.win, 3, 0, key_released, 0);

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
	mlx_clear_window(g_vars.mlx, g_vars.win);
	g_vars.win = mlx_new_window(g_vars.mlx, g_param.width, g_param.height,
				 "Fidus world");

	
	// Don't touch below
	draw_map();
	draw_player();

	update();
	return (0);
}


int		draw_map(void)
{
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