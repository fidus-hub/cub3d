/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_r_c_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:35:16 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:35:17 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_r(char *line)
{
	char	**str;
	int		i;

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
	meme_free(str);
}

void	get_f_2(char **str2)
{
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
}

void	get_f(char *line)
{
	char	**str;
	char	**str2;
	int		i;

	i = 0;
	str = ft_split(line, ' ');
	if (check_rgb(str) != 2)
		errors(4);
	str2 = ft_split(str[1], ',');
	check_comma(line);
	if (check_rgb_number(str2) != 3)
		errors(4);
	if (g_param.f_r != -1 && g_param.f_g != -1 && g_param.f_b != -1)
		errors(2);
	if (str2[0][0] == '-' || str2[1][0] == '-' || str2[2][0] == '-')
		errors(3);
	get_f_2(str2);
	meme_free(str);
	meme_free(str2);
}

void	get_c_2(char **str2)
{
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
}

void	get_c(char *line)
{
	char	**str;
	char	**str2;
	int		i;

	i = 0;
	str = ft_split(line, ' ');
	if (check_rgb(str) != 2)
		errors(4);
	str2 = ft_split(str[1], ',');
	check_comma(line);
	if (check_rgb_number(str2) != 3)
		errors(4);
	if (g_param.c_r != -1 && g_param.c_g != -1 && g_param.c_b != -1)
		errors(2);
	if (str2[0][0] == '-' || str2[1][0] == '-' || str2[2][0] == '-')
		errors(3);
	get_c_2(str2);
	meme_free(str);
	meme_free(str2);
}
