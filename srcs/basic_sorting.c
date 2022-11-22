/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:36 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/15 16:33:47 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	easy_sort(t_stack **stack, size_t size)
{
	while (!is_sort(*stack))
	{
		if ((*stack)->index == size - 1)
			rotate_a(stack);
		else if ((*stack)->next->index == size - 1)
			reverse_rotate_a(stack);
		else if ((*stack)->index > (*stack)->next->index)
			swap_a(stack);
	}
}

void	sort_radix(t_stack **a, size_t size)
{
	t_stack	*b;
	size_t	n;
	size_t	i;

	b = NULL;
	n = 0;
	while (!is_sort(*a))
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index) >> n & 1)
				rotate_a(a);
			else
				push_b(a, &b);
			i++;
		}
		while (b)
			push_a(&b, a);
		++n;
	}
	free_stack(&b);
}
