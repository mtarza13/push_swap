/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:12 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:10:01 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap_bonus.h"

void	check_data(t_stack_node *stack_a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp1;
	int				count;

	tmp = stack_a;
	while (tmp)
	{
		count = 0;
		tmp1 = tmp;
		while (tmp1)
		{
			if (tmp1->value == tmp->value)
			{
				count++;
				if (count >= 2)
					exit_error();
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
// stack = [10 -> 20 -> 30 -> NULL];

void	add_to_stack(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;

	new_node = new_element(value);
	new_node->next = *stack;
	*stack = new_node;
}
// stack = [5 -> 10 -> 20 -> 30 -> NULL];

void	create_new_element(char *str, t_stack_node **stack_a)
{
	long	tmp;
	int		i;

	i = 0;
	if (!str || !str[0])
		exit_error();
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		if (!ft_isdigit(str[i]))
			exit_error();
		i++;
	}
	tmp = ft_atol(str);
	if (tmp > INT_MAX || tmp < INT_MIN)
		exit_error();
	add_to_stack(stack_a, tmp);
}

int	has_space(const char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	handle_input(t_stack_node **stack_a, char **argv, int argc)
{
	int		index;
	char	**split_args;
	int		len_strs;

	index = argc - 1;
	while (index > 0)
	{
		if (has_space(argv[index]))
		{
			split_args = ft_split(argv[index], ' ');
			len_strs = my_strlen(split_args) - 1;
			if (len_strs == -1)
				exit_error();
			while (len_strs >= 0)
			{
				create_new_element(split_args[len_strs], stack_a);
				len_strs--;
			}
		}
		else
			create_new_element(argv[index], stack_a);
		index--;
	}
	check_data(*stack_a);
	create_index(*stack_a);
}
