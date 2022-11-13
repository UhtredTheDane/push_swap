/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:07:04 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/13 19:18:13 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_duo
{
	int				value;
	int				index;
}	t_duo;

void easy_sort(t_stack **stack, size_t size);
void sort_radix (t_stack **a, size_t size);
int resolve_sort(int *tab, t_duo *duo, size_t position, size_t duo_size);
void reverse_operation(int *tab, t_duo *duo, size_t position, size_t i);
void choose_operation(t_duo *duo, size_t duo_size, size_t i);
void hard_sort(t_stack **a, t_duo *duo, size_t size);
int is_duo_sort(t_duo *duo, size_t duo_size);
void	duo_swap(t_duo *duo, size_t duo_size);
void duo_rotate(t_duo *duo, size_t duo_size);
void duo_reverse_rotate(t_duo *duo, size_t duo_size);
void fill_duo(t_duo *int_tab, char **argv, size_t size);
void pre_sort_duo(t_duo *duo, int size);
void make_sort(t_stack *a, t_duo *int_tab, size_t size);
int	check_argv(int argc, char **argv);
int	check_double(int size, t_duo *int_tab);
void swap_a(t_stack **stack);
void rotate_a(t_stack **stack);
void reverse_rotate_a(t_stack **stack);
void push_b(t_stack **a, t_stack **b);
void push_a(t_stack **b, t_stack **a);
t_stack	*ft_stacknew(int content, int index);
void	ft_stack_add(t_stack **stack, t_stack *new);
int	ft_stacksize(t_stack *stack);
void fill_stack(t_stack *a, t_duo *int_tab, size_t size);
void show_stack(t_stack *stack);
size_t	ft_strlen(char	*s);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int is_useless(int *tab, size_t position, size_t i);
int is_sort(t_stack *stack);
int	ft_printf(const char *format, ...);

#endif
