/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/14 16:22:24 by mgrissen         ###   ########.fr       */
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
				while (r < 10)
				{
					draw_circle(y * tile_size, x * tile_size, r, color);
						r++;
				}
			}
			y++;
		}
		x++;
	}
	return(0);
}
	 

	return (0);
}

int		key_hook(int keycode)
{
	//w :13 a: 0 s : 1 d : 2 left : 123 right : 124 up : 126 down :125
	printf("key typed is: %d\n", keycode);

	return(0);
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
			{
				draw_rec(y * tile_size, x * tile_size);
			}
			y++;
		}
		x++;
	}
	return(0);
}