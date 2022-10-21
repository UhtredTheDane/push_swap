/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/21 02:50:32 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../includes/list.h"

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

int	check_argv(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (!ft_strlen(argv[i]))
			return (0);
		if (argv[i][j] == '-')
			j = 1;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			++j;
		}
		++i;	
	}
	return (1);
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

int	check_double(int size, t_duo *int_tab)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (int_tab[i].value == int_tab[j].value)
				return (0);
			++j;
		}
		++i;
		j = i + 1;
	}
	return (1);
}
		
void pre_sort_duo(t_duo *duo, int size)
{
	size_t	i;
	int  j;
	int	temp_index;
	t_duo *buffer;
	
	i = 1;
	while (i < size)
	{
		j = i - 1;
		buffer = duo + i;
		while (j >= 0 && buffer->value < duo[j].value)
		{
			temp_index = duo[j].index;
			duo[j].index = buffer->index;
			
			buffer->index = temp_index;
			--j;
		}
		++i;
	}
}

int is_sort(t_duo *duo, int size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (duo[i].index != i + 1)
		{	
			
			return (0);
		}
		i++;
	}
	return (1);
}  

int main(int argc, char **argv)
{
	size_t i;
	t_list	*a;
	t_list	*b;
	
	if (argc <= 1)
		return (0);

	if (!check_argv(argc - 1, argv + 1))
		return (0);
	t_duo *int_tab = malloc(sizeof(t_duo) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{ 
		int_tab[i].value = ft_atoi(argv[i + 1]);
		 int_tab[i].index = i + 1;
		++i;
	}
	if (!check_double(argc - 1, int_tab))
	{
		free(int_tab);
		return (0);
	}


	pre_sort_duo(int_tab, argc - 1);
	for(int i = 0; i < argc - 1; i++)
		printf("value duo: %d et index: %d\n", int_tab[i].value, int_tab[i].index);
	
	/*a = ft_lstnew();
	printf("coucou5\n");
	
	i = argc - 1;
	
	while (i > 0)
	{
		a = push_front(&a, int_tab[i]);
		--i;
	}
	if(!is_sort(duo))
	{
		if (argc - 1 == 2)
			swap_a();
		
	}


	b = ft_lstnew();
	
	*/
	return (0);
}
