/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/22 08:10:14 by agengemb         ###   ########.fr       */
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

void three_sort(t_list **lst, size_t size)
{
	if ((*lst)->index == size)
	       rotate_a(lst);	
	else if ((*lst)->next->index == size)
		reverse_rotate_a(lst);
	else if ((*lst)->index > (*lst)->next->index)
		swap_a(lst);
}
/*
void pre_treatment(t_list **a, t_list **b, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			push_b(a, b);
			++i;
		}
		else
			rotate_a(a);
	}
	while (i < size - 3)
	{
		push_b(a, b);
		++i;
	}
}*/

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
	
	sort_radix(&a, size);
	show_list(a);
	return (0);
}

