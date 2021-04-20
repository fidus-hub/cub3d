/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:51:39 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 16:28:15 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi_completion(int i, int num, int neg, const char *str)
{
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		if (num <= (9223372036854775807 - (str[i] - 48)) / 10)
			num = num * 10 + (str[i] - 48);
		else
		{
			if (neg == -1)
				num = 0;
			else
				num = -1;
			break ;
		}
		i++;
	}
	return (num * neg);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (ft_atoi_completion(i, num, neg, str));
}

static size_t	ft_numwords(char const *s, char c)
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

static char	**ft_free(char **str, int num)
{
	while (--num)
		free(&str[num]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	**str;

	if (s == 0)
		return (0);
	len = 0;
	i = 0;
	str = (char **)malloc(sizeof(char *) * ((size_t)ft_numwords(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < (size_t)ft_numwords(s, c) + 1 - 1)
	{
		while (s[len] == c && s[len])
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		str[i++] = ft_substr(s, start, (len - start));
		if (!str)
			return (ft_free(str, (size_t)ft_numwords(s, c) + 1));
	}
	str[i] = 0;
	return (str);
}
