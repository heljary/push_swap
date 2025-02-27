/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algor_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:21:22 by heljary           #+#    #+#             */
/*   Updated: 2025/02/27 11:24:11 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int value, int size, int *array)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == array[i])
			return (i);
		i++;
	}
	return (-1);
}

void	push_a_to_b(t_push_swap **stack_a, t_push_swap **stack_b, int *table,
		int end)
{
	int	size;
	int	index;

	size = stack_size(*stack_a);
	while (stack_size(*stack_a) > 0)
	{
		index = get_index((*stack_a)->number, size, table);
		if (index <= stack_size(*stack_b))
		{
			pb_rb(stack_a, stack_b);
			end++;
		}
		else if (index <= end)
		{
			pb(stack_a, stack_b);
			if (stack_size(*stack_b) > 1
				&& (*stack_b)->number < (*stack_b)->next->number)
			{
				sb(stack_b, "sb\n");
			}
			end++;
		}
		else
			ra(stack_a, "ra\n");
	}
}

void	algo_push_a_in_b(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int	size;
	int	end;
	int	*table;

	if (!stack_a || !(*stack_a))
		return ;
	table = sort_array(stack_a);
	end = 0;
	size = stack_size(*stack_a);
	if (!table)
		return ;
	else if (size <= 100)
		end = size / 6;
	else
		end = size / 12;
	push_a_to_b(stack_a, stack_b, table, end);
	free(table);
}

void	check_maxpos_in_b(t_push_swap **stack_b, int max, int pos, int size)
{
	if (pos <= size / 2)
	{
		while ((*stack_b)->number != max)
			rb(stack_b, "rb\n");
	}
	else
		while (stack_size(*stack_b) && (*stack_b)->number != max)
			rrb(stack_b, "rrb\n");
}

void	algorithm_sort(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap		*head;
	int				max;
	int				pos;
	int				i;

	algo_push_a_in_b(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		i = 0;
		head = *stack_b;
		pos = stack_size(*stack_b);
		max = head->number;
		while (head != NULL)
		{
			if (head->number > max)
			{
				max = head->number;
				pos = i;
			}
			head = head->next;
			i++;
		}
		check_maxpos_in_b(stack_b, max, pos, stack_size(*stack_b));
		pa(stack_a, stack_b);
	}
}
