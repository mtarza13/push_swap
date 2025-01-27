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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

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

int	create_new_element(char *str, t_stack_node **stack_a)
{
	long	value;
	int		i;

	if (!str || !str[0])
		return (1);
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	add_to_stack(stack_a, (int)value);
	return (0);
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

static void	parsing_line(t_stack_node **stack_a, char *arg)
{
	char	**split_arg;
	int		count;
	int		i;

	if (!has_space(arg))
	{
		if (create_new_element(arg, stack_a) != 0)
			exit_error(stack_a);
		return ;
	}
	split_arg = ft_split(arg);
	if (!split_arg)
		exit_error(stack_a);
	count = 0;
	while (split_arg[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		if (create_new_element(split_arg[i], stack_a) != 0)
		{
			free_split(split_arg);
			exit_error(stack_a);
		}
		i--;
	}
	free_split(split_arg);
}

void	handle_input(t_stack_node **stack_a, char *argv[], int argc)
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		parsing_line(stack_a, argv[index]);
		index--;
	}
	check_data(*stack_a);
	create_index(*stack_a);
}