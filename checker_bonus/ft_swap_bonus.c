/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:54:31 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 18:27:59 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_push_swap **stack_a)
{
	t_push_swap	*head;
	t_push_swap	*ptr1;

	if (stack_size(*stack_a) < 2)
	{
		return ;
	}
	head = *stack_a;
	ptr1 = head->next;
	head->next = ptr1->next;
	ptr1->next = head;
	*stack_a = ptr1;
}

void	sb(t_push_swap **stack_b)
{
	t_push_swap	*head;
	t_push_swap	*ptr1;

	if (stack_size(*stack_b) < 2)
	{
		return ;
	}
	head = *stack_b;
	ptr1 = head->next;
	head->next = ptr1->next;
	ptr1->next = head;
	*stack_b = ptr1;
}

void	ss(t_push_swap **stack_a, t_push_swap **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
