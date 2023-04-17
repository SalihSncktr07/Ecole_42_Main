NAME = libft.a
LIBFT = libft

all: $(NAME)
		gcc server.c $(NAME) -o server
		gcc client.c $(NAME) -o client
$(NAME): $(LIBFT)
		make -C $(LIBFT)
		cp libft/libft.a .
clean:
		make clean -C $(LIBFT)
fclean: clean
		make fclean -C $(LIBFT)
		rm -rf $(NAME)
		rm -rf server client

.PHONY: clean