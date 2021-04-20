/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:33:34 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:33:36 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_player(void)
{
	int		x;
	int		y;

	x = 0;
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == 'N' || g_map.all_map[x][y] == 'S'
			|| g_map.all_map[x][y] == 'W' || g_map.all_map[x][y] == 'E')
			{
				g_player.x = x * TILE_SIZE + 32;
				g_player.y = y * TILE_SIZE + 32;
				g_player.walkSpeed = 3;
				g_player.turnDirection = 0;
				g_player.turnSpeed = 2 * (M_PI / 180);
				g_player.walkDirection = 0;
			}
			y++;
		}
		x++;
	}
	return (0);
}
