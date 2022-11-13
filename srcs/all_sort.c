/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:36 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/13 19:16:18 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void easy_sort(t_stack **stack, size_t size)
{
	while (!is_sort(*stack))
	{
		if ((*stack)->index == size)
	       		rotate_a(stack);	
		else if ((*stack)->next->index == size)
			reverse_rotate_a(stack);
		else if ((*stack)->index > (*stack)->next->index)
			swap_a(stack);
	}
}

void sort_radix (t_stack **a, size_t size)
{
	t_stack *b;
	size_t n;
	size_t	i;

	b = NULL;
	n = 0;
	while (!is_sort(*a))
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index)>>n&1)
				rotate_a(a);
			else
				push_b(a, &b);
			i++;
		}
		while (b)
			push_a(&b, a);
		++n;
	}
}

int resolve_sort(int *tab, t_duo *duo, size_t position, size_t duo_size)
{
	size_t i;

	if (is_duo_sort(duo, duo_size))
		return (1);
	if (tab[position] != 0)
		return resolve_sort(tab, duo, position + 1, duo_size);
	i = 1;
	while (i <= 3 && position <= 12)
	{
		if (!is_useless(tab, position, i))
		{
			choose_operation(duo, duo_size, i);
			tab[position] = i;
			if (resolve_sort(tab, duo, position + 1, duo_size))
				return (1);
			reverse_operation(tab, duo, position, i);
		}
		++i;
	}							
	tab[position] = 0;
	return (0);
}

void reverse_operation(int *tab, t_duo *duo, size_t position, size_t duo_size)
{
	if (tab[position] == 1)
		duo_swap(duo, duo_size);
	else if (tab[position] == 2)
		duo_reverse_rotate(duo, duo_size);
	else
		duo_rotate(duo, duo_size);
}

void choose_operation(t_duo *duo, size_t duo_size, size_t i)
{
		if (i == 1)
			duo_swap(duo, duo_size);
		else if (i == 2)
			duo_rotate(duo, duo_size);	
		else
			duo_reverse_rotate(duo, duo_size);

}

void hard_sort(t_stack **a, t_duo *duo, size_t size)
{
	size_t	i;
	int tab[12] = {0};
	
	resolve_sort(tab, duo, 0, size);
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
