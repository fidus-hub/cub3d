# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 15:54:56 by mac               #+#    #+#              #
#    Updated: 2021/04/21 16:39:39 by mgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = gnl/get_next_line_utils.c gnl/get_next_line.c
LIBFT = libft/
PARSING = parsing/check_map_2.c parsing/errors.c parsing/ft_strjoin_line.c \
			parsing/get_parametrs.c parsing/init.c parsing/parser_utils.c \
			parsing/routing.c parsing/check_rgb.c parsing/file_reader.c \
			parsing/get_map.c parsing/get_r_c_f.c parsing/map_utils.c \
			parsing/rgb_to_int.c
OUTSIDE = extra_utils.c raycast.c render_3d.c events.c ft_sprite.c \
			raycast_init.c screenshot.c utils.c

SRC = $(LIBFT)/libft.a $(GNL) $(PARSING) $(OUTSIDE)
OBJ = $(SRC:.c=.o)
MLX_FLAG =  -lmlx -framework OpenGL -framework AppKit  -O3
NAME = cub3D
GNL_FLAGS = -D BUFFER_SIZE=32

all : $(NAME)

$(NAME) :
		@make -C $(LIBFT)
		@gcc $(SRC) -o $(NAME) $(MLX_FLAG)
clean :
		rm -rf $(OBJ)
fclean : clean
		rm -rf $(NAME)
re : fclean all