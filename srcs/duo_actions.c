/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duo_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:20:10 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/22 17:31:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duo_sort(t_duo *duo, size_t duo_size)
{
	size_t	i;

	i = 0;
	while (i < duo_size)
	{
		if (duo[i].index != i)
			return (0);
		++i;
	}
	return (1);
}

void	duo_swap(t_duo *duo, size_t duo_size)
{
	t_duo	elem;

	if (duo_size >= 2)
	{
		elem = duo[0];
		duo[0] = duo[1];
		duo[1] = elem;
	}
}

void	duo_rotate(t_duo *duo, size_t duo_size)
{
	t_duo	elem;
	size_t	i;

	i = 0;
	elem = duo[0];
	while (i < duo_size - 1)
	{
		duo[i] = duo[i + 1];
		++i;
	}
	duo[i] = elem;
}

void	duo_reverse_rotate(t_duo *duo, size_t duo_size)
{
	t_duo	elem;
	size_t	i;

	i = duo_size - 1;
	elem = duo[duo_size - 1];
	while (i > 0)
	{
		duo[i] = duo[i - 1];
		--i;
	}
	duo[i] = elem;
}

int	fill_duo(t_duo *duo, char **argv, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		duo[i].value = ft_atol(argv[i + 1]);
		if (duo[i].value < INT_MIN || duo[i].value > INT_MAX)
		{
			write_stderr();
			return (0);
		}
		duo[i].index = size - 1;
		++i;
	}
	return (1);
}
