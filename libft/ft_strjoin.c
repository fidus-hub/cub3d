/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:17:14 by mgrissen          #+#    #+#             */
/*   Updated: 2019/11/16 13:36:57 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) *
				((ft_strlen(s1)) + (ft_strlen(s2)) + 1))))
		return (0);
	j = ft_strlen(s1);
	ft_strcpy(new, s1);
	ft_strcpy(new + j, s2);
	return (new);
}
