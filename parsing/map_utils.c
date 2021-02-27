/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:37:21 by mac               #+#    #+#             */
/*   Updated: 2021/02/27 15:40:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
char    *ft_strjoin_line(char *s1, char *s2)
{
    char    *str;
    int     i;
    int     j;
    if (!s2)
        return (s1);
    if (!s1)
        return (s2);
    str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
    i = -1;
    while (s1[++i])
    {
        str[i] = s1[i];
    }
    j = -1;
    if (s2[0] == '\n')
        errors(1);
    while (s2[++j])
    {
        str[i] = s2[j];
        i++;
    }
    str[i] = '\n';
    str[i + 1] = '\0';
    free(s1);
    return (str);
}

void    check_zero(void)
{
    int i;
    int j;
    
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
    i = g_map.heigth - 2;
    while (i > 0)
	{
		j = 0;
		while (g_map.all_map[i][j])
		{
            if ((g_map.all_map[i][j] == '0') ||
            (g_map.all_map[i][j] == '2'))
                check_zero_errors(i, j);
			j++;
		}
		i--;
    }
}

void    check_zero_errors(int i, int j)
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

void	check_player(void)
{
	int i;
	int j;
    int player;
	
	i = 0;
    player = 0;
	while (g_map.all_map[i])
	{
		j = 0;
		while (g_map.all_map[i][j])
		{
			if ((ft_strchr("NSEW", g_map.all_map[i][j])) != NULL)
				player++;
			j++;
		}
		i++;
	}
    if (player != 1)
        errors(12);
}