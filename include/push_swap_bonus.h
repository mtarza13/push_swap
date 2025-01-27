/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:35:23 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/11 13:35:41 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/* -------------------------- Data Structures -------------------------- */

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					pos;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack_info
{
	int					*tab;
	int					len_stack;
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
}						t_stack_info;

typedef struct s_v_list
{
	char				*data;
	struct s_v_list		*next;
}						t_v_list;

/* -------------------------- Movement Functions -------------------------- */

void					swap_a(t_stack_node **stack_a);
void					swap_b(t_stack_node **stack_b);
void					swap_both(t_stack_node **stack_a,
							t_stack_node **stack_b);

void					push_a(t_stack_node **stack_a, t_stack_node **stack_b);
void					push_b(t_stack_node **stack_a, t_stack_node **stack_b);

void					rotate_a(t_stack_node **stack_a);
void					rotate_b(t_stack_node **stack_b);
void					rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b);

void					reverse_rotate_a(t_stack_node **stack_a);
void					reverse_rotate_b(t_stack_node **stack_b);
void					reverse_rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b);

/* -------------------------- Utility Functions -------------------------- */

int						lst_size(t_stack_node *head);
void					free_stack(t_stack_node **stack);
t_stack_node			*new_element(int value);
void					print_stack(t_stack_node *stack, const char *name);
void	exit_error(t_stack_node **stack_a, t_stack_node **stack_b); 
/* -------------------------- Input Handling -------------------------- */

void					handle_input(t_stack_node **stack_a, char **argv,
							int argc);
int						is_sorted(t_stack_node *stack_a);
void					create_index(t_stack_node *stack_a);

/* -------------------------- Sorting Functions -------------------------- */

void					sort_three(t_stack_node **stack_a);
void					sort_forth(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_five(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_big_algo(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					choose_sorting(t_stack_node **stack_a,
							t_stack_node **stack_b);
t_stack_node			*big_node_of_stack(t_stack_node **stack);

void					push_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b, t_stack_node *target);

/* -------------------------- Helper Functions -------------------------- */

long					ft_atol(const char *str);
int						my_strlen(char **argv);
int						find_min_position(t_stack_node *stack_a);
void					move_to_top(t_stack_node **stack, int position);
int						pos_node(t_stack_node **stack, t_stack_node *target);

/* -------------------- String and GNL Functions -------------------------- */

void					ft_putstr_fd(char *s, int fd);
int						ft_strcmp(char *a, char *b);

void					ft_lstclean_up(struct s_v_list **list,
							struct s_v_list *new_node, char *new_data);
void					ft_lstadd_back_get(struct s_v_list **lst,
							struct s_v_list *new);
char					*ft_strdup(const char *s);
char					*found_newline(struct s_v_list *list);
void					add_line_to_list(struct s_v_list **list, int fd);
char					*construct_line(struct s_v_list *list);
int						get_line_length(struct s_v_list *list);
void					next_line(struct s_v_list **list);
char					*get_next_line(int fd);
struct s_v_list			*ft_lstnew_get(char *content);

void					add_to_stack_a(t_stack_node **stack,
							t_stack_node *new_node);
#endif
