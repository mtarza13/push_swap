/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:51 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 12:01:29 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_head(t_stack_node **stack_a, t_stack_node **stack_b, int *i,
		int chunk_size)
{
	t_stack_node	*head;

	head = *stack_a;
	if (head->index < *i)
	{
		push_b(stack_a, stack_b);
		(*i)++;
	}
	else if (head->index <= *i + chunk_size)
	{
		push_b(stack_a, stack_b);
		if (*stack_a && (*stack_a)->index > *i + chunk_size)
			rotate_both(stack_a, stack_b);
		else
			rotate_b(stack_b);
		(*i)++;
	}
	else
		rotate_a(stack_a);
}

void	move_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = static_chunk(lst_size(*stack_a));
	while (*stack_a)
		process_head(stack_a, stack_b, &i, chunk_size);
}

static void	bring_big_to_top(t_stack_node **stack_b)
{
	t_stack_node	*big_node;
	int				position;
	int				size;

	big_node = big_node_of_stack(stack_b);
	position = pos_node(stack_b, big_node);
	size = lst_size(*stack_b);
	if (position <= size / 2)
	{
		while (position-- > 0)
			rotate_b(stack_b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			reverse_rotate_b(stack_b);
	}
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (*stack_b)
	{
		bring_big_to_top(stack_b);
		push_a(stack_a, stack_b);
	}
}

void	sort_big_algo(t_stack_node **stack_a, t_stack_node **stack_b)
{
	move_to_b(stack_a, stack_b);
	move_b_to_a(stack_a, stack_b);
}
