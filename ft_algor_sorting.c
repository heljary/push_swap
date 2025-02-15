/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algor_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:21:22 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 17:52:55 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(t_push_swap **stack_a)
{
	int			size;
	int			*T;
	int			i;
	t_push_swap	*temp;
	int			len;
	int			j;
	int			k;

	size = stack_size(*stack_a);
	T = malloc(size * sizeof(int));
	if (!T)
		return (NULL);
	i = 0;
	temp = *stack_a;
	while (temp)
	{
		T[i++] = temp->number;
		temp = temp->next;
	}
	len = i;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (T[i] > T[j])
			{
				k = T[j];
				T[j] = T[i];
				T[i] = k;
			}
			j++;
		}
		i++;
	}
	return (T);
}

void	algo_sort_small_numbers(t_push_swap **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
	{
		sa(stack_a, "sa\n");
		return ;
	}
	else if (size == 3)
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

void	algo_sort_fivenumbers(t_push_swap **stack_a, t_push_swap **stack_b)
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
	head = (*stack_a);
	if (head->next->number == min)
		while (head != NULL)
		{
			if ((*stack_a)->number != min)
				ra(stack_a, "ra\n");
			head = head->next;
		}
	else
		while (head != NULL)
		{
			if ((*stack_a)->number != min)
				rra(stack_a, "rra\n");
			head = head->next;
		}
	pb(stack_a, stack_b);
	algo_sort_fournumbers(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	algo_sort_fournumbers(t_push_swap **stack_a, t_push_swap **stack_b)
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
	head = (*stack_a);
	if (head->next->number == min)
		while (head != NULL)
		{
			if ((*stack_a)->number != min)
				ra(stack_a, "ra\n");
			head = head->next;
		}
	else
		while (head != NULL)
		{
			if ((*stack_a)->number != min)
				rra(stack_a, "rra\n");
			head = head->next;
		}
	pb(stack_a, stack_b);
	algo_sort_small_numbers(stack_a);
	pa(stack_a, stack_b);
}

void	algo_push_a_in_b(t_push_swap **stack_a, t_push_swap **stack_b)
{
	int	size;
	int	start;
	int	end;
	int	*T;

	if (!stack_a || !(*stack_a))
		return ;
	T = sort_array(stack_a);
	start = 0;
	end = 0;
	size = stack_size(*stack_a);
	if (!T)
		return ;
	if (size <= 5)
	{
		end = size / size;
	}
	else if (size > 5 && size <= 100)
		end = size / 6;
	else if (size > 100 && size <= 500)
		end = size / 12;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->number <= T[start])
		{
			pb(stack_a, stack_b);
			rb(stack_b, "rb\n");
			start++;
			end++;
		}
		else if ((*stack_a)->number <= T[end])
		{
			pb(stack_a, stack_b);
			if (stack_size(*stack_b) > 1
				&& (*stack_b)->number < (*stack_b)->next->number)
			{
				sb(stack_b, "sb\n");
			}
			start++;
			end++;
		}
		else
			ra(stack_a, "ra\n");
	}
	free(T);
}

void	algorithm_sort(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap *head;
	int max;
	int pos;
	int size;
	int i;

	algo_push_a_in_b(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		i = 0;
		head = *stack_b;
		size = stack_size(*stack_b);
		pos = size;
		max = head->number;
		while (head != NULL)
		{
			if (head->number > max)
			{
				max = head->number;
				pos -= i;
			}
			head = head->next;
			i++;
		}
		if (pos >= size / 2)
		{
			while ((*stack_b)->number != max)
				rb(stack_b, "rb\n");
		}
		else
			while (stack_size(*stack_b) && (*stack_b)->number != max)
				rrb(stack_b, "rrb\n");
		pa(stack_a, stack_b);
	}
}