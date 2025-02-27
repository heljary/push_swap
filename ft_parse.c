/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:20:57 by heljary           #+#    #+#             */
/*   Updated: 2025/02/23 17:05:45 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_rb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	pb(stack_a, stack_b);
	rb(stack_b, "rb\n");
}

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_push_swap	*ft_parsing(int ac, char **av, int i, int j)
{
	int			num;
	char		**args;
	t_push_swap	*stack_a;

	stack_a = NULL;
	while (i < ac)
	{
		if (!ft_isalnum(av[i]))
			function_exit(NULL, stack_a);
		args = ft_split(av[i], ' ');
		j = 0;
		while (args[j])
		{
			num = ft_atoi(args[j], args, stack_a);
			if (!is_validnumber(args[j]))
				function_exit(args, stack_a);
			else if (is_dupliacte(stack_a, num))
				function_exit(args, stack_a);
			insert_last(&stack_a, num);
			j++;
		}
		i++;
		ft_free_split(args);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_push_swap	*stack_b;
	t_push_swap	*stack_a;
	int			size;
	int			i;
	int			j;

	stack_b = NULL;
	i = 1;
	j = 0;
	if (ac == 1)
		exit(1);
	stack_a = ft_parsing(ac, av, i, j);
	if (is_sorted(stack_a))
		(free_stack(stack_a), exit(0));
	size = stack_size(stack_a);
	if (size > 5)
		algorithm_sort(&stack_a, &stack_b);
	if (size == 4)
		algo_sort_fournumbers(&stack_a, &stack_b);
	if (size == 5)
		algo_sort_fivenumbers(&stack_a, &stack_b);
	if (size == 2 || size == 3)
		algo_sort_small_numbers(&stack_a);
	free_stack(stack_a);
}
