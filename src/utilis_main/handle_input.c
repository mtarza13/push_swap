/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:12 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/15 15:50:00 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_data(t_stack_node *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*checker;

	current = stack_a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (checker->value == current->value)
				exit_error(&stack_a); 
			checker = checker->next;
		}
		current = current->next;
	}
}

void	add_to_stack(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;

	new_node = new_element(value);
	if (!new_node)
		exit_error(stack); 
	new_node->next = *stack;
	*stack = new_node;
}

void	create_new_element(char *str, t_stack_node **stack_a)
{
	long	value;
	int		i;

	if (!str || !str[0])
		exit_error(stack_a);
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error(stack_a);
		i++;
	}
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		exit_error(stack_a);
	add_to_stack(stack_a, (int)value);
}

int	has_space(const char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			return (1);
		str++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	handle_input(t_stack_node **stack_a, char **argv, int argc)
{
	int		index;
	char	**split_args;

	index = argc-1;
	while (index > 0)
	{
		if (has_space(argv[index]))
		{
			split_args = ft_split(argv[index], ' ');
			if (!split_args)
				exit_error(stack_a);
			while (*split_args)
				create_new_element(*split_args++, stack_a);
			free_split(split_args);
		}
		else
			create_new_element(argv[index], stack_a);
		index--;
	}
	check_data(*stack_a); 
	create_index(*stack_a); 
}
