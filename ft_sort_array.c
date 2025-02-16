/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:01:47 by heljary           #+#    #+#             */
/*   Updated: 2025/02/15 19:04:24 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bouble_sort(int *table, int len, int i)
{
	int	j;
	int	k;

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (table[i] > table[j])
			{
				k = table[j];
				table[j] = table[i];
				table[i] = k;
			}
			j++;
		}
		i++;
	}
	return (table);
}

int	*sort_array(t_push_swap **stack_a)
{
	int			size;
	int			*table;
	int			i;
	t_push_swap	*temp;
	int			len;

	size = stack_size(*stack_a);
	table = malloc(size * sizeof(int));
	if (!table)
		return (NULL);
	i = 0;
	temp = *stack_a;
	while (temp)
	{
		table[i++] = temp->number;
		temp = temp->next;
	}
	len = i;
	i = 0;
	bouble_sort(table, len, i);
	return (table);
}
