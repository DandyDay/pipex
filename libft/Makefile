# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:43:56 by jinhchoi          #+#    #+#              #
#    Updated: 2023/01/25 13:20:19 by jinhchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rc

SRCFILES := ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c \
		ft_striteri.c ft_itoa.c ft_strmapi.c ft_substr.c ft_strtrim.c \
		ft_strjoin.c ft_strdup.c ft_strrchr.c ft_memmove.c ft_memcpy.c \
		ft_strncmp.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_tolower.c \
		ft_isalnum.c ft_calloc.c ft_memset.c ft_memchr.c ft_isalpha.c \
		ft_toupper.c ft_isprint.c ft_isascii.c ft_bzero.c ft_strchr.c \
		ft_strlen.c ft_isdigit.c ft_strnstr.c ft_atoi.c ft_split.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c get_next_line_utils.c \
		ft_printf.c ft_printf_get_chr_string.c ft_printf_get_dec_string.c \
		ft_printf_get_cnv.c ft_printf_get_hex_string.c ft_printf_print_cnv.c \
		ft_printf_utils.c ft_printf_get_string.c

SRCS := $(addprefix srcs/, $(SRCFILES))
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
