/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:21:29 by mac               #+#    #+#             */
/*   Updated: 2021/04/17 17:35:38 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_init(void)
{
	g_tex.offset_x = 0;
	g_tex.offset_y = 0;
	g_tex.dist_ftop = 0;
	g_tex.color = 0;

	// NORTH
	if (!(g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.north_t,
	&g_tex.img_width, &g_tex.img_height)))
		errors(100);
	g_tex.north = (int *)mlx_get_data_addr(g_tex.ptr, &img.bpp , &img.ln, &img.endian);

	// SOUTH
		if (!(g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.south_t,
	&g_tex.img_width, &g_tex.img_height)))
		errors(100);
	g_tex.south = (int *)mlx_get_data_addr(g_tex.ptr, &img.bpp , &img.ln, &img.endian);

	// WEST

		if (!(g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.west_t,
	&g_tex.img_width, &g_tex.img_height)))
		errors(100);
	g_tex.west = (int *)mlx_get_data_addr(g_tex.ptr, &img.bpp , &img.ln, &img.endian);

	// east

		if (!(g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.east_t,
	&g_tex.img_width, &g_tex.img_height)))
		errors(100);
	g_tex.east = (int *)mlx_get_data_addr(g_tex.ptr, &img.bpp , &img.ln, &img.endian);
}

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