/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:18:28 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/13 19:07:34 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(char	*s)
{
	size_t size;

	size = 0;
	while (*(s + size))
		++size;
	return (size);
}

/*
 *Description:
 *
 * Checks for a digit.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* 
 * Description:
 * 
 * Converts the initial portion of the string pointed to nptr 
 * to int representation. Remarque: atol ???
 */

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		negatif;
	int		res;

	i = 0;
	negatif = 0;
	if (*(nptr + i) == '-')
	{
		++i;
		negatif = 1;
	}
	res = 0;
	while (*(nptr + i))
	{
		res += *(nptr + i) - '0';
		++i;
		if (*(nptr + i))
			res *= 10;
	}
	if (negatif)
		res *= -1;
	return (res);
}    

int is_useless(int *tab, size_t position, size_t i)
{
	if (position > 0)
	{
		if (i == 1)
			return (tab[position - 1] == 1);
		else if (i == 2)
			return (tab[position - 1] == 3);
		else
			return (tab[position - 1] == 2);
	}
	return (0);
}

int is_sort(t_stack *stack)
{
	t_stack *elem;
	size_t	i;

	elem = stack;
	i = 0;
	while (elem)
	{
		if (elem->index != i)
			return (0);
		++i;
		elem = elem->next;
	}
	return (1);
}
