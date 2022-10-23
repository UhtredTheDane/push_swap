/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/23 19:03:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../includes/list.h"

t_list *ft_lstnew(int, int);
void ft_lstadd_front(t_list **, t_list *);
void swap_a(t_list **);
void rotate_a(t_list **);
void reverse_rotate_a(t_list **);
void show_list(t_list *);
int ft_lstsize(t_list *);
void push_a(t_list **, t_list **);
void push_b(t_list **, t_list **);

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

int is_sort(t_list *lst)
{
	t_list *elem;
	size_t	i;

	elem = lst;
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

void easy_sort(t_list **lst, size_t size)
{
	while (!is_sort(*lst))
	{
		if ((*lst)->index == size)
	       		rotate_a(lst);	
		else if ((*lst)->next->index == size)
			reverse_rotate_a(lst);
		else if ((*lst)->index > (*lst)->next->index)
			swap_a(lst);
	}
}

void sort_radix (t_list **a, size_t size)
{
	t_list *b;
	size_t n;
	size_t	i;

	b = NULL;
	n = 0;
	while (!is_sort(*a))
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index)>>n)&1)
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
	t_duo *duo_elem;

	if (position == 5)
		return (1);
	if (tab[position] != 0)
		return resolve_sort(tab, duo, position + 1);
	i = 1;
	while (i <= 3)
	{
		if (position <= 5)
		{
			if (i == 1)
			{
				duo_elem = duo[0]
				duo[0] = duo[1];
				duo[1] = duo[0]
			}
			else if (i == 2)
			{
				size_t j = 0;
				duo_elem = duo[0];
				while (j < duo_size - 1)
				{
					duo[j] = duo[j + 1];
					++j;
				}
				duo[j] = duo_elem;
			}
			else
			{
				size_t j = duo_size - 1;
				duo_elem = duo[duo_size - 1];
				while (j > 0)
				{
					duo[j] = duo[j - 1] ;
					--j;
				}
				duo[j] = duo_elem;
			}
			
			tab[position] = i;
			if (duo_is_sort() || resolve_sort(tab, duo, position + 1, duo_size))
				return (1);
		}
	}
	deswap duo;
	tab
	return (0);
}

void hard_sort(t_list **a, t_duo *duo, size_t size)
{
	int tab[5] = {0};

	//swap a= 1
	//ra = 2
	//rra = 3
	
}

int main(int argc, char **argv)
{
	int i;
	size_t	size;
	t_list	*a;
	t_list	*b;
	
	if (argc <= 1)
		return (0);
	size = argc - 1;
	if (!check_argv(size, argv + 1))
		return (0);
	t_duo *int_tab = malloc(sizeof(t_duo) * size);
	i = 0;
	while (i < size)
	{ 
		int_tab[i].value = ft_atoi(argv[i + 1]);
		int_tab[i].index = size - 1;
		++i;
	}
	if (!check_double(size, int_tab))
	{
		free(int_tab);
		return (0);
	}
	pre_sort_duo(int_tab, size);	
	a = NULL;
	i = size - 1;
	t_list *new;
	new = NULL;
	while (i >= 0)
	{
		new = ft_lstnew(int_tab[i].value, int_tab[i].index);
		ft_lstadd_front(&a, new);
		--i;
	}
	show_list(a);
	
	if (size < 4)
		little_sort(&a, size - 1);
	else if (size < 5)
		
	else	
		sort_radix(&a, size);

	show_list(a);
	return (0);
}

