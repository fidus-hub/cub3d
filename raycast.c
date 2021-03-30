/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:18:48 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/30 14:57:46 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return angle;
}

float	distance_between_points(x1, y1, x2, y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void cast_ray(float rayAngle, int stripId)
{
	rayAngle = normalizeAngle(rayAngle);
	g_ray.down = rayAngle > 0 && rayAngle < PI;
	g_ray.up = !g_ray.down;
	g_ray.right = rayAngle < 0.5 * PI && rayAngle > 1.5 * PI;
	g_ray.left = !g_ray.right;
	g_rays.found_HorzHit = FALSE;
	g_rays.horz_HitX = 0;
	g_rays.horz_HitY = 0;
	g_rays.horz_content = 0;
	g_rays.y_intercept = floor(g_player.y / tile_size) * tile_size;
	if (g_ray.down)
		g_rays.y_intercept += tile_size;
	else 
		g_rays.y_intercept += 0;
	g_rays.x_intercept = g_player.x + (g_rays.y_intercept - g_player.y) /
															tan(rayAngle);
															//horiz
	g_rays.y_step = tile_size;
	if(g_ray.up)
		g_rays.y_step *= -1;
	else
		g_rays.y_step *= 1;
	g_rays.x_step = tile_size / tan(rayAngle);
	if (g_ray.left && (g_rays.x_step > 0))
		g_rays.x_step *= -1;
	else
		g_rays.x_step *= 1;
	if (g_ray.right && (g_rays.x_step < 0))
		g_rays.x_step *= -1;
	else
		g_rays.x_step *= 1;
	g_rays.NHX = g_rays.x_intercept;
	g_rays.NHY = g_rays.y_intercept;
	while (g_rays.NHX >=  0 && g_rays.NHX <= g_map.width && g_rays.NHY >= 0
											&& g_rays.NHY <- g_map.heigth)
	{
		g_rays.x_check = g_rays.NHX;
		if(g_ray.up)
			g_rays.y_check = g_rays.NHY + -1;
		else
			g_rays.y_check = g_rays.NHY + 0;
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.horz_HitX = g_rays.NHX;
			g_rays.horz_HitY = g_rays.NHY;
			g_rays.horz_content = g_map.all_map[(int)floor(g_rays.y_check / tile_size)][(int)floor(g_rays.x_check / tile_size)];
			g_rays.found_HorzHit = TRUE;
			break;
		}
		else
		{
			g_rays.NHX += g_rays.x_step;
			g_rays.NHX += g_rays.y_step;
		}
	}
	//vert

	g_rays.found_VertHit = FALSE;
	g_rays.vert_HitX = 0;
	g_rays.vert_HitY = 0;
	g_rays.vert_content = 0;
	g_rays.x_intercept = floor(g_player.x / tile_size) * tile_size;
	if (g_ray.down)
		g_rays.x_intercept += tile_size;
	else 
		g_rays.x_intercept += 0;
	g_rays.y_intercept = g_player.y + (g_rays.x_intercept - g_player.x) /
															tan(rayAngle);
															//horiz
	g_rays.x_step = tile_size;
	if(g_ray.left)
		g_rays.x_step *= -1;
	else
		g_rays.x_step *= 1;
	g_rays.y_step = tile_size / tan(rayAngle);
	if (g_ray.up && (g_rays.x_step > 0))
		g_rays.y_step *= -1;
	else
		g_rays.y_step *= 1;
	if (g_ray.down && (g_rays.x_step < 0))
		g_rays.y_step *= -1;
	else
		g_rays.y_step *= 1;
	g_rays.NVX = g_rays.x_intercept;
	g_rays.NVY = g_rays.y_intercept;
	while (g_rays.NVX >=  0 && g_rays.NVX <= g_map.width && g_rays.NVY >= 0
											&& g_rays.NVY <- g_map.heigth)
	{
		g_rays.y_check = g_rays.NVY;
		if(g_ray.left)
			g_rays.x_check = g_rays.NVX + -1;
		else
			g_rays.x_check = g_rays.NVX + 0;
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.vert_HitX = g_rays.NVX;
			g_rays.vert_HitY = g_rays.NVY;
			g_rays.vert_content = g_map.all_map[(int)floor(g_rays.y_check / tile_size)][(int)floor(g_rays.x_check / tile_size)];
			g_rays.found_VertHit = TRUE;
			break;
		}
		else
		{
			g_rays.NVX += g_rays.x_step;
			g_rays.NVY += g_rays.y_step;
		}
	}
	// calcul hotz and vert
	if (g_rays.found_HorzHit)
		g_rays.horz_dist = distance_between_points(g_player.x, g_player.y, g_rays.horz_HitX, g_rays.horz_HitY);
	else
		g_rays.horz_dist = INT_MAX;
	if (g_rays.found_VertHit)
		g_rays.vert_dist = distance_between_points(g_player.x, g_player.y, g_rays.vert_HitX, g_rays.vert_HitY);
	else
		g_rays.vert_dist = INT_MAX;
	if (g_rays.vert_dist < g_rays.horz_dist)
	{
		g_ray[stripId].distance = g_rays.vert_dist;
		g_ray[stripId].wallHitX = g_rays.vert_HitX;
		g_ray[stripId].wallHitY = g_rays.vert_HitY;
		g_ray[stripId].content = g_rays.vert_content;
		g_ray[stripId].vertical = TRUE;
	}
	else
	{
		g_ray[stripId].distance = g_rays.horz_dist;
		g_ray[stripId].wallHitX = g_rays.horz_HitX;
		g_ray[stripId].wallHitY = g_rays.horz_HitY;
		g_ray[stripId].content = g_rays.horz_content;
		g_ray[stripId].vertical = FALSE;
	}
	g_ray[stripId].rayAngle = rayAngle;
	g_ray[stripId].down = g_ray.down;
	g_ray[stripId].up = g_ray.up;
	g_ray[stripId].left = g_ray.left;
	g_ray[stripId].right = g_ray.right;
}

void	cast_all_rays()
{
	int stripId;
	float rayAngle;

	stripId = 0;
	rayAngle =  g_player.rotationAngle - (fov_angle / 2);
	

	while (stripId < NUM_RAYS)
	{
		cast_ray(rayAngle, stripId);
		rayAngle += fov_angle / NUM_RAYS;
		stripId++;
	}
}