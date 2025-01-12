.SILENT:

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a



SRCS = src/main.c src/utilis_main/error_clean.c src/utilis_main/handle_input.c src/utilis_main/utils.c src/utilis_main/stack_index.c \
       src/movement/swap.c src/movement/push.c src/movement/rotate.c \
       src/movement/reverse_rotate.c src/sorting/chose_sorting.c \
       src/sorting/sort_three.c src/sorting/sort_forth.c src/sorting/sort_five.c \
       src/sorting/sort_big_algo.c src/sorting/help_function.c

SRCS_BONUS = bonus/main.c bonus/utilis_main/error_clean.c bonus/utilis_main/handle_input.c \
             bonus/utilis_main/utils.c bonus/utilis_main/stack_index.c \
             bonus/movement/swap.c bonus/movement/push.c bonus/movement/rotate.c \
             bonus/movement/reverse_rotate.c bonus/sorting/chose_sorting.c \
             bonus/sorting/sort_three.c bonus/sorting/sort_forth.c bonus/sorting/sort_five.c \
             bonus/sorting/sort_big_algo.c bonus/sorting/help_function.c \
             bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \
             bonus/utilis_main/ft_strcmp.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
	@echo "\n██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗"
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "\033[32m[Program is ready for use]\033[0m"


$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 
	@echo "\033[0;92m[Push_swap compiled successfully!]\033[0m"

bonus: $(BONUS_NAME)
	@echo "\n ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ "
	@echo "██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗"
	@echo "██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝"
	@echo "██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗"
	@echo "╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║"
	@echo " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)
	@echo "\033[0;92m[Checker (bonus) compiled successfully!]\033[0m"

$(LIBFT):
	@make -C libft > /dev/null

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make -C libft clean > /dev/null
	@echo "\033[0;93m[Object files cleaned.]\033[0m"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C libft fclean > /dev/null
	@echo "\033[0;93m[Executables removed.]\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
