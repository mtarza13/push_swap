/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:29:58 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:35:21 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	handle_splitted_args(t_stack_node **stack_a, char **split_arg)
{
	int	count;
	int	i;

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
	return (0);
}

static void	parse_and_add_to_stack(t_stack_node **stack_a, char *arg)
{
	char	**split_arg;

	if (!has_space(arg))
	{
		if (create_new_element(arg, stack_a) != 0)
			exit_error(stack_a);
		return ;
	}
	split_arg = ft_split(arg);
	if (!split_arg)
		exit_error(stack_a);
	if (handle_splitted_args(stack_a, split_arg) != 0)
		exit_error(stack_a);
	free_split(split_arg);
}

void	handle_input(t_stack_node **stack_a, char *argv[], int argc)
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		parse_and_add_to_stack(stack_a, argv[index]);
		index--;
	}
	check_data(*stack_a);
	create_index(*stack_a);
}
