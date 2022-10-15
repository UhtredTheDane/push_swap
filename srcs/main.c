/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:55:30 by agengemb          #+#    #+#             */
/*   Updated: 2022/10/15 19:46:00 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Description:
 *
 * Checks for a digit.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_argv(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j = 1;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]))
				return (0);
			j++;
		}
		i++;	
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc <= 1 || !check_argv(argc - 1, argv + 1))
		return (0);
	t_stack *a = ft_stacknew();
	t_stack *b = ft_stacknew();
	if (!a || !b)
		return (0);
	
	return (0);
}
