/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:33:03 by mac               #+#    #+#             */
/*   Updated: 2021/02/25 17:38:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_map(char *str)
{
	if (str[0] != '\0' && !g_map.test)
		g_map.test = 1;
	if (g_map.test && (str[0] != '\0'))
	g_map.map = ft_strjoin_line(g_map.map, str);
	if (g_map.test && (str[0] == '\0'))
		errors(11);
}

void split_map()
{
	int i;
	int j;
	int width_tmp;

	i = 0;
	
	g_map.all_map=ft_split(g_map.map,'\n');
	check_map();
	while (g_map.all_map[i])
	{
		j = 0;
		width_tmp = 0;
		while (g_map.all_map[i][j])
		{
			width_tmp++;
			j++;
		}
		if (width_tmp > g_map.width)
			g_map.width = width_tmp;
		g_map.heigth++;
		i++;
	}
}

void check_map(void)
{
	int i;
	int j;
	
	i = 0;
	while (g_map.all_map[i])
	{
		j = 0;
		while (g_map.all_map[i][j])
		{
			if ((ft_strchr("102NSEW", g_map.all_map[i][j])) == NULL
				&& (g_map.all_map[i][j] != ' '))
				errors(1);
			j++;
		}
		i++;
	}
}

void map_spacer(void)
{
	int	i;

	i = 0;
	while(g_map.all_map[i])
	{
		g_map.all_map[i] = ft_strjoin(" ",g_map.all_map[i]);
		g_map.all_map[i] = ft_strjoin(g_map.all_map[i]," ");
		i++;
	}
	i = 0;
	while(g_map.all_map[i])
	{
		secure_map(i);
		i++;
	}
}

void secure_map(int i)
{
	int len;
	char *str;
	int f;
	
	f = 0;
	len = g_map.width + 2 - ft_strlen(g_map.all_map[i]);
	str = malloc(sizeof(char ) * len + 1);
	while(len)
	{
		str[f] = ' ';
		len--;
		f++;
	}
	str[f] = '\0';
	g_map.all_map[i] = ft_strjoin(g_map.all_map[i],str);
	
}