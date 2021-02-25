/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:51:39 by mac               #+#    #+#             */
/*   Updated: 2021/02/22 18:41:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}


int		ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;
	long	max;
	max = 9223372036854775807;
	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		if (num <= ((max - (str[i] - 48)) / 10))
			num = num * 10 + (str[i] - 48);
		else
		{
			num = (neg == -1) ? 0 : -1;
			break ;
		}
		i++;
	}
	return (num * neg);
}

static size_t		ft_numwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			count++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char			**ft_free(char **str, int num)
{
	while (--num)
		free(&str[num]);
	free(str);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num;
	size_t	start;
	size_t	len;
	char	**str;

	if (s == 0)
		return (0);
	len = 0;
	i = 0;
	num = ft_numwords(s, c) + 1;
	if (!(str = (char **)malloc(sizeof(char *) * (num))))
		return (NULL);
	while (i < num - 1)
	{
		while (s[len] == c && s[len])
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		if (!(str[i++] = ft_substr(s, start, (len - start))))
			return (ft_free(str, num));
	}
	str[i] = 0;
	return (str);
}