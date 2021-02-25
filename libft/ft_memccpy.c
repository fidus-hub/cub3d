/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:40:14 by mgrissen          #+#    #+#             */
/*   Updated: 2019/11/16 12:46:52 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		(d[i] = s[i]);
		if (s[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
