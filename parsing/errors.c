/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:15:24 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 13:16:04 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_quit(int keycode)
{
	exit(0);
	return (0);
}

void	more_errors(int i)
{
	if (i == 10)
		printf("Error\nInvalid map.");
	if (i == 11)
		printf("Error\nNew line.");
	if (i == 12)
		printf("Error\nInvalid player number.");
	if (i == 13)
		printf("Error\nAdd a map.");
	if (i == 69)
		printf("Error \nInvalid File Configuration.");
	if (i == 100)
		printf("Error\nTexture file not found!");
	if (i == 111)
		printf("Error\nArguments number is too high or low.");
	if (i == 112)
		printf("Error\nSecond argument is wrong.");
}

void	errors(int i)
{
	if (i == 1)
		printf("Error\nCheck your map.");
	if (i == 2)
		printf("Error\nDouble inclusion.");
	if (i == 3)
		printf("Error\nNegative value.");
	if (i == 4)
		printf("Error\nWrong number of arguments.");
	if (i == 5)
		printf("Error\nNot a valid argument.");
	if (i == 6)
		printf("Error\nUse only 2 commas.");
	if (i == 7)
		printf("Error\nInvalid Floor RGB Values");
	if (i == 8)
		printf("Error\nInvalid Ceiling RGB Values");
	if (i == 9)
		printf("Error\nInvalid Line.");
	more_errors(i);
	exit(0);
}
