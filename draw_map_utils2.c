/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:44:46 by mgrissen          #+#    #+#             */
/*   Updated: 2021/03/28 14:52:50 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cub3d_init()
{
	 

    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
}

int		key_pressed(int keycode)
{
	if (keycode == 13)
		g_player.walkDirection = 1;
	if (keycode == 1)
		g_player.walkDirection = -1;
	if (keycode == 0)
		g_player.turnDirection = 1;
	if (keycode == 2)
		g_player.turnDirection = -1;
	if (keycode == 53)
		exit(0);
		
	return (0);
}

int		key_released(int keycode)
{
		if (keycode == 13)
		g_player.walkDirection = 0;
	if (keycode == 1)
		g_player.walkDirection = 0;
	if (keycode == 0)
		g_player.turnDirection = 0;
	if (keycode == 2)
		g_player.turnDirection = 0;
		
	return (0);
}