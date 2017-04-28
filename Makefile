NAME = fdf
NAME2 = libft/libft.a
LIBFTINC = -L ./libft/ -lft
MINILIB = -L ./minilibx_macos/ -lmlx
FILES = main.c \
		clear_data.c \
		get_data.c \
		prep_data.c \
		begin.c \
		lines.c  \
		modify_z.c \
		rot_matrices.c \
		error.c \

CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
SRCS = libft/libft.a minilibx_macos/libmlx.a
LIB = libft/*.c
BIN = libft/*.o libft/libft.a

all: $(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx_macos
	ar rc $(NAME2) $(BIN)
	gcc -o $(NAME) $(FILES) $(MINILIB) $(LIBFTINC) $(FRAMEWORKS)

clean:
	rm -f $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all
