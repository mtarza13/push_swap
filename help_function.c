/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:11:09 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:35:28 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*big_node_of_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*big_node;

	current = *stack;
	big_node = current;
	while (current)
	{
		if (current->index > big_node->index)
			big_node = current;
		current = current->next;
	}
	return (big_node);
}

int	pos_node(t_stack_node **stack, t_stack_node *target)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = *stack;
	while (current)
	{
		if (current == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
void	add_to_stack(t_stack_node **stack, int value)
{
	t_stack_node *new_node;

	new_node = new_element(value);
	if (!new_node)
		exit_error(stack);
	new_node->next = *stack;
	*stack = new_node;
}