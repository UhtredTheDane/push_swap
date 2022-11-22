/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/21 19:59:21 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void show_stack(t_stack *stack)
{
	t_stack *elem;

	if (stack)
	{
		elem = stack;
		while (elem != NULL)
		{
			printf("%ld  et index: %d | ", elem->value, elem->index);
			elem = elem->next;
		}
		printf("\n");	
	}
}

void	pre_sort_duo(t_duo *duo, int size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && duo[i].value < duo[j].value)
				duo[i].index--;
			++j;
		}
		++i;
	}
}

void	make_sort(t_stack **a, t_duo *duo, size_t size)
{
	if (size < 4)
		easy_sort(a, size);
	else if (size <= 5)
		hard_sort(a, duo, size);
	else
		sort_radix(a, size);
}

int	main(int argc, char **argv)
{
	size_t	size;
	t_stack	*a;
	t_duo	*duo;

	size = argc - 1;
	if (!check_number(argc) || !check_argv(size, argv + 1))
		return (0);
	duo = malloc(sizeof(t_duo) * size);
	if (!duo)
		return (0);
	if (!fill_duo(duo, argv, size))
	{
		free(duo);
		return (0);
	}
	pre_sort_duo(duo, size);
	if (big_check(duo, size))
		return (0);
	a = NULL;
	fill_stack(&a, duo, size);
	make_sort(&a, duo, size);
	free_stack(&a);
	free(duo);
	return (0);
}
