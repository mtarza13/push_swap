/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:03 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:04:07 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void exit_error(t_stack_node **stack, char **split_args)
{
    if (split_args)
        free_split(split_args);  // Free split_args if allocated
    if (stack && *stack)
        free_stack(stack);       // Free the stack
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}


void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
