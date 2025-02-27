/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:33 by heljary           #+#    #+#             */
/*   Updated: 2025/02/23 16:48:56 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"
#include <string.h>

void	checker_function(t_push_swap **stack_a, char *line)
{
	ft_putstr("Error: Invalid instruction\n");
	free(line);
	free_stack(*stack_a);
	exit(1);
}

void	norm(t_push_swap **stack_a, t_push_swap **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		checker_function(stack_a, line);
}

void	ft_get_line_from_stdin(t_push_swap **stack_a, t_push_swap **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if ((!line))
			break ;
		norm(stack_a, stack_b, line);
		free(line);
	}
}

t_push_swap	*ft_parsing(int ac, char **av, int i, int j)
{
	int			num;
	char		**args;
	t_push_swap	*stack_a;

	stack_a = NULL;
	while (i < ac)
	{
		if (!ft_isalnum(av[i]))
			function_exit(NULL, stack_a);
		args = ft_split(av[i], ' ');
		j = 0;
		while (args[j])
		{
			num = ft_atoi(args[j], args, stack_a);
			if (!is_validnumber(args[j]))
				function_exit(args, stack_a);
			else if (is_dupliacte(stack_a, num))
				function_exit(args, stack_a);
			insert_last(&stack_a, num);
			j++;
		}
		i++;
		ft_free_split(args);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_push_swap	*stack_a;
	t_push_swap	*stack_b;
	int			i;
	int			j;

	stack_b = NULL;
	i = 1;
	j = 0;
	if (ac == 1)
		exit(0);
	stack_a = ft_parsing(ac, av, i, j);
	ft_get_line_from_stdin(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (stack_b)
		free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}
