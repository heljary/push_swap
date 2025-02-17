/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_b_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:46:44 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 14:53:53 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlenn(s);
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	stack_size(t_push_swap *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	free_stack(t_push_swap *head)
{
	t_push_swap	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	insert_last(t_push_swap **head, int value)
{
	t_push_swap	*newnode;
	t_push_swap	*current;

	newnode = malloc(sizeof(t_push_swap));
	if (!newnode)
		return ;
	newnode->next = NULL;
	newnode->number = value;
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	if (!head || !*head)
		return ;
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = newnode;
}

void	insert_first(t_push_swap **head, int value)
{
	t_push_swap	*new;

	new = malloc(sizeof(t_push_swap));
	if (!new)
		return ;
	new->number = value;
	new->next = *head;
	*head = new;
}
