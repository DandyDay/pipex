NAME = pipex

SRCS = srcs/get_valid_bin.c srcs/main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -o $@ $^ -lft -Llibft

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all