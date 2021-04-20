/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parametrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:01:48 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 13:17:38 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	meme_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	get_check_txt(char *line, int txt)
{
	char	*linee;
	char	*line_sprite;

	linee = ft_substr(line, 3, ft_strlen(line));
	line_sprite = ft_substr(line, 2, ft_strlen(line));
	if (txt == NO && g_param.north_t == NULL)
		g_param.north_t = ft_strdup(linee);
	else if (txt == WE && g_param.west_t == NULL)
		g_param.west_t = ft_strdup(linee);
	else if (txt == EA && g_param.east_t == NULL)
		g_param.east_t = ft_strdup(linee);
	else if (txt == SO && g_param.south_t == NULL)
		g_param.south_t = ft_strdup(linee);
	else if (txt == S && g_param.sprite_t == NULL)
		g_param.sprite_t = ft_strdup(line_sprite);
	else
		errors(2);
}

int	main(int ac, char **av)
{
	init();
	get_file(ac, av);
	split_map(g_map.map);
	map_spacer();
	check_zero();
	check_player();
	g_map.width = ft_strlen(g_map.all_map[0]);
	g_vars.mlx = mlx_init();
	g_vars.win = mlx_new_window(g_vars.mlx, g_param.width, g_param.height,
			"Fidus world");
	set_player();
	texture_init();
	init_sprite();
	mlx_loop_hook(g_vars.mlx, play, 0);
	mlx_loop(g_vars.mlx);
	return (0);
}
