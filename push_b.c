/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:24 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:05:26 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack_node **from_stack, t_stack_node **to_stack)
{
	t_stack_node	*temp;

	if (*from_stack)
	{
		temp = *from_stack;
		*from_stack = (*from_stack)->next;
		temp->next = *to_stack;
		*to_stack = temp;
	}
}

void	push_a_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_b(stack_b, stack_a);

}

void	push_b_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_b(stack_a, stack_b);

}
