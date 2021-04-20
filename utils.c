/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:39 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:40 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < g_param.width && y >= 0 && y < g_param.height)
	{
		dst = data->addr + (y * data->ln + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	is_wall(float x, float y)
{
	int		i;
	int		j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x < 0 || (x > g_param.width * TILE_SIZE)
		|| y < 0 || y > (g_param.height * TILE_SIZE))
		return (1);
	if (g_map.all_map[j][i] == '1' || g_map.all_map[j][i] == '2')
		return (1);
	else
		return (0);
}

int	map_has_wall(float x, float y)
{
	int		i;
	int		j;

	if (x < 0 || x > (g_map.heigth * TILE_SIZE)
		|| y < 0 || y > (g_map.width * TILE_SIZE))
		return (1);
	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (i < 0 || (i >= g_map.heigth)
		|| j < 0 || j >= g_map.width)
		return (1);
	if (g_map.all_map[i][j] == '1' || g_map.all_map[i][j] == ' ')
		return (1);
	return (0);
}

float	normalizeAngle(float angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
