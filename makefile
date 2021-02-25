# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 15:54:56 by mac               #+#    #+#              #
#    Updated: 2021/02/23 12:00:51 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL = gnl/
LIBFT = libft/
PARSING = parsing/

SRC = $(LIBFT)/libft.a $(GNL)/*.c $(PARSING)/*.c 
MLX_FLAG = mlx_flags
NAME = CUB3D
GNL_FLAGS = -D BUFFER_SIZE=32

USELESS_FLAG = -fsanitize=address

all : $(NAME)

$(NAME) :
		@$(MAKE) -C $(LIBFT)
		@gcc -Wall -Wextra -Werror  $(SRC) $(USELESS_FLAG) -o $(NAME)
clean :
		@$(MAKE) -C $(LIBFT) clean 
fclean : clean
		 @$(MAKE) -C $(LIBFT) fclean 
		 @rm $(NAME)
re : fclean all
test : 
		@gcc -Wall -Wextra -Werror -g3 $(SRC) $(USELESS_FLAG) -o $(NAME)