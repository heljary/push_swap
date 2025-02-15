/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:56:35 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 17:06:36 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap **stack_a, char *s)
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
	ft_putstr(s);
}

void	sb(t_push_swap **stack_b, char *s)
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
	ft_putstr(s);
}

void	ss(t_push_swap **stack_a, t_push_swap **stack_b)
{
	sa(stack_a, NULL);
	sb(stack_b, NULL);
	ft_putstr("ss\n");
}
