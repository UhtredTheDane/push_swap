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
 * Allocates and returns a new empty stack.
 * The member variable content is uninitialized because it is a empty stack. 
 * The variable previous is initialized to NULL.
 */

t_stack	*ft_lstnew(void *content)
{
	t_stack	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = NULL;
	res->previous = NULL;
	return (res);
}
