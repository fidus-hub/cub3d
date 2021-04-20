/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:15:59 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 16:30:45 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_comma(char *line)
{
	int		comma;

	comma = 0;
	while (*line)
	{
		if (*line == ',')
		{
			comma++;
			if (comma > 2)
				errors(6);
		}
		line++;
	}
}
