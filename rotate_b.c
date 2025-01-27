/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:34 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:05:36 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*tail;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		tail = *stack;
		while (tail->next)
			tail = tail->next;
		tail->next = temp;
	}
}

void	rotate_a_b(t_stack_node **stack_a)
{
	rotate_b(stack_a);

}

void	rotate_b_b(t_stack_node **stack_b)
{
	rotate_b(stack_b);

}

void	rotate_both_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_b(stack_a);
	rotate_b(stack_b);

}
