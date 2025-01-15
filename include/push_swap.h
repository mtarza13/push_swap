/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:03:42 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/12 01:27:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* -------------------------- Structures -------------------------- */

// Node structure for the stack
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					pos;
	struct s_stack_node	*next;
}						t_stack_node;

// Structure for stack information
typedef struct s_stack_info
{
	int					*tab;
	int					len_stack;
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
}						t_stack_info;

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
void					exit_error(t_stack_node **stack_a);

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
// -------------------------- Additional Helper Functions -----------------
long					ft_atol(const char *str);
int						my_strlen(char **argv);
int						find_min_position(t_stack_node *stack_a);
void					move_to_top(t_stack_node **stack, int position);
int						pos_node(t_stack_node **stack, t_stack_node *target);
#endif
