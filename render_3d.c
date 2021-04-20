/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:30 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:31 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ceiling(int stripId)
{
	int	y;

	y = 0;
	while (y < g_3d.wallTopPixel)
	{
		my_mlx_pixel_put(&g_img, stripId, y,
			rgb_to_int(g_param.c_r, g_param.c_g, g_param.c_b));
		y++;
	}
}

void	render_floor(int stripId)
{
	int	y;

	y = g_3d.wallBottomPixel;
	while (y < g_param.height)
	{
		my_mlx_pixel_put(&g_img, stripId, y,
			rgb_to_int(g_param.f_r, g_param.f_g, g_param.f_b));
		y++;
	}
}

void	render_walls(int stripId)
{
	int	y;

	y = g_3d.wallTopPixel;
	if (g_ray[stripId].vertical)
		g_tex.offset_x = (int)g_ray[stripId].wallHitY % 64;
	else
		g_tex.offset_x = (int)g_ray[stripId].wallHitX % 64;
	while (y < g_3d.wallBottomPixel)
	{
		g_tex.dist_ftop = y + (g_3d.wallStripHeight / 2) - (g_param.height / 2);
		g_tex.offset_y = g_tex.dist_ftop * ((float)64 / g_3d.wallStripHeight);
		if ((64 * g_tex.offset_y + g_tex.offset_x) > 0)
		{
			if (g_ray[stripId].up && !g_ray[stripId].vertical)
				g_tex.color = g_tex.north[64 * g_tex.offset_y + g_tex.offset_x];
			else if (g_ray[stripId].down && !g_ray[stripId].vertical)
				g_tex.color = g_tex.south[64 * g_tex.offset_y + g_tex.offset_x];
			else if (g_ray[stripId].right && g_ray[stripId].vertical)
				g_tex.color = g_tex.east[64 * g_tex.offset_y + g_tex.offset_x];
			else if (g_ray[stripId].left && g_ray[stripId].vertical)
				g_tex.color = g_tex.west[64 * g_tex.offset_y + g_tex.offset_x];
		}
		my_mlx_pixel_put(&g_img, stripId, y, g_tex.color);
		y++;
	}
}

void	render_3d(int stripId)
{
	g_3d.perpDistance = g_ray[stripId].distance
		* cos(g_ray[stripId].rayAngle - g_player.rotationAngle);
	g_3d.distanceProjPlane = (g_param.width / 2) / tan(FOV_ANGLE / 2);
	g_3d.projectedWallHeight = (TILE_SIZE / g_3d.perpDistance)
		* g_3d.distanceProjPlane;
	g_3d.wallStripHeight = (int)g_3d.projectedWallHeight;
	g_3d.wallTopPixel = (g_param.height / 2) - (g_3d.wallStripHeight / 2);
	if (g_3d.wallTopPixel < 0)
		g_3d.wallTopPixel = 0;
	g_3d.wallBottomPixel = (g_param.height / 2) + (g_3d.wallStripHeight / 2);
	if (g_3d.wallBottomPixel > g_param.height)
		g_3d.wallBottomPixel = g_param.height;
	render_ceiling(stripId);
	render_walls(stripId);
	render_floor(stripId);
}
