/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:18:48 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/13 16:53:22 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	vert_ray(float rayAngle)
{
	g_rays.x_step = tile_size;
	if (g_rays.left)
		g_rays.x_step *= -1;
	g_rays.y_step = tile_size * tan(rayAngle);
	if (g_rays.up && (g_rays.y_step > 0))
		g_rays.y_step *= -1;
	if (g_rays.down && (g_rays.y_step < 0))
		g_rays.y_step *= -1;
	g_rays.NVX = g_rays.x_intercept;
	g_rays.NVY = g_rays.y_intercept;
	while (g_rays.NVX >=  0 && g_rays.NVX <= (g_map.heigth * tile_size)
		&& g_rays.NVY >= 0 && g_rays.NVY <= (g_map.width * tile_size))
	{
		g_rays.y_check = g_rays.NVY;
		g_rays.x_check = g_rays.NVX + (g_rays.left ? -1 : 0);
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.vert_HitX = g_rays.NVX;
			g_rays.vert_HitY = g_rays.NVY;
			g_rays.found_VertHit = 1;
			break;
		}
		else
		{
			g_rays.NVX += g_rays.x_step;
			g_rays.NVY += g_rays.y_step;
		}
	}
}

void	horz_ray(float rayAngle)
{
	g_rays.y_step = tile_size;
	if (g_rays.up)
		g_rays.y_step *= -1;
	g_rays.x_step = tile_size / tan(rayAngle);
	if (g_rays.left && (g_rays.x_step > 0))
		g_rays.x_step *= -1;
	if (g_rays.right && (g_rays.x_step < 0))
		g_rays.x_step *= -1;
	g_rays.NHX = g_rays.x_intercept;
	g_rays.NHY = g_rays.y_intercept;
	while (g_rays.NHX >= 0 && g_rays.NHX <= (g_map.heigth * tile_size)
		&& g_rays.NHY >= 0 && g_rays.NHY <= (g_map.width * tile_size))
	{
		g_rays.x_check = g_rays.NHX;
		g_rays.y_check = g_rays.NHY + (g_rays.up ? -1 : 0);
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
	 		g_rays.horz_HitX = g_rays.NHX;
			g_rays.horz_HitY = g_rays.NHY;
			g_rays.found_HorzHit = 1;
			break;
		}
		else
		{
			g_rays.NHX += g_rays.x_step;
			g_rays.NHY += g_rays.y_step;
		}
	}
}

void	push_ray(int stripId)
{
	if (g_rays.found_HorzHit)
		g_rays.horz_dist = distance_between_points(g_player.x,
				g_player.y, g_rays.horz_HitX, g_rays.horz_HitY);
	else
		g_rays.horz_dist = (float)INT32_MAX;
	if (g_rays.found_VertHit)
		g_rays.vert_dist = distance_between_points(g_player.x,
				g_player.y, g_rays.vert_HitX, g_rays.vert_HitY);
	else
		g_rays.vert_dist = (float)INT32_MAX;
	if (g_rays.vert_dist < g_rays.horz_dist)
	{
		g_ray[stripId].distance = g_rays.vert_dist;
		g_ray[stripId].wallHitX = g_rays.vert_HitX;
		g_ray[stripId].wallHitY = g_rays.vert_HitY;
		g_ray[stripId].vertical = TRUE;
	}
	else
	{
		g_ray[stripId].distance = g_rays.horz_dist;
		g_ray[stripId].wallHitX = g_rays.horz_HitX;
		g_ray[stripId].wallHitY = g_rays.horz_HitY;
		g_ray[stripId].vertical = FALSE;
	}
}

void cast_ray(float rayAngle, int stripId)
{
	g_rays.found_HorzHit = FALSE;
	g_rays.horz_HitX = 0;
	g_rays.horz_HitY = 0;
	g_rays.y_intercept = floor(g_player.y / tile_size) * tile_size;
	if (g_rays.down)
		g_rays.y_intercept += tile_size;
	g_rays.x_intercept = g_player.x +
	((g_rays.y_intercept - g_player.y) / tan(rayAngle));
	horz_ray(rayAngle);
	g_rays.found_VertHit = FALSE;
	g_rays.vert_HitX = 0;
	g_rays.vert_HitY = 0;
	g_rays.x_intercept = floor(g_player.x / tile_size) * tile_size;
	if (g_rays.right)
		g_rays.x_intercept += tile_size;
	g_rays.y_intercept = g_player.y +
	((g_rays.x_intercept - g_player.x) * tan(rayAngle));
	vert_ray(rayAngle);
	push_ray(stripId),
	g_ray[stripId].rayAngle = rayAngle;
	g_ray[stripId].down = g_rays.down;
	g_ray[stripId].up = g_rays.up;
	g_ray[stripId].left = g_rays.left;
	g_ray[stripId].right = g_rays.right;

//	DDA(g_player.y, g_player.x, g_ray[stripId].wallHitY, g_ray[stripId].wallHitX, 0xffffff);

        float perpDistance = g_ray[stripId].distance * cos(g_ray[stripId].rayAngle - g_player.rotationAngle);
        float distanceProjPlane = (g_param.width / 2) / tan(fov_angle / 2);
        float projectedWallHeight = (tile_size / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (g_param.height / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        int wallBottomPixel = (g_param.height / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > g_param.height ? g_param.height : wallBottomPixel;

        // render the wall from wallTopPixel to wallBottomPixel
        for (int y = wallTopPixel; y < wallBottomPixel; y++) {
			my_mlx_pixel_put(&img, stripId, y, 0xFF0000);
            //colorBuffer[(g_param.width * y) + stripId] = g_ray[stripId].vertical ? 0xFFFFFFFF : 0xFFCCCCCC;
        }

}

void	cast_all_rays()
{
	int		stripId;
	float	rayAngle;

	stripId = 0;
	rayAngle = g_player.rotationAngle - (fov_angle / 2);
	rayAngle = normalizeAngle(rayAngle);

	while (stripId < g_param.width)
	{
		g_rays.down = rayAngle > 0 && rayAngle < PI;
		g_rays.up = !g_rays.down;
		g_rays.right = rayAngle < (M_PI_2) || rayAngle > (1.5 * PI);
		g_rays.left = !g_rays.right;
		
		cast_ray(rayAngle, stripId);
		rayAngle = normalizeAngle(rayAngle);
		rayAngle += (fov_angle / NUM_RAYS);
		stripId++;
	}
}
