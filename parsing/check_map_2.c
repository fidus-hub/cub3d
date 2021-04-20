/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:35:02 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:35:03 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_2(void)
{
	int	i;
	int	j;
	int	width_tmp;

	i = 0;
	while (g_map.all_map[i])
	{
		j = 0;
		width_tmp = 0;
		while (g_map.all_map[i][j])
		{
			if (g_map.all_map[i][j] == '2')
				g_param.sprite_count++;
			width_tmp++;
			j++;
		}
		if (width_tmp > g_map.width)
			g_map.width = width_tmp;
		g_map.heigth++;
		i++;
	}
}
