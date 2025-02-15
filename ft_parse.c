/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:20:57 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 17:05:14 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_push_swap *stack_a)
{
	while (stack_a != NULL)
	{
		ft_putnbr(stack_a->number);
		ft_putchar('\n');
		stack_a = stack_a->next;
	}
}

int	is_sorted(t_push_swap *head)
{
	int	num;

	if (head == NULL)
	{
		return (1);
	}
	num = head->number;
	head = head->next;
	while (head != NULL)
	{
		if (num > head->number)
		{
			return (0);
		}
		num = head->number;
		head = head->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_push_swap	*stack_a;
	t_push_swap	*stack_b;
	int			i;
	int			j;
	int			num;
	int			size;
	char		**args;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			args = ft_split(av[i], ' ');
			j = 0;
			while (args[j])
			{
				num = ft_atoi(args[j]);
				if (!is_validnumber(args[j]))
					function_exit();
				else if (is_dupliacte(stack_a, num))
					function_exit();
				insert_last(&stack_a, num);
				j++;
			}
			i++;
		}
		ft_free_split(args);
	}
	if (is_sorted(stack_a))
		exit(1);
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
	return (0);
}
