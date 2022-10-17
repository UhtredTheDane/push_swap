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

t_stack	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = NULL;
	res->next = NULL;
	return (res);
}
