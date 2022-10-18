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
	return (res);
}

t_list *push_front(t_list **lst, int new_value, int index)
{
	t_list *new;
	
	if (lst && *lst)
	{
		if(!*lst->value)
			*lst->value = new_value;
		else
		{
			new = malloc(sizeof(t_list));
			if (!new)
				return (NULL);
			new->value = new->value;
			new->index = index;
			new->next = *lst;
			*lst = new;
		}
		return (*lst);
	}
	return (NULL);
}
