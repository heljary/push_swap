/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:58:54 by heljary           #+#    #+#             */
/*   Updated: 2025/02/20 18:19:34 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	insert_first(stack_b, temp->number);
	free(temp);
	ft_putstr("pb\n");
}

void	pa(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	insert_first(stack_a, temp->number);
	free(temp);
	ft_putstr("pa\n");
}
