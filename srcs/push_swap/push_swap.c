/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:10:30 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 11:13:04 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		error_ender(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("Error\n", 2);
	lst_delete(stack_a, stack_b);
	return (-1);
}

static int		create_stack(t_stack **stack_a, t_stack **stack_b,
		char **av, int ac)
{
	int i;

	if (ac == 1)
		return (-1);
	i = -1;
	while (++i < ac - 1)
	{
		if ((check_arg(av[i + 1], stack_a) == -1))
			return (error_ender(stack_a, stack_b));
	}
	if (check_list(*stack_b) == -1)
		return (error_ender(stack_a, stack_b));
	return (0);
}

int				main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (create_stack(&stack_a, &stack_a, av, ac) == -1)
		return (-1);
	if (ft_checker(stack_a) != 0)
	{
		if (ft_lstsize(stack_a) < 55)
			ft_idiot_sort(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) < 200)
			ft_simple_sort(&stack_a, &stack_b);
		else
			ft_quick_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
	}
	lst_delete(&stack_a, &stack_b);
	return (0);
}
