# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by jinhchoi          #+#    #+#              #
#    Updated: 2022/12/23 14:38:43 by jinhchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rc

SRCFILES := ft_printf.c get_chr_string.c get_dec_string.c get_cnv.c\
			get_hex_string.c print_cnv.c utils.c get_string.c

SRCS := ${addprefix srcs/, ${SRCFILES}}
OBJS := $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	ar -rc $@ $(OBJS)

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./includes/

clean :
	$(RM) $(OBJS)
	make -C libft clean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all clean fclean re
