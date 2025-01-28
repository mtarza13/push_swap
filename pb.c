/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:12:27 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/27 23:12:28 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bonus(t_stack_node **from_stack, t_stack_node **to_stack)
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

void	push_a_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_bonus(stack_b, stack_a);
}

void	push_b_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_bonus(stack_a, stack_b);
}
