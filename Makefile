# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikenn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:51:46 by sikenn            #+#    #+#              #
#    Updated: 2019/05/22 21:33:52 by sikenn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########

TARGET = ft_ls 

#############
# DIRECTORY #
#############

BIN_DIR := ./bin
SRC_DIR := ./srcs
INC_DIR := ./includes
OBJ_DIR := ./obj
LIB_DIR := ./libft
TEST_DIR := ./test

########################
# Sources compilations #
########################

SRCS = $(SRC_DIR)/main.c \


########################
# Objects compilations #
########################

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

###############################
# FLAGS, LIBRARY AND INCLUDES #
###############################

CC = gcc -o
CFLAGS = -Wall -Wextra -Werror
INC_LS = -Iincludes/
INC_LIBFT = -Ilibft/includes/
LIB = libft/libft.a

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

$(TARGET): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(TARGET) $(LIB) $(OBJS)
	@mv $(TARGET) $(BIN_DIR)
	@printf "\n$(BLUE)Building executable: $(RESET)$(GREEN)[Ok]$(RESET)\n$(RESET)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@printf "$(GREEN)+$(RESET)"
	@$(CC) $@ $(CFLAGS) $(INC_LS) $(INC_LIBFT) -c $<

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@printf "\n$(BLUE)Creating object directory...\n$(RESET)"
	@printf "$(BLUE)Linking in object directory...\n$(RESET)"

.PHONY: clean
clean:
	@make clean -C $(LIB_DIR)	
	@rm -rf $(OBJ_DIR)
	@printf "$(BLUE)Object directory: $(RED)[DELETED]$(RESET)\n"

.PHONY: fclean
fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm $(BIN_DIR)/$(TARGET)
	@printf "$(BLUE)Executable: $(RED)[DELETED]$(RESET)\n"

.PHONY: re
re: fclean all
	@make re -C $(LIB_DIR)

.PHONY: build
build: all clean
	@make build -C $(LIB_DIR)

########
# TEST #
########


