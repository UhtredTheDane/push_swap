/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:18:27 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:16 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_operate(t_duo *duo, size_t duo_size, size_t i)
{
	if (i == 1)
		duo_swap(duo, duo_size);
	else if (i == 2)
		duo_reverse_rotate(duo, duo_size);
	else
		duo_rotate(duo, duo_size);
}

void	choose_operate(t_duo *duo, size_t duo_size, size_t i)
{
	if (i == 1)
		duo_swap(duo, duo_size);
	else if (i == 2)
		duo_rotate(duo, duo_size);
	else
		duo_reverse_rotate(duo, duo_size);
}

void	init_duo(int *tab, size_t size_tab)
{
	size_t	i;

	i = 0;
	while (i < size_tab)
	{
		tab[i] = 0;
		++i;
	}
}

void	hard_sort(t_stack **a, t_duo *duo, size_t duo_size)
{
	size_t	i;
	int		tab[12];

	init_duo(tab, 12);
	if (resolve_sort(tab, duo, 0, duo_size))
	{
		i = 0;
		while (i < 12 && tab[i])
		{
			if (tab[i] == 1)
				swap_a(a);
			else if (tab[i] == 2)
				rotate_a(a);
			else
				reverse_rotate_a(a);
			++i;
		}
	}
}

int	resolve_sort(int *tab, t_duo *duo, size_t position, size_t duo_size)
{
	size_t	i;

	if (is_duo_sort(duo, duo_size))
		return (1);
	i = 1;
	while (i <= 3 && position < 12)
	{
		if (!is_useless(tab, position, i))
		{
			choose_operate(duo, duo_size, i);
			tab[position] = i;
			if (resolve_sort(tab, duo, position + 1, duo_size))
				return (1);
			reverse_operate(duo, duo_size, i);
			tab[position] = 0;
		}
		++i;
	}
	return (0);
}
