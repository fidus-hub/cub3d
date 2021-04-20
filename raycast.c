/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidus <fidus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:18:48 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/19 15:54:57 by fidus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_ray(float rayAngle)
{
	vert_ray_init(rayAngle);
	while (g_rays.NVX >= 0 && g_rays.NVX <= (g_map.heigth * TILE_SIZE)
		&& g_rays.NVY >= 0 && g_rays.NVY <= (g_map.width * TILE_SIZE))
	{
		g_rays.y_check = g_rays.NVY;
		g_rays.x_check = g_rays.NVX;
		if (g_rays.left)
			g_rays.x_check += -1;
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.vert_HitX = g_rays.NVX;
			g_rays.vert_HitY = g_rays.NVY;
			g_rays.found_VertHit = 1;
			break ;
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
	horz_ray_init(rayAngle);
	while (g_rays.NHX >= 0 && g_rays.NHX <= (g_map.heigth * TILE_SIZE)
		&& g_rays.NHY >= 0 && g_rays.NHY <= (g_map.width * TILE_SIZE))
	{
		g_rays.x_check = g_rays.NHX;
		g_rays.y_check = g_rays.NHY;
		if (g_rays.up)
			g_rays.y_check += -1;
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.horz_HitX = g_rays.NHX;
			g_rays.horz_HitY = g_rays.NHY;
			g_rays.found_HorzHit = 1;
			break ;
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

void	cast_ray(float rayAngle, int stripId)
{
	g_rays.found_HorzHit = FALSE;
	g_rays.horz_HitX = 0;
	g_rays.horz_HitY = 0;
	g_rays.y_intercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_rays.down)
		g_rays.y_intercept += TILE_SIZE;
	g_rays.x_intercept = g_player.x
		+ ((g_rays.y_intercept - g_player.y) / tan(rayAngle));
	horz_ray(rayAngle);
	g_rays.found_VertHit = FALSE;
	g_rays.vert_HitX = 0;
	g_rays.vert_HitY = 0;
	g_rays.x_intercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (g_rays.right)
		g_rays.x_intercept += TILE_SIZE;
	g_rays.y_intercept = g_player.y
		+ ((g_rays.x_intercept - g_player.x) * tan(rayAngle));
	vert_ray(rayAngle);
	push_ray(stripId),
	g_ray[stripId].rayAngle = rayAngle;
	g_ray[stripId].down = g_rays.down;
	g_ray[stripId].up = g_rays.up;
	g_ray[stripId].left = g_rays.left;
	g_ray[stripId].right = g_rays.right;
}

void	cast_all_rays(void)
{
	int		stripId;
	float	rayAngle;

	stripId = 0;
	rayAngle = g_player.rotationAngle - (FOV_ANGLE / 2);
	rayAngle = normalizeAngle(rayAngle);
	while (stripId < g_param.width)
	{
		g_rays.down = rayAngle > 0 && rayAngle < PI;
		g_rays.up = !g_rays.down;
		g_rays.right = rayAngle < (M_PI_2) || rayAngle > (1.5 * PI);
		g_rays.left = !g_rays.right;
		cast_ray(rayAngle, stripId);
		render_3d(stripId);
		rayAngle = normalizeAngle(rayAngle);
		rayAngle += (FOV_ANGLE / g_param.width);
		stripId++;
	}
}
