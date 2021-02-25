/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:44:54 by mgrissen          #+#    #+#             */
/*   Updated: 2019/11/09 18:38:10 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	while (s[len] != c)
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return ((char *)s + len);
}
