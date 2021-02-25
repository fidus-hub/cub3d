/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:21:29 by mac               #+#    #+#             */
/*   Updated: 2021/02/24 16:39:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

 void init()
 {
	g_param.width = 0;
	g_param.height = 0;
	g_param.c_r = -1;
	g_param.c_g = -1;
	g_param.c_b = -1;
	g_param.f_r = -1;
	g_param.f_g = -1;
	g_param.f_b = -1;
	g_param.north_t = NULL;
	g_param.south_t	 = NULL;
	g_param.east_t = NULL;
	g_param.west_t = NULL;
	g_param.sprite_t = NULL;
	g_map.map = ft_strdup("");
 }

 int check_param()
 {
	 if ((g_param.width != 0 && g_param.height != 0) &&
	 (g_param.c_r != -1 && g_param.c_g != -1 && g_param.c_b != -1 &&
	  g_param.f_r != -1 && g_param.f_g != -1 && g_param.f_b != -1) &&
	 (g_param.north_t != NULL && g_param.south_t != NULL &&
	 g_param.east_t != NULL && g_param.west_t != NULL &&
	 g_param.sprite_t != NULL))
	 	return (g_param.check = 1);
	else
		return (g_param.check = 0);
 }