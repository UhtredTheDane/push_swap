/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:35 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/22 07:36:30 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/list.h"

int ft_lstsize(t_list *);
 /*
 * Description:
 *
 * Allocates and returns a new empty list.
 * The member variable content is uninitialized because it is a empty list. 
 * The variable previous is initialized to NULL.
 */

t_list	*ft_lstnew(int content, int index)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = content;
	res->index = index;
	res->next = NULL;
	res->pos = 0;
	res->target_pos = 0;
	res->cost_a = 0;
	res->cost_b = 0;
	return (res);
}

/*
 * Description:
 *
 * Adds the node new at the beginnning of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;	
		*lst = new;
	}
}

void	pop_front(t_list **lst)
{
	t_list *elem;

	if (*lst && lst)
	{
		elem = *lst;
		*lst = elem->next;
		free(elem);		
	}
}

void swap_a(t_list **lst)
{
	t_list *elem;
	
	if (lst && *lst)
	{
		elem = (*lst)->next;
		(*lst)->next = elem->next;
		elem->next = *lst;
		*lst = elem;
	}
}

void rotate_a(t_list **lst)
{
	t_list *first_elem;
	t_list *elem;

	if (lst && *lst && ft_lstsize(*lst) > 1)
	{
		first_elem = *lst;
		elem = first_elem->next;
		*lst = elem;
		while (elem->next)
			elem = elem->next;
		elem->next = first_elem;
		first_elem->next = NULL;
	}
	printf("ra\n");
}

void reverse_rotate_a(t_list **lst)
{
	t_list *first_elem;
	t_list *elem;

	if (lst && *lst && ft_lstsize(*lst) > 1)
	{
		elem = *lst;
		while (elem->next->next)
			elem = elem->next;
		first_elem = elem->next;
		elem->next = NULL;
		first_elem->next = *lst;
		*lst = first_elem;
	}
}

void push_b(t_list **a, t_list **b)
{
	t_list *elem;
	
	if (a && *a && b)
	{
		elem = *a;
		*a = elem->next;
		elem->next = *b;
		*b = elem;
	}
	printf("pb\n");
}

void push_a(t_list **b, t_list **a)
{
	t_list *elem;

	if (b && *b && a)
	{
		elem = *b;
		*b = elem->next;
		elem->next = *a;
		*a = elem;
	}
	printf("pa\n");
}

/*
 * Description:
 *
 * Counts the number of nodes in a list.
 */

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}


void show_list(t_list *lst)
{
	t_list *elem;

	if (lst)
	{
		elem = lst;
		while (elem != NULL)
		{
			printf("%d ", elem->value);
			elem = elem->next;
		}
		printf("\n");	
	}
}

