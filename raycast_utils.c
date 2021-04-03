/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:48:21 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/03 17:57:46 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void DDA(int X0, int Y0, int X1, int Y1, int color)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
		//printf("dda = x = %d , y = %d , x1 = %d , y1 = %d\n", X0, Y0 , X1,Y1);
        my_mlx_pixel_put(&img,round(X),round(Y), color);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        //delay(100);          // for visualization of line-
                             // generation step by step
    }
}

int			map_has_wall(float x, float y)
{
	int		i;
	int		j;

	i = floor(x / tile_size);
	j = floor(y / tile_size);
	if (i < 0 || (i >= g_map.width)
	|| j < 0 || j >= (g_map.heigth))
		return (0);
	if (g_map.all_map[j][i] == '1' && g_map.all_map[j][i] == ' ')
		return (1);
	return (0);
}
/*
int		map_has_wall(float x,float y)
{
	int index_x;
	int index_y;

	index_x = (int)floor(x / tile_size);
	index_y = (int)floor(y / tile_size);
	if (index_x > g_param.width || index_x < 0 || index_y < 0 || index_y > g_param.height)
		return (0);
	if (g_map.all_map[index_x][index_y] == '1' && g_map.all_map[index_x][index_y] == ' ')
		return (1);
	return (0);
}
*/