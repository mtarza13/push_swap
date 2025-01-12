/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:39 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:04:41 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	choose_sorting(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;

	stack_size = lst_size(*stack_a);
	if (stack_size == 2)
		swap_a(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size == 4)
		sort_forth(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big_algo(stack_a, stack_b);
}
