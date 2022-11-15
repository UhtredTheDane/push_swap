/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/15 16:32:50 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	make_sort(t_stack **a, t_duo *int_tab, size_t size)
{
	if (size < 4)
		easy_sort(a, size - 1);
	else if (size <= 5)
		hard_sort(a, int_tab, size);
	else
		sort_radix(a, size);
}

int	main(int argc, char **argv)
{
	size_t	size;
	t_stack	*a;
	t_duo	*int_tab;

	size = argc - 1;
	if (!check_number(argc) || !check_argv(size, argv + 1))
		return (0);
	int_tab = malloc(sizeof(t_duo) * size);
	if (!int_tab)
	{
		write_stderr();
		return (0);
	}
	fill_duo(int_tab, argv, size);
	if (check_double(size, int_tab) || is_duo_sort(int_tab, size))
	{
		free(int_tab);
		return (0);
	}
	pre_sort_duo(int_tab, size);
	a = NULL;
	fill_stack(&a, int_tab, size);
	make_sort(&a, int_tab, size);
	free_stack(&a);
	free(int_tab);
	return (0);
}
