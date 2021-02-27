/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:15:24 by mac               #+#    #+#             */
/*   Updated: 2021/02/27 15:35:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void errors(int i)
{
	if (i == 1)
		printf("ERROR\ncheck your map");
	if (i == 2)
		printf("ERROR\nDOUBLE INCLUSION");
	if (i == 3)
		printf("ERROR\nNEGATIVE VALUE");
	if (i == 4)
		printf("ERROR\nWRONG NUMBER OF ARGUMENTS");
	if (i == 5)
		printf("ERROR\nNOT A VALID ARGUMENT");
	if (i == 6)
		printf("ERROR\nUSE ONLY 2 COMMAS ");
	if (i == 7)
		printf("ERROR\nINVALID FLOOR RGB VALLUES");
	if (i == 8)
		printf("ERROR\nINVALID CEILLING RGB VALLUES");
	if (i == 9)
		printf("ERROR\nINVALID LINE");
	if (i == 10)
		printf("ERROR\nINVALID MAP");
	if (i == 11)
		printf("ERROR\nNEW LINE");
	if (i == 12)
		printf("ERROR\nINVALID PLAYER NUMBER");
	if (i == 13)
		printf("ERROR\n ADD A MAP");
	if (i == 69)
		printf("ERROR \n INVALID FILE CONFIGURATION");
		
		
	exit(0);
}

int		check_R_number(char **str)
{
	int		i;
	int		j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				errors(5);
			j++;
		}
		i++;
	}
	return (i);
}

int		check_rgb_number(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				errors(5);
			j++;
		}
		i++;
	}
	return (i);
}

int		check_rgb(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

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