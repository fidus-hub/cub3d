/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:53:08 by mac               #+#    #+#             */
/*   Updated: 2021/04/20 13:17:56 by mgrissen         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1

# define PI 3.14159265
# define TWO_PI 6.28318530
# define RAD 0.0174532925
# define FLT_MAX 3.4028234664e+38

# define NO 9001
# define WE 9002
# define EA 9003
# define SO 9004
# define S  9005

# define TILE_SIZE 64
# define FOV_ANGLE 1.0471975512

typedef struct s_params
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
	int			sprite_count;
	int			check;
}				t_params;

typedef struct s_player
{
	float		x;
	float		y;
	float		width;
	float		height;
	float		turnDirection;
	float		walkDirection;
	float		rotationAngle;
	float		walkSpeed;
	float		turnSpeed;
	float		fov;
}				t_player;

typedef struct s_ray
{
	float		rayAngle;
	float		wallHitX;
	float		wallHitY;
	float		distance;
	int			vertical;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_ray;

typedef struct s_rays
{
	int			found_HorzHit;
	int			found_VertHit;
	int			horz_content;
	int			vert_content;
	float		x_intercept;
	float		y_intercept;
	float		horz_HitX;
	float		horz_HitY;
	float		vert_HitX;
	float		vert_HitY;
	float		y_step;
	float		x_step;
	float		NHX;
	float		NHY;
	float		NVX;
	float		NVY;
	float		x_check;
	float		y_check;
	float		horz_dist;
	float		vert_dist;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_rays;

typedef struct s_map
{
	char		*map;
	char		**all_map;
	char		**spaces;
	int			width;
	int			heigth;
	int			test;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			save;
}				t_vars;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ln;
	int			endian;
}				t_data;

typedef struct s_tex
{
	void		*ptr;
	int			img_width;
	int			img_height;
	int			bpp;
	int			size_line;
	int			endian;
	int			*north;
	int			*south;
	int			*east;
	int			*west;
	int			offset_x;
	int			offset_y;
	int			dist_ftop;
	int			color;
}				t_tex;

typedef struct s_sprite
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			ln;
	int			endian;
	int			width;
	int			height;
	float		x;
	float		y;
	float		distance;
}				t_sprite;

typedef struct s_3d
{
	float		perpDistance;
	float		distanceProjPlane;
	float		projectedWallHeight;
	int			wallStripHeight;
	int			wallTopPixel;
	int			wallBottomPixel;
}				t_3d;

t_data		g_img;
t_map		g_map;
t_params	g_param;
t_vars		g_vars;
t_player	g_player;
t_ray		g_ray[3000];
t_rays		g_rays;
t_3d		g_3d;
t_tex		g_tex;
t_sprite	**g_sprite;

void			my_mlx_pixel_put(t_data *img, int x, int y, int color);

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_line(char *s1, char *s2);

int				get_next_line(int fd, char **line);

void			init(void);
void			cub3d_init(void);

void			check_comma(char *line);

int				rgb_to_int(int r, int g, int b);

void			get_file(int ac, char **av);
void			treat_file(char *line);
int				check_R_number(char **str);
void			get_r(char *line);
void			get_f(char *line);
void			get_c(char *line);
int				check_rgb(char **str);
int				check_rgb_number(char **str);
void			get_check_txt(char *line, int txt);
int				check_param(void);
int				notmap(char *buffer);
void			get_map(char *str);
void			split_map(char *str);
void			check_map(void);
void			check_map_2(void);
void			map_spacer(void);
void			secure_map(int i);
void			check_zero(void);
void			check_zero_errors(int i, int j);
void			check_player(void);
void			meme_free(char **str);

int				set_player(void);

void			errors(int i);
int				ft_quit(int keycode);

float			distance_between_points(float x1, float y1, float x2, float y2);
float			normalizeAngle(float angle);
int				is_wall(float x, float y);
int				map_has_wall(float x, float y);

int				play(void);
int				key_hook(void);
int				key_pressed(int keycode);
int				key_released(int keycode);

void			cast_all_rays(void);
void			vert_ray_init(float rayAngle);
void			horz_ray_init(float rayAngle);
void			render_3d(int stripId);

void			texture_init(void);

void			ft_sprite(void);
void			init_sprite(void);

void			get_c(char *line);

void			bmp_save(void);
#endif