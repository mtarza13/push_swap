.SILENT:

NAME        = push_swap
BONUS_NAME  = checker
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g 
HEADER      = push_swap.h

SRCS_COMMON = error_clean.c handle_input.c utils.c stack_index.c swap.c push.c \
             rotate.c reverse_rotate.c chose_sorting.c sort_three.c sort_forth.c \
             sort_five.c sort_big_algo.c help_function.c ft_split.c ft_strlcpy.c \
             lib_src.c

SRCS_PUSH_SWAP = main.c

SRCS_CHECKER   = checker.c get_next_line.c get_next_line_utils.c ss.c pb.c rb.c rrb.c 

OBJS_COMMON    = $(SRCS_COMMON:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER   = $(SRCS_CHECKER:.c=.o)

CYAN    = \033[0;36m
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
RESET   = \033[0m

all: display_banner $(NAME)

$(NAME): $(OBJS_PUSH_SWAP) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COMMON) -o $(NAME)
	@echo "$(GREEN)[Push_swap compiled successfully!]$(RESET)"

BONUS: display_banner_bonus $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_CHECKER) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(OBJS_COMMON) -o $(BONUS_NAME)
	@echo "$(GREEN)[Bonus compiled successfully!]$(RESET)" 
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_COMMON)
	@echo "$(YELLOW)[Object files cleaned.]$(RESET)"

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)[Executables removed.]$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re display_banner display_banner_bonus

display_banner:
	@echo "$(CYAN)Loading Turbo Sort Engine...$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)███╗   ███╗██████╗         ██████╗  ██████╗  ██████╗ ████████╗$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)████╗ ████║██╔══██╗        ██╔══██╗██╔═══██╗██╔═══██╗╚══██╔══╝$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)██╔████╔██║██████╔╝        ██████╔╝██║   ██║██║   ██║   ██║   $(RESET)"
	@sleep 0.5
	@echo "$(CYAN)██║╚██╔╝██║██╔══██╗        ██╔══██╗██║   ██║██║   ██║   ██║   $(RESET)"
	@sleep 0.5	
	@echo "$(CYAN)██║ ╚═╝ ██║██║  ██║███████╗██████╔╝╚██████╔╝╚██████╔╝   ██║   $(RESET)"
	@sleep 0.5
	@echo "$(CYAN)╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝    ╚═╝   $(RESET)"
	@sleep 0.8

display_banner_bonus:
	@echo "$(CYAN)Loading Bonus Engine...$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)███╗   ███╗██████╗         ██████╗  ██████╗  ██████╗ ████████╗$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)████╗ ████║██╔══██╗        ██╔══██╗██╔═══██╗██╔═══██╗╚══██╔══╝$(RESET)"
	@sleep 0.5
	@echo "$(CYAN)██╔████╔██║██████╔╝        ██████╔╝██║   ██║██║   ██║   ██║   $(RESET)"
	@sleep 0.5
	@echo "$(CYAN)██║╚██╔╝██║██╔══██╗        ██╔══██╗██║   ██║██║   ██║   ██║   $(RESET)"
	@sleep 0.5	
	@echo "$(CYAN)██║ ╚═╝ ██║██║  ██║███████╗██████╔╝╚██████╔╝╚██████╔╝   ██║   $(RESET)"
	@sleep 0.5
	@echo "$(CYAN)╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝    ╚═╝   $(RESET)"
	@sleep 0.8
