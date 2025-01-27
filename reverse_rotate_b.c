/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:29 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:05:30 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_stack_node **stack)
{
	t_stack_node	*prev;
	t_stack_node	*tail;

	prev = NULL;
	tail = *stack;
	if (*stack && (*stack)->next)
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}

void	reverse_rotate_a_b(t_stack_node **stack_a)
{
	reverse_rotate_b(stack_a);
	
}

void	reverse_rotate_b_b(t_stack_node **stack_b)
{
	reverse_rotate_b(stack_b);
	
}

void	reverse_rotate_both_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate_b(stack_a);
	reverse_rotate_b(stack_b);
	
}
