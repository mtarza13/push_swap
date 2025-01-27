/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:05:40 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:05:41 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack_node **stack)
{
	int	temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
	}
}

void	swap_a_b(t_stack_node **stack_a)
{
swap_b(stack_a);

}

void	swap_b_b(t_stack_node **stack_b)
{
	swap_b(stack_b);

}

void	swap_both_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_b(stack_a);
	swap_b(stack_b);

}
