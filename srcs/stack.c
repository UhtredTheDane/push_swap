/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:35 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/15 15:11:19 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
* Description:
*
* Allocates and returns a new empty list.
* The member variable content is uninitialized because it is a empty list. 
* The variable previous is initialized to NULL.
*/

t_stack	*ft_stacknew(int content, int index)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->value = content;
	res->index = index;
	res->next = NULL;
	res->pos = 0;
	return (res);
}

/*
 * Description:
 *
 * Adds the node new at the beginnning of the list.
 */
void	ft_stack_add(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

/*
 * Description:
 *
 * Counts the number of nodes in a list.
 */

int	ft_stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	fill_stack(t_stack **a, t_duo *int_tab, size_t size)
{
	t_stack	*new;
	int		i;

	i = size - 1;
	new = NULL;
	while (i >= 0)
	{
		new = ft_stacknew(int_tab[i].value, int_tab[i].index);
		ft_stack_add(a, new);
		--i;
	}
}

void	show_stack(t_stack *stack)
{
	t_stack	*elem;

	if (stack)
	{
		elem = stack;
		while (elem != NULL)
		{
			ft_printf("%d ", elem->value);
			elem = elem->next;
		}
		ft_printf("\n");
	}
}
