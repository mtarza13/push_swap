/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:45:15 by mtarza            #+#    #+#             */
/*   Updated: 2024/11/23 08:49:03 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_v_list	*ft_lstnew_get(char *data)
{
	t_v_list	*new_node;

	new_node = (t_v_list *)malloc(sizeof(t_v_list));
	if (!new_node)
		return (NULL);
	new_node->data = ft_strdup(data);
	if (!new_node->data)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_lstclean_up(struct s_v_list **list, t_v_list *new_node,
		char *new_data)
{
	t_v_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->data);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new_node->data[0])
		*list = new_node;
	else
	{
		free(new_data);
		free(new_node);
	}
}

void	ft_lstadd_back_get(struct s_v_list **lst, t_v_list *new)
{
	t_v_list	*current;

	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

char	*found_newline(struct s_v_list *list)
{
	t_v_list	*current;
	char		*ptr;

	current = list;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	if (!current->data)
		return (NULL);
	ptr = current->data;
	while (*ptr != '\0')
	{
		if (*ptr == '\n')
			return (ptr);
		ptr++;
	}
	return (NULL);
}
