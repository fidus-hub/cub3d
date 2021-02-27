/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:53:08 by mac               #+#    #+#             */
/*   Updated: 2021/02/27 11:13:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>

# define NO 9001
# define WE 9002
# define EA 9003
# define SO 9004
# define S  9005



typedef	struct	s_param
{
	int			width;
	int			height;
	int			c_r;
	int			c_g;
	int			c_b;
	int			f_r;
	int			f_g;
	int			f_b;
	char		*north_t;
	char		*south_t;
	char		*west_t;
	char		*east_t;
	char		*sprite_t;
	int			check;
}				t_param;

typedef struct	s_map
{
	char *map;
	char **all_map;
	char **spaces;
	int width;
	int heigth;
	int test;
}				t_map;

t_map			g_map;
t_param			g_param;

int				ft_isdigit(int c);
void			get_file();
void			treat_file(char *line);
void			get_r(char *line);
int				check_R_number(char **str);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void 			errors(int i);
void			get_f(char *line);
void			get_c(char *line);
void			check_comma(char *line);
int				check_rgb(char **str);
int				check_rgb_number(char **str);
void			get_check_txt(char *line, int txt);
int				check_param();
void 			init();
int				notmap(char *buffer);
void			get_map(char *str);
char			*ft_strjoin_line(char *s1, char *s2);
void			split_map();
void 			check_map(void);
void			map_spacer(void);
void 			secure_map(int i);
void			check_zero(void);
void    		check_zero_errors(int i, int j);
void			check_player(void);

#endif