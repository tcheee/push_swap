/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:12:15 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 11:16:49 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		error_return(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("Error\n", 2);
	lst_delete(stack_a, stack_b);
	return (-1);
}

int				create_stack_checker(t_stack **stack_a, t_stack **stack_b,
		char **av, int ac)
{
	int i;

	if (ac > 1)
	{
		i = -1;
		if (av[1] && av[2])
		{
			if (ft_strcmp(av[1], "-v") == 0 || ft_strcmp(av[1], "-c") == 0)
				i++;
			if (ft_strcmp(av[2], "-v") == 0 || ft_strcmp(av[2], "-c") == 0)
				i++;
		}
		while (++i < ac - 1)
		{
			if ((check_arg(av[i + 1], stack_a) == -1))
				return (error_return(stack_a, stack_b));
		}
		if (check_list(*stack_a) == -1)
			return (error_return(stack_a, stack_b));
	}
	return (0);
}
