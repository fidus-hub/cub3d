/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:10:06 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/01 17:49:34 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->ln + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

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
			my_mlx_pixel_put(&img,x, y, 0x1EE4ED);
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
		my_mlx_pixel_put(&img ,x + x1,y + y1, color);
		//printf("----*-->%d\n",x);
		angle += 0.1;
	}
}

int			is_wall(float x, float y)
{
	int		i;
	int		j;

	i = floor(x / tile_size);
	j = floor(y / tile_size);
	
	
	if (x < 0 || (x > g_param.width * tile_size )
	|| y < 0 || y > (g_param.height * tile_size))
		return (1);
	if (g_map.all_map[i][j] == '1')
		return (1);
	else
		return (0);
}