/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duo_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:20:10 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/13 17:20:12 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_duo_sort(t_duo *duo, size_t duo_size)
{
	size_t i;

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
	t_duo elem;

	if (duo_size >= 2)
	{
		elem = duo[0];
		duo[0] = duo[1];
		duo[1] = elem;
	}
}

void duo_rotate(t_duo *duo, size_t duo_size)
{
	t_duo elem;
	size_t i;

	i = 0;
	elem = duo[0];
	while (i < duo_size - 1)
	{
		duo[i] = duo[i + 1];
		++i;
	}
	duo[i] = elem;
}

void duo_reverse_rotate(t_duo *duo, size_t duo_size)
{
	t_duo elem;
	size_t i;

	i = duo_size - 1;
	elem = duo[duo_size - 1];
	while (i > 0)
	{
		duo[i] = duo[i - 1];
		--i;
	}
	duo[i] = elem;
}

void fill_duo(t_duo *int_tab, char **argv, size_t size)
{
	size_t i;
	
	i = 0;
	while (i < size)
	{ 
		int_tab[i].value = ft_atoi(argv[i + 1]);
		int_tab[i].index = size - 1;
		++i;
	}
}
