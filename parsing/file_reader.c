/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:07:13 by mac               #+#    #+#             */
/*   Updated: 2021/03/14 17:14:59 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_file()
{
		int fd;
		char *line;
		int	n;
		fd = open("map.cub", O_RDONLY);
		n = 1;
		while (n)
		{
			n = get_next_line(fd, &line);
			if (n < 0)
				errors(69);
			if (!(check_param()))
			{
				if(*line != '\0')
					treat_file(line);
			}
			else
				treat_file(line);
			if (n == 0)
				break;
			free(line);
		}
	free(line);
}

void	treat_file(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if  (line[i] == 'R' && line[++i] == ' ')
		get_r(line);
	else if	(line[i] == 'F' && line [++i] == ' ')
		get_f(line);
	else if	(line[i] == 'C' && line [++i] == ' ')
		get_c(line);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_check_txt(line, NO);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_check_txt(line, WE);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_check_txt(line, EA);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_check_txt(line, SO);
	else if	(line[i] == 'S' && line [++i] == ' ')
		get_check_txt(line, S);
	else if (check_param())
		get_map(line);
	else
		errors(9);
}