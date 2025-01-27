/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:57 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:04:59 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	min_pos;
	int	count;

	count = 2;
	while (count-- > 0)
	{
		min_pos = find_min_position(*stack_a);
		move_to_top(stack_a, min_pos);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
