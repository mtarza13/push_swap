/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:44 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:08:07 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

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
