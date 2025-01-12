/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_forth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:11 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:05:15 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	sort_forth(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min_pos;

	min_pos = find_min_position(*stack_a);
	move_to_top(stack_a, min_pos);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

int	find_min_position(t_stack_node *stack_a)
{
	int				min;
	int				pos;
	int				min_pos;
	t_stack_node	*current;

	min = stack_a->value;
	pos = 0;
	min_pos = 0;
	current = stack_a;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	move_to_top(t_stack_node **stack, int position)
{
	int	size;

	size = lst_size(*stack);
	if (position <= size / 2)
	{
		while (position-- > 0)
		{
			rotate_a(stack);
		}
	}
	else
	{
		position = size - position;
		while (position-- > 0)
		{
			reverse_rotate_a(stack);
		}
	}
}
