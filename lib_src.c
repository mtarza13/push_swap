/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:12:34 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:50:57 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
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

static int	ft_sqrt(int size)
{
	int	i;

	if (size < 0)
		return (0);
	i = 0;
	while (i * i <= size)
		i++;
	return (i - 1);
}

static int	static_chunk(int size)
{
	int	a;

	if (size <= 10)
		return (1);
	a = ft_sqrt(size);
	return (a);
}
