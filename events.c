/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:33:24 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:33:28 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keycode)
{
	if (keycode == 13)
		g_player.walkDirection = 1;
	if (keycode == 1)
		g_player.walkDirection = -1;
	if (keycode == 2)
		g_player.turnDirection = 1;
	if (keycode == 0)
		g_player.turnDirection = -1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	key_released(int keycode)
{
	if (keycode == 13)
		g_player.walkDirection = 0;
	if (keycode == 1)
		g_player.walkDirection = 0;
	if (keycode == 2)
		g_player.turnDirection = 0;
	if (keycode == 0)
		g_player.turnDirection = 0;
	return (0);
}

void	update(void)
{
	float	x;
	float	y;
	float	moveStep;

	g_player.rotationAngle += g_player.turnDirection * g_player.turnSpeed;
	moveStep = g_player.walkDirection * g_player.walkSpeed;
	x = g_player.x + cos(g_player.rotationAngle) * moveStep;
	y = g_player.y + sin(g_player.rotationAngle) * moveStep;
	if (!is_wall(y, x))
	{
		g_player.x = x;
		g_player.y = y;
	}
}

int	key_hook(void)
{
	update();
	g_img.img = mlx_new_image(g_vars.mlx, g_param.width, g_param.height);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.ln,
			&g_img.endian);
	cast_all_rays();
	ft_sprite();
	if (g_vars.save == 1)
	{
		bmp_save();
		mlx_destroy_image(g_vars.mlx, g_img.img);
		exit(0);
	}
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img.img, 0, 0);
	mlx_destroy_image(g_vars.mlx, g_img.img);
	return (0);
}

int	play(void)
{
	mlx_hook(g_vars.win, 2, 0, key_pressed, 0);
	key_hook();
	mlx_hook(g_vars.win, 3, 0, key_released, 0);
	mlx_hook(g_vars.win, 17, 0L, ft_quit, 0);
	return (0);
}
