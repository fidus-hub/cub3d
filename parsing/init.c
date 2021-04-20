/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:21:29 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 16:56:44 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_sprite(void)
{
	int		i;

	i = 0;
	g_sprite = malloc(sizeof(t_sprite *) * (g_param.sprite_count + 1));
	if (!g_sprite)
		return ;
	while (i < g_param.sprite_count)
	{
		g_sprite[i] = malloc(sizeof(t_sprite));
		if (!g_sprite[i])
			return ;
		g_sprite[i]->ptr = mlx_xpm_file_to_image(g_vars.mlx,
				g_param.sprite_t, &g_sprite[i]->width,
				&g_sprite[i]->height);
		if (!g_sprite[i]->ptr)
			errors(100);
		g_sprite[i]->data = (int *)mlx_get_data_addr(g_sprite[i]->ptr,
				&g_sprite[i]->bpp,
				&g_sprite[i]->ln,
				&g_sprite[i]->endian);
		i++;
	}
	g_sprite[i] = NULL;
}

void	texture_init_2(void)
{
	g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.west_t,
			&g_tex.img_width, &g_tex.img_height);
	if (!g_tex.ptr)
		errors(100);
	g_tex.west = (int *)mlx_get_data_addr(g_tex.ptr, &g_img.bpp,
			&g_img.ln, &g_img.endian);
	g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.east_t,
			&g_tex.img_width, &g_tex.img_height);
	if (!(g_tex.ptr))
		errors(100);
	g_tex.east = (int *)mlx_get_data_addr(g_tex.ptr, &g_img.bpp,
			&g_img.ln, &g_img.endian);
}

void	texture_init(void)
{
	g_tex.offset_x = 0;
	g_tex.offset_y = 0;
	g_tex.dist_ftop = 0;
	g_tex.color = 0;
	g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.north_t,
			&g_tex.img_width, &g_tex.img_height);
	if (!g_tex.ptr)
		errors(100);
	g_tex.north = (int *)mlx_get_data_addr(g_tex.ptr, &g_img.bpp,
			&g_img.ln, &g_img.endian);
	g_tex.ptr = mlx_xpm_file_to_image(g_vars.mlx, g_param.south_t,
			&g_tex.img_width, &g_tex.img_height);
	if (!g_tex.ptr)
		errors(100);
	g_tex.south = (int *)mlx_get_data_addr(g_tex.ptr, &g_img.bpp,
			&g_img.ln, &g_img.endian);
	texture_init_2();
}

void	init(void)
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
	g_param.south_t = NULL;
	g_param.east_t = NULL;
	g_param.west_t = NULL;
	g_param.sprite_t = NULL;
	g_map.map = ft_strdup("");
}

int	check_param(void)
{
	if ((g_param.width != 0 && g_param.height
			!= 0) && (g_param.c_r != -1 && g_param.c_g != -1 && g_param.c_b
			!= -1 && g_param.f_r != -1 && g_param.f_g != -1 && g_param.f_b
			!= -1) && (g_param.north_t != NULL && g_param.south_t
			!= NULL && g_param.east_t != NULL && g_param.west_t
			!= NULL && g_param.sprite_t != NULL))
		return (g_param.check = 1);
	else
		return (g_param.check = 0);
}
