/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidus <fidus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:54:35 by fidus             #+#    #+#             */
/*   Updated: 2021/04/19 15:40:46 by fidus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_headers(unsigned char *bmpfileheader, unsigned char *bmpinfoheader)
{
	int		filesize;

	filesize = 54 + 3 * g_param.width * g_param.height;
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	bmpinfoheader[4] = (unsigned char)(g_param.width);
	bmpinfoheader[5] = (unsigned char)(g_param.width >> 8);
	bmpinfoheader[6] = (unsigned char)(g_param.width >> 16);
	bmpinfoheader[7] = (unsigned char)(g_param.width >> 24);
	bmpinfoheader[8] = (unsigned char)(g_param.height);
	bmpinfoheader[9] = (unsigned char)(g_param.height >> 8);
	bmpinfoheader[10] = (unsigned char)(g_param.height >> 16);
	bmpinfoheader[11] = (unsigned char)(g_param.height >> 24);
}

void	write_bmp_data(int fd, char *bitmap)
{
	int		padding_size;
	int		i;
	int		j;

	padding_size = (4 - (g_param.width * 3) % 4) % 4;
	i = -1;
	while (++i < g_param.height)
	{
		j = -1;
		while (++j < g_param.width)
			write(fd, (int *)g_img.addr + (
					j + (g_param.height - i - 1) * g_param.width), 3);
		write(fd, bitmap, padding_size);
	}
}

void	bmp_save(void)
{
	static unsigned char	bmpfileheader[14] = {'B', 'M'
	, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	static unsigned char	bmpinfoheader[40] = {40, 0
	, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	static char				bitmap[3] = {0, 0, 0};
	int						fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	init_headers(bmpfileheader, bmpinfoheader);
	write(fd, bmpfileheader, 14);
	write(fd, bmpinfoheader, 40);
	write_bmp_data(fd, bitmap);
	close(fd);
}
