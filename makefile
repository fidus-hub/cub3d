# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 15:54:56 by mac               #+#    #+#              #
#    Updated: 2021/04/13 16:08:12 by mgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = gnl/
LIBFT = libft/
PARSING = parsing/

SRC = $(LIBFT)/libft.a $(GNL)/*.c $(PARSING)/*.c  *.c
OBJ = $(SRC:.c=.o)
MLX_FLAG =  -lmlx -framework OpenGL -framework AppKit 
NAME = CUB3D
GNL_FLAGS = -D BUFFER_SIZE=32

USELESS_FLAG = -fsanitize=address

all : $(NAME)

$(NAME) :
		@make -C $(LIBFT)
		@gcc -g3 $(SRC) -o $(NAME) $(MLX_FLAG) -g -fsanitize=address
clean :
		rm -rf $(OBJ)
fclean : clean
		rm -rf $(NAME)
re : fclean all