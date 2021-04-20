/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:33:44 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:33:46 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bubble_sort(void)
{
	int			i;
	int			j;
	t_sprite	*tmp;

	i = 0;
	while (i < g_param.sprite_count)
	{
		j = 0;
		while (j < g_param.sprite_count - i - 1)
		{
			if (g_sprite[j]->distance <= g_sprite[j + 1]->distance)
			{
				tmp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	update_sprite(void)
{
	int		i;
	int		j;
	int		sprite_id;

	i = 0;
	sprite_id = 0;
	while (i < g_map.heigth)
	{
		j = 0;
		while (j < g_map.width)
		{
			if (g_map.all_map[i][j] == '2')
			{
				g_sprite[sprite_id]->y = (j * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[sprite_id]->x = (i * TILE_SIZE) + TILE_SIZE / 2;
				g_sprite[sprite_id]->distance = distance_between_points(
						g_sprite[sprite_id]->y, g_sprite[sprite_id]->x,
						g_player.y, g_player.x);
				sprite_id++;
			}
			j++;
		}
		i++;
	}
	bubble_sort();
}

void	render_sprite(int sprite_id, int x_offset, int y_offset, int sp_size)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < sp_size)
	{
		if (x_offset + i < 0 || x_offset + i > g_param.width)
			continue ;
		if (g_ray[x_offset + i - 2].distance < g_sprite[sprite_id]->distance)
			continue ;
		j = -1;
		while (++j < sp_size)
		{
			if (y_offset + j < 0 || y_offset + j > g_param.height)
				continue ;
			color = g_sprite[sprite_id]->data
			[g_sprite[sprite_id]->width * (
					j * g_sprite[sprite_id]->height / sp_size)
				+ (i * g_sprite[sprite_id]->width / sp_size)];
			if (color)
				my_mlx_pixel_put(&g_img, x_offset + i, y_offset + j, color);
		}
	}
}

void	ft_sprite_informations(int sprite_id)
{
	float	x_offset;
	float	y_offset;
	float	sp_angle;
	float	sp_size;

	sp_angle = atan2(-g_player.y + (g_sprite[sprite_id]->y),
			-g_player.x + (g_sprite[sprite_id]->x));
	while (sp_angle - g_player.rotationAngle > M_PI)
		sp_angle -= TWO_PI;
	while (sp_angle - g_player.rotationAngle < -M_PI)
		sp_angle += TWO_PI;
	sp_size = (g_param.width / g_sprite[sprite_id]->distance * TILE_SIZE);
	x_offset = (sp_angle - g_player.rotationAngle)
		/ FOV_ANGLE * g_param.width + (g_param.width / 2 - sp_size / 2);
	y_offset = (g_param.height / 2 - sp_size / 2);
	render_sprite(sprite_id, x_offset, y_offset, sp_size);
}

void	ft_sprite(void)
{
	int		sprite_id;

	sprite_id = 0;
	update_sprite();
	while (sprite_id < g_param.sprite_count)
	{
		ft_sprite_informations(sprite_id);
		sprite_id++;
	}
}
