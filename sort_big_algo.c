/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:51 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:38:58 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int size)
{
	int	i;

	if (size < 0)
		return (0);
	i = 0;
	while (i * i <= size)
	{
		i++;
	}
	return (i - 1);
}

static int	static_chunk(int size)
{
	int	a;

	if (size <= 10)
		return (1);
	a = ft_sqrt(size);
	return (a);
}

void	move_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				i;
	int				chunk_size;
	t_stack_node	*head;

	i = 0;
	chunk_size = static_chunk(lst_size(*stack_a));
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
			if (*stack_a && head->index > i + chunk_size)
				reverse_rotate_both(stack_a, stack_b);
			else
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
