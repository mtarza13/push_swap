/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:51 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:04:52 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				i;
	int				chunk_size;
	t_stack_node	*head;

	i = 0;
	chunk_size = lst_size(*stack_a) / 12;
	while (*stack_a)
	{
		head = *stack_a;
		if (head->index < i)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else if (head->index <= i + chunk_size)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
		}
		else
		{
			rotate_a(stack_a);
		}
	}
}

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *target)
{
	int	position;
	int	size;

	position = pos_node(stack_b, target);
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
	push_a(stack_a, stack_b);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*big_node;
	int				position;
	int				size;

	while (*stack_b)
	{
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
		push_a(stack_a, stack_b);
	}
}

void	sort_big_algo(t_stack_node **stack_a, t_stack_node **stack_b)
{
	move_to_b(stack_a, stack_b);
	move_b_to_a(stack_a, stack_b);
}
