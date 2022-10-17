/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/15 19:58:46 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../includes/stack.h"

size_t	ft_strlen(char	*s)
{
	size_t size;

	size = 0;
	while (*(s + size))
		size++;
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

int	check_double(int pos, int argc, char **argv)
{
	
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
			j++;
		}
		i++;	
	}
	return (1);
}
	       
/*
 * Description:
 *
 * Compare not more than n bytes from the array pointed to by s1 to the array 
 * pointed to by s2.
 */


	       
int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
 	t_list	*a = ft_lstnew();
	t_list	*b = ft_lstnew();
	if (!check_argv(argc - 1, argv + 1))
		return (0);	
	int	*temp = malloc(sizeof(int) * (argc - 1))
	return (0);
}
