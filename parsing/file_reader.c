/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidus <fidus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:07:13 by mac               #+#    #+#             */
/*   Updated: 2021/04/19 16:03:48 by fidus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_file_norm(int fd, char *line)
{
	int	n;

	n = 1;
	while (n)
	{
		n = get_next_line(fd, &line);
		if (n < 0)
			errors(69);
		if (!(check_param()))
		{
			if (*line != '\0')
				treat_file(line);
		}
		else
			treat_file(line);
		if (n == 0)
			break ;
		free(line);
	}
	free(line);
}

void	get_file(int ac, char **av)
{
	char	*line;
	int		fd;
	int		n;

	g_vars.save = 0;
	if (ac < 2 || ac > 3)
		errors(111);
	fd = open(av[1], O_RDONLY);
	if (av[2])
	{
		if (!ft_strncmp(av[2], "--save", 15))
			g_vars.save = 1;
		else
			errors(112);
	}
	get_file_norm(fd, line);
}

void	treat_file(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'R' && line[++i] == ' ')
		get_r(line);
	else if (line[i] == 'F' && line [++i] == ' ')
		get_f(line);
	else if (line[i] == 'C' && line [++i] == ' ')
		get_c(line);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_check_txt(line, NO);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_check_txt(line, WE);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_check_txt(line, EA);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_check_txt(line, SO);
	else if (line[i] == 'S' && line [++i] == ' ')
		get_check_txt(line, S);
	else if (check_param())
		get_map(line);
	else
		errors(9);
}
