/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:30:01 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/17 17:40:47 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This is the function where you'll be incrementing or decrementing your player position (x, y) depending on the key
void	update(void)
{
	float x;
	float y;
	float moveStep;
	
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

void	render_sprite(void)
{
	// DO WHATEVER WE GONNA DO
}

int		key_hook(void)
{
	update();
	draw_map();
	cast_all_rays();
	// To-do:
	// render_sprite();
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, img.img, 0, 0);
	mlx_destroy_image(g_vars.mlx, img.img);
	//mlx_clear_window(g_vars.mlx, g_vars.win);
	
	
	return (0);
}


 int draw_player(void)
{
	{
	int		x;
	int		y;
	
	x = 0;
	while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == 'N')
			{
				g_player.x = x * tile_size + 32;
				g_player.y = y * tile_size + 32;
				g_player.rotationAngle = RADIAN(360);
				g_player.walkSpeed = 3;
				g_player.turnDirection = 0;
				g_player.turnSpeed = 2 * (M_PI / 180);
				g_player.walkDirection = 0;
			}
			y++;
		}
		x++;
	}
	return(0);
}
	return (0);
}

int		draw_map(void)
{
	img.img = mlx_new_image(g_vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln,
                                 &img.endian);
	int		x;
	int		y;
	int		r;
	
	r = 0;
	x = 0;
	/*while (x < g_map.heigth)
	{
		y = 0;
		while (y < g_map.width)
		{
			if (g_map.all_map[x][y] == '1' || g_map.all_map[x][y] == ' ')
				draw_rec(y * tile_size, x * tile_size);
			y++;
		}
		x++;
	}*/
	return (0);
}
int play()
{
	mlx_hook(g_vars.win, 2, 0, key_pressed, 0);
	key_hook();
	mlx_hook(g_vars.win, 3, 0, key_released, 0);
	return(0);
}