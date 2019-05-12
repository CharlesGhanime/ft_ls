# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikenn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:51:46 by sikenn            #+#    #+#              #
#    Updated: 2019/05/12 14:42:10 by sikenn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

AR = ar cr

CFLAGS = -Wall -Werror -Wextra

SRC = srcs/char/ft_isalpha.c srcs/char/ft_isalnum.c srcs/char/ft_isdigit.c \
	srcs/char/ft_isprint.c srcs/char/ft_toupper.c srcs/char/ft_tolower.c \
	srcs/conv/ft_atoi.c srcs/conv/ft_itoa.c srcs/gnl/get_next_line.c \
	srcs/lst/ft_lstnew.c srcs/lst/ft_lstnewf.c srcs/lst/ft_lstdelone.c \
	srcs/lst/ft_lstdel.c srcs/lst/ft_lstadd.c srcs/lst/ft_lstiter.c \
	srcs/lst/ft_lstmap.c srcs/lst/ft_lstlen.c srcs/mem/ft_memset.c \
	srcs/mem/ft_bzero.c srcs/mem/ft_memcpy.c srcs/mem/ft_memccpy.c \
	srcs/mem/ft_memmove.c srcs/mem/ft_memchr.c srcs/mem/ft_memcmp.c \
	srcs/mem/ft_memdel.c srcs/mem/ft_memalloc.c srcs/put/ft_putnbr_fd.c \
	srcs/put/ft_putendl_fd.c srcs/put/ft_putstr_fd.c \
	srcs/put/ft_putchar_fd.c srcs/put/ft_putnbr.c srcs/put/ft_putendl.c \
	srcs/put/ft_putstr.c srcs/put/ft_putchar.c srcs/str/ft_strlen.c \
	srcs/str/ft_strdup.c srcs/str/ft_strndup.c srcs/str/ft_strcpy.c \
	srcs/str/ft_strncpy.c srcs/str/ft_strcat.c srcs/str/ft_strncat.c \
	srcs/str/ft_strlcat.c srcs/str/ft_strchr.c srcs/str/ft_strrchr.c \
	srcs/str/ft_strstr.c srcs/str/ft_strnstr.c srcs/str/ft_strcmp.c \
	srcs/str/ft_strncmp.c srcs/str/ft_strsplit.c srcs/str/ft_strtrim.c \
	srcs/str/ft_strtrim.c srcs/str/ft_strjoin.c srcs/str/ft_strsub.c \
	srcs/str/ft_strsubf.c srcs/str/ft_strnequ.c srcs/str/ft_strequ.c \
	srcs/str/ft_strmapi.c srcs/str/ft_striteri.c srcs/str/ft_striter.c \
	srcs/str/ft_strclr.c srcs/str/ft_strdel.c srcs/str/ft_strnew.c \
	srcs/str/ft_strjoinf.c srcs/str/ft_strindex.c srcs/str/ft_strinsert.c \
	srcs/ft_getopt/ft_getopt.c \

INC = -Iincludes/
HEAD = includes/*.h
OBJ = $(SRC:.c=.o)
VAL = valgrind
G3 = -fsanitize=address -g3 

YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n$(PURPLE)LIBFT SOURCES  $(GREEN)[OK]$(RESET)\n$(RESET)"
	@$(AR) $(NAME) $(OBJ) 
	@printf "$(PURPLE)LIBFT COMPILED $(GREEN)[OK]$(RESET)\n$(RESET)"
	@printf "$(YELLOW)_____________________________$(RESET)\n$(RESET)"

%.o: %.c
	@printf "$(GREEN)+$(RESET)"
	@$(CC) -o $@ -c $(INC) $< $(CFLAGS) 

getotp:
	gcc test/getopt_test.c libft.a
	./a.out

clean:
	@printf "$(PURPLE)Objects:  $(RED)[DELETED]$(RESET)\n$(RESET)"
	@rm -rf $(wildcard srcs/*/*.o)

fclean: clean
	@printf "$(PURPLE)Libft:    $(RED)[DELETED]$(RESET)\n$(RESET)"
	@rm -rf $(NAME) $(so)

re: fclean all 
