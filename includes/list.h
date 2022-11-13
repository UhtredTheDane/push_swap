#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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

size_t	ft_strlen(char	*s);
int	ft_isdigit(int c);
int	check_argv(int argc, char **argv);
int	ft_atoi(const char *nptr);
int	check_double(int size, t_duo *int_tab);
void pre_sort_duo(t_duo *duo, int size);
int is_duo_sort(t_duo *duo, size_t duo_size);
int is_sort(t_list *lst);
void easy_sort(t_list **lst, size_t size);
void sort_radix (t_list **a, size_t size);
void	duo_swap(t_duo *duo, size_t duo_size);
void duo_rotate(t_duo *duo, size_t duo_size);
void duo_reverse_rotate(t_duo *duo, size_t duo_size);
int is_useless(int *tab, size_t position, size_t i);
int resolve_sort(int *tab, t_duo *duo, size_t position, size_t duo_size);
void hard_sort(t_list **a, t_duo *duo, size_t size);
int	make_operation(int *tab, t_duo *duo, size_t position, size_t duo_size);
void make_sort(t_list *a, t_duo *int_tab, size_t size);
t_list *ft_lstnew(int, int);
void ft_lstadd_front(t_list **, t_list *);
void swap_a(t_list **);
void rotate_a(t_list **);
void reverse_rotate_a(t_list **);
void show_list(t_list *);
int ft_lstsize(t_list *);
void push_a(t_list **, t_list **);
void push_b(t_list **, t_list **);