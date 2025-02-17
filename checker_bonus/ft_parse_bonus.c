/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:53:33 by heljary           #+#    #+#             */
/*   Updated: 2025/02/17 18:35:18 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"
#include <string.h>

void checker_function()
{
	
}

void ft_print(t_push_swap *head)
{
	while(head)
	{
		printf("%d\n",head ->number);
		head = head -> next;
	}
}

t_push_swap	*ft_parsing(int ac, char **av, int i)
{
	int			j;
	int			num;
	char		**args;
	t_push_swap	*stack_a;

	stack_a = NULL;
	while (i < ac)
	{
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
	stack_a = NULL;
	int			i;

	i = 1;
	if (ac >= 2)
	{
		stack_a = ft_parsing(ac, av, i);
	}

	// ft_print(stack_a);
	if(is_sorted(stack_a))
	{
		exit(1);
	}
	char *line ;
	while ((line = get_next_line(0)) != NULL) 
	{
		line[strcspn(line, "\n")] = '\0';
		if(strcmp(line,"sa") == 0)
			sa(&stack_a);
		else if(strcmp(line,"sb") == 0)
			sb(&stack_b);
		else if(strcmp(line,"ss") == 0)
			ss(&stack_a, &stack_b);
		else if(strcmp(line,"pa") == 0)
			pa(&stack_a, &stack_b);
		else if(strcmp(line,"pb") == 0)
			pb(&stack_a, &stack_b);
		else if(strcmp(line,"ra") == 0)
			ra(&stack_a);
		else if(strcmp(line,"rb") == 0)
			rb(&stack_b);
		else if(strcmp(line,"rr") == 0)
			rr(&stack_a, &stack_b);
		else if(strcmp(line,"rra") == 0)
			rra(&stack_a);
		else if(strcmp(line,"rrb") == 0)
			rrb(&stack_b);
		else if(strcmp(line,"rrr") == 0)
			rrr(&stack_a, &stack_b);
		else {
            ft_putstr("Error: Invalid instruction\n");
            free(line);
            exit(1);
        }
		// ft_print(stack_a);
        free(line);
	}

	if (is_sorted(stack_a)) {
        ft_putstr("OK\n");
    } else {
        ft_putstr("KO\n");
    }
	
	return (0);
}
