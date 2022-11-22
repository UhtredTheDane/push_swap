/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:39:45 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/22 17:51:08 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_size(char **argv)
{
	size_t	size_number;

	size_number = ft_strlen(argv[i]);
	if (!size_number || (size_number == 1 && argv[i][j] == '-'))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_number(int argc)
{
	if (argc <= 1)
		return (0);
	return (1);
}

int	check_argv(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (!check_size(argv))
			return (0);
		if (argv[i][j] == '-')
			j = 1;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				return (0);
				++j;
			}
		}
		++i;
	}
	return (1);
}

int	check_double(t_duo *duo, int size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (duo[i].value == duo[j].value)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			++j;
		}
		++i;
		j = i + 1;
	}
	return (0);
}

int	big_check(t_duo *duo, int size)
{
	if (check_double(duo, size) || is_duo_sort(duo, size))
	{	
		free(duo);
		return (0);
	}
	return (1);
}
