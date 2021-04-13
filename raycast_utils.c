/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:48:21 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/13 14:37:34 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void DDA(int X0, int Y0, int X1, int Y1, int color)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(&img,round(X),round(Y), color);
        X += Xinc;
        Y += Yinc;
    }
}


int		map_has_wall(float x, float y)
{
	int		i;
	int		j;
	if (x < 0 || x > (g_map.heigth * tile_size) ||
		y < 0 || y > (g_map.width * tile_size))
		return (1);
	i = floor(x / tile_size);
	j = floor(y / tile_size);
	if (i < 0 || (i >= g_map.heigth)
	|| j < 0 || j >= g_map.width)
		return (1);
	if (g_map.all_map[i][j] == '1' || g_map.all_map[i][j] == ' ')
		return (1);
	return (0);
}


float normalizeAngle(float angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

float	distance_between_points(float x1,float y1, float x2, float y2)
{
	return (sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}