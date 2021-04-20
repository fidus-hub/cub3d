/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:37:21 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 16:40:13 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_zero_2(void)
{
	int	i;
	int	j;

	i = g_map.heigth - 2;
	while (i > 0)
	{
		j = 0;
		while (g_map.all_map[i][j])
		{
			if ((g_map.all_map[i][j] == '0')
				|| (g_map.all_map[i][j] == '2'))
				check_zero_errors(i, j);
			j++;
		}
		i--;
	}
}

void	check_zero(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_map.all_map[0][i])
	{
		if ((((g_map.all_map[0][i])) != '1') && (g_map.all_map[0][i] != ' '))
			errors(10);
		i++;
	}
	i = g_map.heigth - 1;
	while (g_map.all_map[i][j])
	{
		if ((((g_map.all_map[i][j])) != '1') && (g_map.all_map[i][j] != ' '))
			errors(10);
		j++;
	}
	check_zero_2();
}

void	check_zero_errors(int i, int j)
{
	if (g_map.all_map[i + 1][j] == ' ')
		errors(10);
	if (g_map.all_map[i - 1][j] == ' ')
		errors(10);
	if (g_map.all_map[i][j + 1] == ' ')
		errors(10);
	if (g_map.all_map[i][j - 1] == ' ')
		errors(10);
}

void	set_rotation_angle(char position)
{
	if (position == 'N')
		g_player.rotationAngle = 180 * RAD;
	if (position == 'S')
		g_player.rotationAngle = 360 * RAD;
	if (position == 'W')
		g_player.rotationAngle = 270 * RAD;
	if (position == 'E')
		g_player.rotationAngle = 90 * RAD;
}

void	check_player(void)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (g_map.all_map[i])
	{
		j = 0;
		while (g_map.all_map[i][j])
		{
			if ((ft_strchr("NSEW", g_map.all_map[i][j])) != NULL)
			{
				player++;
				set_rotation_angle(g_map.all_map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		errors(12);
}
