/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:53:08 by mac               #+#    #+#             */
/*   Updated: 2021/03/28 14:47:20 by mgrissen         ###   ########.fr       */
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
# include <mlx.h>


# define PI 3.14159265
# define TWO_PI 6.28318530
# define rad (PI / 180)

# define NO 9001
# define WE 9002
# define EA 9003
# define SO 9004
# define S  9005

# define tile_size 64
# define fov_angle (60 * (PI / 180))



typedef	struct	s_params
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
}				t_params;

typedef struct	s_move
{
	int			up;
}				t_move;


typedef struct s_player
{
	float x;
	float y;
	float width;
	float height;
	float turnDirection;
	float walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
	float fov;
}				t_player;

t_player		g_player;	

typedef struct	s_map
{
	char *map;
	char **all_map;
	char **spaces;
	int width;
	int heigth;
	int test;
}				t_map;

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct s_data {
	void *img;
	char *addr;
	int bpp;
	int ln;
	int endian;
}               t_data;

t_data			img;
t_map			g_map;
t_params		g_param;
t_vars			g_vars;
t_move			g_move;

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
void			split_map(char* str);
void			check_map(void);
void			map_spacer(void);
void 			secure_map(int i);
void			check_zero(void);
void			check_zero_errors(int i, int j);
void			check_player(void);
void			meme_free(char **str);
void			cub3d_init();
int				draw_map(void);
void			draw_circle(int x, int y, int r, int color);
void			draw_rec(int x, int y);
int				key_hook(void);
int				draw_player(void);
int				play();
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
int				is_wall(float x, float y);
int				key_pressed(int keycode);
int				key_released(int keycode);





#endif