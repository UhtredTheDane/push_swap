/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:35 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/15 18:59:38 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /*
 * Description:
 *
 * Allocates and returns a new empty list.
 * The member variable content is uninitialized because it is a empty list. 
 * The variable previous is initialized to NULL.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = NULL;
	res->next = NULL;
	res->pos = 0;
	res->target_pos = 0;
	res->cost_a = 0;
	res->cost_b = 0;
	return (res);
}

t_list *push_front(t_list **lst, t_duo *duo)
{
	t_list *new;
	
	if (lst && *lst)
	{
		if(!(*lst)->value)
		{
			(*lst)->value = duo->value;
			(*lst)->index = duo->index;
		}
		else
		{
			new = malloc(sizeof(t_list));
			if (!new)
				return (NULL);
			new->value = duo->value;
			new->index = duo->index;
			new->next = *lst;
			*lst = new;
		}
		return (*lst);
	}
	return (NULL);
}

void swap_a(t_list **lst)
{
	t_list *elem;
	
	if (!lst)
	{
		elem = lst->next;
		lst->next = elem->next;
		elem->next = lst;
		*lst = elem;
	}
	
}
