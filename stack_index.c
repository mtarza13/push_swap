/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:04:25 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/10 04:04:27 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_stack_clone(t_stack_node *stack_a, t_stack_info *list, int temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < lst_size(stack_a) - 1)
	{
		j = 0;
		while (j < lst_size(stack_a) - i - 1)
		{
			if (list->tab[j] > list->tab[j + 1])
			{
				temp = list->tab[j];
				list->tab[j] = list->tab[j + 1];
				list->tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_stack_info	*sorting_stack_clone(t_stack_node *stack_a, t_stack_info *list)
{
	int				i;
	int				temp;
	t_stack_node	*head;

	temp = 0;
	list->tab = malloc(sizeof(int) * lst_size(stack_a));
	i = 0;
	if (!list->tab)
		return (NULL);
	head = stack_a;
	while (head)
	{
		list->tab[i] = head->value;
		head = head->next;
		i++;
	}
	swap_stack_clone(stack_a, list, temp);
	return (list);
}

void	create_index(t_stack_node *stack_a)
{
	t_stack_node	*head;
	int				len_stack;
	int				i;
	t_stack_info	*list;

	list = malloc(sizeof(t_stack_info));
	sorting_stack_clone(stack_a, list);
	head = stack_a;
	len_stack = lst_size(stack_a);
	while (head)
	{
		i = 0;
		while (i < len_stack)
		{
			if (head->value == list->tab[i])
				head->index = i;
			i++;
		}
		head = head->next;
	}
	free(list->tab);
	free(list);
}
//[42(index=2) -> 15(index=0) -> 93(index=3) -> 27(index=1)]
//[42 -> 15 -> 93 -> 27]
//[15, 27, 42, 93]
