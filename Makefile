NAME = pipex

SRCS := srcs/get_valid_bin.c srcs/main.c srcs/commands.c srcs/utils.c
BONUSSRCS := $(SRCS:.c=_bonus.c)

OBJS := $(SRCS:.c=.o)
BONUSOBJS := $(BONUSSRCS:.c=.o)

ifndef BONUS
	OBJECTS := $(OBJS)
else
	OBJECTS := $(BONUSOBJS)
endif

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -lft -Llibft

$(LIBFT) :
	make -C libft all

bonus :
	make BONUS=1 all

clean :
	rm -rf $(OBJS)
	rm -rf $(BONUSOBJS)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re :
	make fclean
	make -C libft re
	make all
