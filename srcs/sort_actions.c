/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:16:43 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/13 17:16:45 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void swap_a(t_stack **stack)
{
	t_stack *elem;
	
	if (stack && *stack)
	{
		elem = (*stack)->next;
		(*stack)->next = elem->next;
		elem->next = *stack;
		*stack = elem;
	}
	printf("sa\n");
}

void rotate_a(t_stack **stack)
{
	t_stack *first_elem;
	t_stack *elem;

	if (stack && *stack && ft_stacksize(*stack) > 1)
	{
		first_elem = *stack;
		elem = first_elem->next;
		*stack = elem;
		while (elem->next)
			elem = elem->next;
		elem->next = first_elem;
		first_elem->next = NULL;
	}
	printf("ra\n");
}

void reverse_rotate_a(t_stack **stack)
{
	t_stack *first_elem;
	t_stack *elem;

	if (stack && *stack && ft_stacksize(*stack) > 1)
	{
		elem = *stack;
		while (elem->next->next)
			elem = elem->next;
		first_elem = elem->next;
		elem->next = NULL;
		first_elem->next = *stack;
		*stack = first_elem;
	}
	printf("rra\n");
}

void push_b(t_stack **a, t_stack **b)
{
	t_stack *elem;
	
	if (a && *a && b)
	{
		elem = *a;
		*a = elem->next;
		elem->next = *b;
		*b = elem;
	}
	printf("pb\n");
}

void push_a(t_stack **b, t_stack **a)
{
	t_stack *elem;

	if (b && *b && a)
	{
		elem = *b;
		*b = elem->next;
		elem->next = *a;
		*a = elem;
	}
	printf("pa\n");
}