/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:12:14 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/27 23:12:15 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **from_stack, t_stack_node **to_stack)
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

void	push_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
