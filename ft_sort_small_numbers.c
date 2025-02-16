/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:28:52 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 19:03:43 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sort_small_numbers(t_push_swap **stack_a)
{
	if (stack_size(*stack_a) == 2)
	{
		sa(stack_a, "sa\n");
		return ;
	}
	if (stack_size(*stack_a) == 3)
	{
		if ((*stack_a)->number > (*stack_a)->next->number
			&& (*stack_a)->number > (*stack_a)->next->next->number)
			ra(stack_a, "ra\n");
		if ((*stack_a)->number > (*stack_a)->next->number
			&& (*stack_a)->number < (*stack_a)->next->next->number)
			sa(stack_a, "sa\n");
		if ((*stack_a)->number < (*stack_a)->next->number
			&& (*stack_a)->number > (*stack_a)->next->next->number)
			rra(stack_a, "rra\n");
		if ((*stack_a)->number < (*stack_a)->next->number
			&& (*stack_a)->next->number > (*stack_a)->next->next->number)
		{
			sa(stack_a, "sa\n");
			ra(stack_a, "ra\n");
		}
	}
}

int	check_min(t_push_swap **stack_a)
{
	t_push_swap	*head;
	int			min;

	head = (*stack_a);
	min = head->number;
	while (head != NULL)
	{
		if (head->number < min)
			min = head->number;
		head = head->next;
	}
	return (min);
}

void	algo_sort_fivenumbers(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*head;

	head = (*stack_a);
	if (head->next->number == check_min(stack_a))
	{
		while (head != NULL)
		{
			if ((*stack_a)->number != check_min(stack_a))
				ra(stack_a, "ra\n");
			head = head->next;
		}
	}
	else
	{
		while (head != NULL)
		{
			if ((*stack_a)->number != check_min(stack_a))
				rra(stack_a, "rra\n");
			head = head->next;
		}
	}
	pb(stack_a, stack_b);
	algo_sort_fournumbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	algo_sort_fournumbers(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*head;

	head = (*stack_a);
	if (head->next->number == check_min(stack_a))
	{
		while (head != NULL)
		{
			if ((*stack_a)->number != check_min(stack_a))
				ra(stack_a, "ra\n");
			head = head->next;
		}
	}
	else
	{
		while (head != NULL)
		{
			if ((*stack_a)->number != check_min(stack_a))
				rra(stack_a, "rra\n");
			head = head->next;
		}
	}
	pb(stack_a, stack_b);
	algo_sort_small_numbers(stack_a);
	pa(stack_a, stack_b);
}
