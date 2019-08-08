# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikenn <marvin42.fr>                      +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 10:51:46 by sikenn            #+#    #+#              #
#    Updated: 2019/08/03 15:49:05 by sikenn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########

TARGET = ft_ls 

#############
# DIRECTORY #
#############

SRC_DIR := ./srcs
INC_DIR := ./includes
OBJ_DIR := ./obj
LIB_DIR := ./libft
TEST_DIR := ./test

########################
# Sources compilations #
########################

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/ft_list_dir.c $(SRC_DIR)/ft_inspect_file.c \
	   $(SRC_DIR)/parsing.c $(SRC_DIR)/usage.c $(SRC_DIR)/ft_istype.c \
	   $(SRC_DIR)/ft_getpath.c $(SRC_DIR)/dispatcher.c $(SRC_DIR)/output.c \
	   $(SRC_DIR)/output_a.c $(SRC_DIR)/recursive.c $(SRC_DIR)/ft_sorting.c \
	   $(SRC_DIR)/ft_sorting_c.c $(SRC_DIR)/ft_sorting_f.c \
	   $(SRC_DIR)/ft_sorting_t.c $(SRC_DIR)/ft_sorting_u.c \
	   $(SRC_DIR)/ft_sorting_uu.c $(SRC_DIR)/ft_num_list.c $(SRC_DIR)/test_params_dir.c \
	   $(SRC_DIR)/ft_affichage.c $(SRC_DIR)/ft_printing_functions_reforged.c $(SRC_DIR)/free_mem.c

#######################
# Objects compilations #
########################

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

########
# Head #
########

HEAD = $(INC_DIR)/ft_ls.h 

###############################
# FLAGS, LIBRARY AND INCLUDES #
###############################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
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

$(TARGET): $(LIB) $(OBJ_DIR) $(OBJS)
	$(CC) -o $(TARGET) $(LIB) $(OBJS)
	printf "\n$(BLUE)Building executable: $(RESET)$(GREEN)[Ok]$(RESET)\n$(RESET)"

$(LIB): FORCE
	$(MAKE) -C $(LIB_DIR)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEAD) Makefile
	printf "$(GREEN)+$(RESET)"
	$(CC) -o $@ $(CFLAGS) $(INC_LS) $(INC_LIBFT) -c $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	printf "\n$(BLUE)Creating object directory...\n$(RESET)"
	printf "$(BLUE)Linking in object directory...\n$(RESET)"

.PHONY: clean
clean:
	make clean -C $(LIB_DIR)	
	$(RM) -R $(OBJ_DIR)
	printf "$(BLUE)Object directory: $(RED)[DELETED]$(RESET)\n"

.PHONY: fclean
fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(TARGET)
	printf "$(BLUE)Executable: $(RED)[DELETED]$(RESET)\n"

.PHONY: re
re: fclean all
	make re -C $(LIB_DIR)

.PHONY: build
build: all clean
	make build -C $(LIB_DIR)

FORCE:

#.SILENT:

########
# TEST #
########


