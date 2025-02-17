/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:59 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 18:27:32 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_push_swap **stack_a)
{
	t_push_swap	*nxt;
	t_push_swap	*first;

	if (*stack_a == NULL)
		return ;
	if (stack_size(*stack_a) == 1)
		return ;
	nxt = *stack_a;
	while (nxt->next != NULL)
		nxt = nxt->next;
	first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	nxt->next = first;
	first->next = NULL;
}

void	rb(t_push_swap **stack_b)
{
	t_push_swap	*head;
	t_push_swap	*first;

	if (*stack_b == NULL)
		return ;
	if (stack_size(*stack_b) == 1)
		return ;
	head = (*stack_b);
	while (head->next != NULL)
		head = head->next;
	first = (*stack_b);
	*stack_b = (*stack_b)->next;
	head->next = first;
	first->next = NULL;
}

void	rr(t_push_swap **stack_a, t_push_swap **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
