/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/12 17:06:31 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void *g_mlx;
void *g_mlx_win;

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
}               t_vars;

void draw_rec(int x ,int y)
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
			mlx_pixel_put(g_mlx, g_mlx_win, x, y, 0x1EE4ED);
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
		mlx_pixel_put(g_mlx, g_mlx_win, x + x1, y + y1, color);
		angle += 0.4;
	}
	
}

int draw_map(void)
{
	int		x;
	int		y;
	int		r;
	int		color;
	
	r = 0;
	color = 0xEB3EF3;

	g_mlx = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx, g_param.width, g_param.height, "Fidus");
	
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
			else if (g_map.all_map[x][y] == 'N')
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
	mlx_loop(g_mlx);
	return(0);
}