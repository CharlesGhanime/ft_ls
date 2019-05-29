# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikenn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:51:46 by sikenn            #+#    #+#              #
#    Updated: 2019/05/29 17:38:34 by sikenn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########

TARGET = libft.a

#############
# DIRECTORY #
#############

SRC_DIR := ./srcs
INC_DIR := ./includes
OBJ_DIR := ./obj

###############################
# FLAGS, LIBRARY AND INCLUDES #
###############################

CC = gcc -o
AR = ar cr
CFLAGS = -Wall -Werror -Wextra
INC = -Iincludes/

#######################
# SOURCES COMPILATION #
#######################

SRCS = srcs/char/ft_isalpha.c srcs/char/ft_isalnum.c srcs/char/ft_isdigit.c \
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
	srcs/str/ft_strncmp.c srcs/str/ft_strsplit.c  \
	srcs/str/ft_strtrim.c srcs/str/ft_strjoin.c srcs/str/ft_strsub.c \
	srcs/str/ft_strsubf.c srcs/str/ft_strnequ.c srcs/str/ft_strequ.c \
	srcs/str/ft_strmapi.c srcs/str/ft_striteri.c srcs/str/ft_striter.c \
	srcs/str/ft_strclr.c srcs/str/ft_strdel.c srcs/str/ft_strnew.c \
	srcs/str/ft_strjoinf.c srcs/str/ft_strindex.c srcs/str/ft_strinsert.c \
	srcs/ft_getopt/ft_getopt.c srcs/bitwise/ft_print_bits.c \

########################
# Objects compilations #
########################

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

##########
# COLORS #
##########

YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

#########
# RULES #
#########

.PHONY: all
all: $(TARGET)

#$(MK_OBJ): | $(OBJ_DIR)

$(TARGET): $(OBJ_DIR) $(OBJS) 
	@$(AR) $(TARGET) $(OBJS) 
	@printf "\n$(BLUE)Building static library: $(GREEN)[OK]$(RESET)\n$(RESET)"
	@printf "$(YELLOW)_____________________________$(RESET)\n$(RESET)"

obj/%.o: $(SRC_DIR)/*/%.c
	@printf "$(GREEN)+$(RESET)"
	@$(CC) $@ $(CFLAGS) $(INC) -c $< 

	
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@printf "\n$(BLUE)Creating object directory...\n$(RESET)"
	@printf "$(BLUE)Linking in object directory...\n$(RESET)"

.PHONY: clean 
clean:
	@rm -rf $(OBJ_DIR) 
	@printf "$(BLUE)Libft Objects:  $(RED)[DELETED]$(RESET)\n$(RESET)"

.PHONY: clean 
fclean: clean
	@rm -rf $(TARGET)
	@printf "$(BLUE)$(TARGET): $(RED)[DELETED]$(RESET)\n$(RESET)"

.PHONY: re
re: fclean all 

.PHONY: build
build: all clean
