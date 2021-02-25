/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:30:33 by mgrissen          #+#    #+#             */
/*   Updated: 2019/11/16 12:47:34 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (b);
}
