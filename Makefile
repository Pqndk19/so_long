# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:27:34 by mmassa-r          #+#    #+#              #
#    Updated: 2023/03/13 11:27:35 by mmassa-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Werror -Wextra -Wall
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
MINILIBX = ./mlx
SRC = ./so_long.c ./map.c ./map_rules.c ./utils.c ./valid_path.c ./mlx_init.c ./mlx_image.c \
		./hooks.c ./map_uploader.c


OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
		$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
		$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o so_long

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all
