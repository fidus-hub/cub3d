/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:04 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:05 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_ray_init(float rayAngle)
{
	g_rays.x_step = TILE_SIZE;
	if (g_rays.left)
		g_rays.x_step *= -1;
	g_rays.y_step = TILE_SIZE * tan(rayAngle);
	if (g_rays.up && (g_rays.y_step > 0))
		g_rays.y_step *= -1;
	if (g_rays.down && (g_rays.y_step < 0))
		g_rays.y_step *= -1;
	g_rays.NVX = g_rays.x_intercept;
	g_rays.NVY = g_rays.y_intercept;
}

void	horz_ray_init(float rayAngle)
{
	g_rays.y_step = TILE_SIZE;
	if (g_rays.up)
		g_rays.y_step *= -1;
	g_rays.x_step = TILE_SIZE / tan(rayAngle);
	if (g_rays.left && (g_rays.x_step > 0))
		g_rays.x_step *= -1;
	if (g_rays.right && (g_rays.x_step < 0))
		g_rays.x_step *= -1;
	g_rays.NHX = g_rays.x_intercept;
	g_rays.NHY = g_rays.y_intercept;
}
