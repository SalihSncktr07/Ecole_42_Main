NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Lft_printf -Llibft -Lminilibx -lft -lprintf -lmlx -framework OpenGL -framework AppKit
SOURCES	=	$(shell find src/*.c)
OBJ = $(SOURCES:.c=.o)

all		:	$(NAME)

$(NAME)	:	mdir $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

mdir	:
		@make -C ft_printf
		@make -C libft
		@make -C minilibx

clean	:
		@make -C ft_printf	clean
		@make -C libft 		clean
		@make -C minilibx	clean
		@rm -f $(OBJ)

fclean :
		@make -C ft_printf	clean
		@make -C libft 		clean
		@make -C minilibx	clean
		@rm	-f $(NAME) $(OBJ)

re		:	fclean all

.PHONY	:	all $(NAME) mdir clean fclean re
