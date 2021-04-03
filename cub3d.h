/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:53:08 by mac               #+#    #+#             */
/*   Updated: 2021/04/01 17:29:35 by mgrissen         ###   ########.fr       */
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
# include <limits.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <mlx.h>

#define FALSE 0
#define TRUE 1
# define PI 3.14159265
# define TWO_PI 6.28318530
# define rad (PI / 180)
# define FLT_MAX  3.4028234664e+38

# define NO 9001
# define WE 9002
# define EA 9003
# define SO 9004
# define S  9005

# define tile_size 64
# define fov_angle (60 * (PI / 180))

#define WALL_STRIP_WIDTH  1
#define NUM_RAYS  g_map.width / WALL_STRIP_WIDTH


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

typedef struct s_ray
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	int vertical;
	int up;
	int down;
	int left;
	int right;
	int content;
}				t_ray[1000];

typedef struct s_rays
{
	int found_HorzHit;
	int found_VertHit;
	int horz_content;
	int vert_content;
	float x_intercept;
	float y_intercept;
	float horz_HitX;
	float horz_HitY;
	float vert_HitX;
	float vert_HitY;
	float y_step;
	float x_step;
	float NHX;
	float NHY;
	float NVX;
	float NVY;
	float x_check;
	float y_check;
	float horz_dist;
	float vert_dist;

	int up;
	int down;
	int left;
	int right;
	int content;
	
}				t_rays;


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
t_ray			g_ray;
t_rays			g_rays;

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
void			DDA(int X0, int Y0, int X1, int Y1, int color);
void			cast_all_rays();
int				map_has_wall(float x, float y);
void		draw_line_2(float y, float x, float y1,	float x1, float ray_angle, int color);
float	distancebetweenpts(float xd, float yd, float xf, float yf);




#endif