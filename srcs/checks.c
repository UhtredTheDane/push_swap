/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:39:45 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/13 04:47:26 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_size(char *number_str)
{
	int	number_size;

	number_size = ft_strlen(number_str);
	if (!number_size || (number_size == 1 && number_str[0] == '-'))
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
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (!check_size(argv[i]))
			return (0);
		if (argv[i][j] == '-')
			j = 1;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

int	check_double(t_duo *duo, int size)
{
	int	i;
	int	j;

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
