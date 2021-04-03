/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:18:48 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/03 14:21:58 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float normalizeAngle(float angle)
{
	angle = fmod(angle, TWO_PI);
	if (angle < 0)
	{
		angle += (2 * M_PI);
	}
	return (angle);
}

float	distance_between_points(float x1,float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void cast_ray(float rayAngle, int stripId)
{
	int temp = g_player.x;
	g_player.x = g_player.y;
	g_player.y = temp;
	rayAngle = normalizeAngle(rayAngle);
	g_rays.down = rayAngle > 0 && rayAngle < PI;
	g_rays.up = !g_rays.down;
	g_rays.right = rayAngle < (M_PI_2) || rayAngle > (1.5 * PI);
	g_rays.left = !g_rays.right;
	g_rays.found_HorzHit = FALSE;
	g_rays.horz_HitX = 0;
	g_rays.horz_HitY = 0;
	g_rays.horz_content = 0;
	g_rays.y_intercept = floor(g_player.y / tile_size) * tile_size;
	if (g_rays.down)
		g_rays.x_intercept += tile_size;
	//printf("%f\n",g_rays.y_intercept);
	g_rays.x_intercept = g_player.x + ((g_rays.y_intercept - g_player.y) /
															tan(rayAngle));
															//horiz
	g_rays.y_step = tile_size;
	if(g_rays.up)
		g_rays.y_step *= -1;
	g_rays.x_step = tile_size / tan(rayAngle);
	if (g_rays.left && (g_rays.x_step > 0))
		g_rays.x_step *= -1;
	if (g_rays.right && (g_rays.x_step < 0))
		g_rays.x_step *= -1;
	g_rays.NHX = g_rays.x_intercept;
	g_rays.NHY = g_rays.y_intercept;
//	printf("%f\n",g_rays.NHY);
	while (g_rays.NHX >=  0 && g_rays.NHX <= (g_map.width * tile_size) && g_rays.NHY >= 0
											&& g_rays.NHY <= (g_map.heigth * tile_size))
	{
		g_rays.x_check = g_rays.NHX;
		g_rays.y_check = g_rays.NHY + (g_rays.up ? -1 : 0);
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			//printf("%f %f \n",g_rays.x_check, g_rays.y_check);
	 		g_rays.horz_HitX = g_rays.NHX;
			g_rays.horz_HitY = g_rays.NHY;
			//int xff = floor(g_rays.x_check / tile_size);
			//int yff = floor(g_rays.y_check / tile_size);
			//char tmp = g_map.all_map[xff][yff];
			//g_rays.horz_content = (tmp == '1'|| tmp == ' '  ) ? 1 :0;
			g_rays.found_HorzHit = 1;
			break;
		}
		else
		{
			//printf("dkhlat2\n");
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
	if (g_rays.right)
		g_rays.x_intercept += tile_size;
	g_rays.y_intercept = g_player.y + ((g_rays.x_intercept - g_player.x) *
															tan(rayAngle));
															//veerti
	g_rays.x_step = tile_size;
	if(g_rays.left)
		g_rays.x_step *= -1;
	g_rays.y_step = tile_size * tan(rayAngle);
	if (g_rays.up && (g_rays.y_step > 0))
		g_rays.y_step *= -1;
	if (g_rays.down && (g_rays.y_step < 0))
		g_rays.y_step *= -1;
	g_rays.NVX = g_rays.x_intercept;
	g_rays.NVY = g_rays.y_intercept;
	while (g_rays.NVX >=  0 && g_rays.NVX <= (g_map.width * tile_size) && g_rays.NVY >= 0
											&& g_rays.NVY <= (g_map.heigth * tile_size))
	{
		g_rays.y_check = g_rays.NVY;
		g_rays.x_check = g_rays.NVX + (g_rays.left ? -1 : 0);
		if (map_has_wall(g_rays.x_check, g_rays.y_check))
		{
			g_rays.vert_HitX = g_rays.NVX;
			g_rays.vert_HitY = g_rays.NVY;
			//  int xfff = floor(g_rays.x_check / tile_size);
			//  int yfff = floor(g_rays.y_check / tile_size);
			//  char tmp = g_map.all_map[xfff][yfff];
			//  g_rays.vert_content = (tmp == '1'  || tmp == ' '  ) ? 1 :0;
			// g_rays.vert_content = g_map.all_map[(int)floor(g_rays.y_check / tile_size)][(int)floor(g_rays.x_check / tile_size)];
			g_rays.found_VertHit = 1;
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
		g_rays.horz_dist = FLT_MAX;
	if (g_rays.found_VertHit)
		g_rays.vert_dist = distance_between_points(g_player.x, g_player.y, g_rays.vert_HitX, g_rays.vert_HitY);
	else
		g_rays.vert_dist = FLT_MAX;
	if (g_rays.vert_dist < g_rays.horz_dist)
	{
		g_ray[stripId].distance = g_rays.vert_dist;
		g_ray[stripId].wallHitX = g_rays.vert_HitX;
		g_ray[stripId].wallHitY = g_rays.vert_HitY;
		//g_ray[stripId].content = g_rays.vert_content;
		g_ray[stripId].vertical = TRUE;
	}
	else
	{
	//	printf("%f\n",g_rays.horz_dist);
		g_ray[stripId].distance = g_rays.horz_dist;
		g_ray[stripId].wallHitX = g_rays.horz_HitX;
		g_ray[stripId].wallHitY = g_rays.horz_HitY;
		//g_ray[stripId].content = g_rays.horz_content;
		g_ray[stripId].vertical = FALSE;
}
	g_ray[stripId].rayAngle = rayAngle;
	g_ray[stripId].down = g_rays.down;
	g_ray[stripId].up = g_rays.up;
	g_ray[stripId].left = g_rays.left;
	g_ray[stripId].right = g_rays.right;
	//printf("x = %f , y = %f , x1 = %f , y1 = %f\n", g_player.x, g_player.y,g_ray[stripId].wallHitX, g_ray[stripId].wallHitY);

	DDA(g_player.x ,g_player.y , g_ray[stripId].wallHitX, g_ray[stripId].wallHitY, 0xDF15C0);
}

void	cast_all_rays()
{
	int stripId;
	float rayAngle;

	stripId = 0;
	rayAngle =  g_player.rotationAngle - (fov_angle / 2);
	

	while (stripId <(int)g_map.width)
	{
		//printf("->>>%d",g_param.width);
		//cast_ray(rayAngle, stripId);
		rayAngle += fov_angle / NUM_RAYS;
		//rayAngle+= g_player.fov / g_map.width;
		//DDA(g_player.y, g_player.x, g_ray[stripId].wallHitX, g_ray[stripId].wallHitY, 0xDF15C0);
		//draw_line_2(g_player.y, g_player.x, g_ray[stripId].wallHitX, g_ray[stripId].wallHitY,  rayAngle, 0xDF15C0);
		stripId++;
	}
}