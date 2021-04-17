/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parametrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:01:48 by mac               #+#    #+#             */
/*   Updated: 2021/04/17 17:32:16 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void	meme_free(char **str)
{
	int i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}


void	get_r(char *line)
{
	char **str;
	int i;
	
	i = 0;
	str = ft_split(line, ' ');
	if (g_param.width != 0 && g_param.height != 0)
		errors(2);
	if (check_R_number(str) != 3)
		errors(4);
	if (str[1][0] == '-' || str[2][0] == '-')
		errors(3);
	g_param.width = ft_atoi(str[1]);
	g_param.height = ft_atoi(str[2]);
	if (g_param.width > 2550)
		g_param.width = 2550;
	if (g_param.height > 1500)
		g_param.height = 1500;
	if (g_param.width < 0)
		g_param.width = 2550;
	if (g_param.height < 0)
		g_param.height = 1500;
		
	
	printf("width =%d, height = %d\n", g_param.width, g_param.height);
	meme_free(str); 

}

void	get_f(char *line)
{
	char **str;
	char **str2;
	int i;
	
	i = 0;
	str = ft_split(line, ' ');
	if	(check_rgb(str) != 2)
		errors(4);
	str2 = ft_split(str[1], ',');
	
	check_comma(line);
	if (check_rgb_number(str2) != 3)
		errors(4);
	if (g_param.f_r != -1 && g_param.f_g != -1 && g_param.f_b != -1)
		errors(2);
	if (str2[0][0] == '-' || str2[1][0] == '-' || str2[2][0] == '-')
		errors(3);
	if (ft_atoi(str2[0]) >= 0 && ft_atoi(str2[0]) < 256
		&& ft_atoi(str2[1]) >= 0 && ft_atoi(str2[1]) < 256
		&& ft_atoi(str2[2]) >= 0 && ft_atoi(str2[2]) < 256)
	{
		g_param.f_r = ft_atoi(str2[0]);
		g_param.f_g = ft_atoi(str2[1]);
		g_param.f_b = ft_atoi(str2[2]);
	}
	else
		errors(7);

	printf("F_R =%d, F_G = %d, F_B = %d\n", g_param.f_r, g_param.f_g, g_param.f_b);
	meme_free(str);
	meme_free(str2);
}

void	get_c(char *line)
{
	char **str;
	char **str2;
	int i;
	
	i = 0;
	str = ft_split(line, ' ');
	if	(check_rgb(str) != 2)
		errors(4);
	str2 = ft_split(str[1], ',');
	
	check_comma(line);
	if (check_rgb_number(str2) != 3)
		errors(4);
	if (g_param.c_r != -1 && g_param.c_g != -1 && g_param.c_b != -1)
		errors(2);
	if (str2[0][0] == '-' || str2[1][0] == '-' || str2[2][0] == '-')
		errors(3);
	if (ft_atoi(str2[0]) >= 0 && ft_atoi(str2[0]) < 256
		&& ft_atoi(str2[1]) >= 0 && ft_atoi(str2[1]) < 256
		&& ft_atoi(str2[2]) >= 0 && ft_atoi(str2[2]) < 256)
	{
		g_param.c_r = ft_atoi(str2[0]);
		g_param.c_g = ft_atoi(str2[1]);
		g_param.c_b = ft_atoi(str2[2]);
	}
	else
		errors(8);

	printf("C_R =%d, C_G = %d, C_B = %d\n", g_param.c_r, g_param.c_g, g_param.c_b);
	meme_free(str);
	meme_free(str2);
}

void	get_check_txt(char *line, int txt)
{
	char **str;
	
	str = ft_split(line, ' ');
	
	if (check_rgb(str) != 2)
		errors(4);
	else if (txt == NO && g_param.north_t == NULL)
		g_param.north_t = ft_strdup(str[1]);
	else if (txt == WE && g_param.west_t == NULL)
		g_param.west_t = ft_strdup(str[1]);
	else if (txt == EA && g_param.east_t == NULL)
		g_param.east_t = ft_strdup(str[1]);
	else if (txt == SO && g_param.south_t == NULL)
		g_param.south_t = ft_strdup(str[1]);
	else if (txt == S && g_param.sprite_t == NULL)
		g_param.sprite_t = ft_strdup(str[1]);
	else
		errors(2);
	meme_free(str);
}

int main()
{
	int i;
	init();

	i = 0;
	get_file();
	split_map(g_map.map);
	map_spacer();
	check_zero();
	check_player();
	//! check this 
	g_map.width =  ft_strlen(g_map.all_map[0]);
	g_vars.mlx = mlx_init();
	g_vars.win = mlx_new_window(g_vars.mlx, g_param.width, g_param.height,
				 "Fidus world");
	
	
	//draw_map();
	draw_player();
	texture_init();
	mlx_loop_hook(g_vars.mlx,play,0);
//	mlx_key_hook(g_vars.win, key_hook, 0);

	mlx_loop(g_vars.mlx);
	

	return (0);
}