/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:12:54 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:37:51 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
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
	size_t	len;

	len = 0;
	while (s[len] && s[len] != ' ' && s[len] != '\t')
		len++;
	return (len);
}

static char	*alloc_word(const char *s)
{
	size_t	word_len;
	char	*word;

	word_len = ft_word_len(s);
	word = malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, word_len + 1);
	return (word);
}

static char	**fill_result(const char *s, size_t words)
{
	char	**result;
	size_t	i;

	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		result[i] = alloc_word(s);
		if (!result[i])
			return (free_all(result, i));
		s += ft_word_len(s);
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s)
{
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s);
	return (fill_result(s, words));
}
