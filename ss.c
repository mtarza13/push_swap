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

void	swap_bonus(t_stack_node **stack_b)
{
	int	temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = temp;
	}
}

void	swap_a_bonus(t_stack_node **stack_a)
{
	swap_bonus(stack_a);
}

void	swap_b_bonus(t_stack_node **stack_b)
{
	swap_bonus(stack_b);
	write(1, "sb\n", 3);
}

void	swap_both_bonus(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_bonus(stack_a);
	swap_bonus(stack_b);
}
