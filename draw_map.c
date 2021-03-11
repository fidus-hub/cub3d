/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/11 17:34:51 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void *g_mlx;
void *g_mlx_win;

void draw_rec(int x ,int y, void *mlx, void *mlx_win)
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
			mlx_pixel_put(mlx, mlx_win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

void draw_void_rec(t_rec rec_coord, void *mlx, void *mlx_win)
{
	while (rec_coord.i <= rec_coord.r)
	{
		rec_coord.j = 0;
		while (rec_coord.j <= rec_coord.c)
		{
			if (rec_coord.i == tile_size|| rec_coord.i == rec_coord.r ||
				rec_coord.j == tile_size || rec_coord.j == rec_coord.c)
				mlx_pixel_put(mlx, mlx_win, rec_coord.i, rec_coord.j, 0xFF0000);
			rec_coord.j++;
		}
		rec_coord.i++;
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
		mlx_pixel_put(g_mlx, g_mlx_win, x + x1, y + y1, color);
		angle += 0.4;
	}
	
}

int draw_map(void)
{
	t_rec rec_coord;
	int		r;
	int		color;
	// int i;
	// int j;
	// int tilex;
	// int tiley;
	

	rec_coord.i = 0;
	rec_coord.j = 0;
	rec_coord.c = 0;
	rec_coord.r = 0;
	r = 0;
	color = 0xFF0000;
	int 		x;
	int			y;

	
	y = 0;

	g_mlx = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx, g_param.width, g_param.height, "Fidus world!");
	x = 0;
	
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == '1' /*|| g_map.all_map[x][y] == ' '*/)
			{
				draw_rec(y * tile_size, x * tile_size, g_mlx, g_mlx_win);
			}
			// else
			// {
			// 	draw_void_rec(rec_coord, g_mlx, g_mlx_win);
			// }
			y++;
		}
		x++;
	}
	mlx_loop(g_mlx);
	return(0);
}