# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourname <youremail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 00:00:00 by yourname          #+#    #+#              #
#    Updated: 2025/01/27 00:00:00 by yourname         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** VARIABLES ************************************ #

# Executable names
NAME        = push_swap
BONUS_NAME  = checker

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -O0

# Header file
HEADER      = push_swap.h

# Common source files (shared between push_swap and checker)
SRCS_COMMON = error_clean.c handle_input.c utils.c stack_index.c swap.c push.c  \
             rotate.c   reverse_rotate.c chose_sorting.c sort_three.c sort_forth.c \
             sort_five.c sort_big_algo.c help_function.c ft_split.c ft_strlcpy.c \
              lib_src.c  

# Source files for push_swap (main executable)
SRCS_PUSH_SWAP = main.c

# Source files for checker (bonus executable)
SRCS_CHECKER   = checker.c get_next_line.c get_next_line_utils.c swap_b.c push_b.c rotate_b.c reverse_rotate_b.c 

# Object files
OBJS_COMMON    = $(SRCS_COMMON:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER   = $(SRCS_CHECKER:.c=.o)

# **************************** RULES *************************************** #

# Default target to build push_swap
all: $(NAME)

# Rule to build push_swap
$(NAME): $(OBJS_PUSH_SWAP) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COMMON) -o $(NAME)
	@echo "\033[0;92m[Push_swap compiled successfully!]\033[0m"

# Target to build checker (bonus)
bonus: $(BONUS_NAME)

# Rule to build checker
$(BONUS_NAME): $(OBJS_CHECKER) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(OBJS_COMMON) -o $(BONUS_NAME)
	@echo "\033[0;92m[Checker (bonus) compiled successfully!]\033[0m"

# Pattern rule to compile .c files to .o files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_COMMON)
	@echo "\033[0;93m[Object files cleaned.]\033[0m"

# Clean object files and executables
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@echo "\033[0;93m[Executables removed.]\033[0m"

# Rebuild the project from scratch
re: fclean all

# Phony targets to prevent conflicts with files of the same name
.PHONY: all bonus clean fclean re
