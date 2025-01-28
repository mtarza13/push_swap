/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:29 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/27 23:11:58 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_bonus(t_stack_node **stack)
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

void	reverse_rotate_a_bonus(t_stack_node **stack_a)
{
	reverse_rotate_bonus(stack_a);
}

void	reverse_rotate_b_bonus(t_stack_node **stack_b)
{
	reverse_rotate_bonus(stack_b);
}

void	reverse_rotate_both_bonus(t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	reverse_rotate_bonus(stack_a);
	reverse_rotate_bonus(stack_b);
}
