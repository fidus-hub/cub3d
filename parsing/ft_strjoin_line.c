/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:35:10 by mgrissen          #+#    #+#             */
/*   Updated: 2021/04/20 17:35:11 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	i = -1;
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	j = -1;
	if (s2[0] == '\n')
		errors(1);
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}
