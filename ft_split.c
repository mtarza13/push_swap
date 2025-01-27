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

static size_t	count_words(const char *s)
{
	size_t	count = 0;
	size_t	i = 0;

	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	return (count);
}

static size_t	ft_word_len(const char *s)
{
	size_t	len = 0;

	while (s[len] && s[len] != ' ' && s[len] != '\t')
		len++;
	return (len);
}

static void	*free_all(char **arr, size_t size)
{
	size_t	i = 0;

	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s)
{
	size_t	words;
	char	**result;
	size_t	i = 0;
	size_t	word_len;

	if (!s)
		return (NULL);
	words = count_words(s);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		word_len = ft_word_len(s);
		result[i] = malloc((word_len + 1) * sizeof(char));
		if (!result[i])
			return (free_all(result, i));
		ft_strlcpy(result[i], s, word_len + 1);
		s += word_len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
