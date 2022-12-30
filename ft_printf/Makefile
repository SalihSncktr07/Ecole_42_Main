NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) *.o
	@echo "✅"
clean:
	@/bin/rm -f  *.o *a.out
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "🗑️"

re: fclean all

.PHONY: all bonus clean fclean re