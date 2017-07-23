# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 12:58:52 by sdarsie           #+#    #+#              #
#    Updated: 2017/05/22 14:27:36 by sdarsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = ./libft/libft.a
LIB_MLX = ./minilibx_macos/libmlx.a
LIBFTINC = -L ./libft/ -lft
MINILIB = -L ./minilibx_macos/ -lmlx

SRC_DIR = ./src/
FILES = main.c \
		clear_data.c \
		get_data.c \
		prep_data.c \
		begin.c \
		lines.c  \
		modify_z.c \
		rot_matrices.c \
		error.c \
		n_x_rot.c \

SRCS = $(addprefix $(SRC_DIR),$(FILES))

CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit

OBJ_DIR = ./obj/
OBJ_NAME = $(FILES:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

INC = -I ../fdf.h

all: obj $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIB_MLX)
	gcc -o $(NAME) $(OBJS) $(CFLAGS) $(MINILIB) $(LIBFTINC) $(FRAMEWORKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) -o $@ -c $<  

obj:
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C ./libft

$(LIB_MLX):
	make -C ./minilibx_macos

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx_macos

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all
