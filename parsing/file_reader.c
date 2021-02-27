/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:07:13 by mac               #+#    #+#             */
/*   Updated: 2021/02/25 21:33:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_file()
{
		int fd;
		char *line;
		int	n;
		/*
		if((fd = open("map.cub", O_RDONLY);) == -1)
		{
			perror(strerror(errno));
			exit(0);
		}
		*/
		fd = open("map.cub", O_RDONLY);
		n = 1;
		while (n)
		{
			n = get_next_line(fd, &line);
			treat_file(line);
		}
}

void	treat_file(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
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