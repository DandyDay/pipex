NAME = pipex

SRCS = srcs/get_valid_bin.c srcs/main.c srcs/commands.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) -o $@ $^ -lft -Llibft

$(LIBFT) : 
	make -C libft all

clean :
	rm -rf $(OBJS)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re :
	make fclean
	make -C libft re
	make all
