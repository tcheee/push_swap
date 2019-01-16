/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:10:30 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/16 17:20:05 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		get_option(char **av, int *v, int *c, char **line)
{
	*v = 0;
	*c = 0;
	if (av[1] && av[2])
	{
		if (ft_strcmp(av[1], "-v") == 0 || ft_strcmp(av[2], "-v") == 0)
			*v = 1;
		if (ft_strcmp(av[1], "-c") == 0 || ft_strcmp(av[2], "-c") == 0)
			*c = 1;
	}
	*line = NULL;
}

static void		do_option(int *v, int *c, t_stack *stack_a, t_stack *stack_b)
{
	if (*c > 0)
		(*c)++;
	if (*v == 1)
		ft_printer_stack(stack_a, stack_b, *c);
}

static int		return_bad_op(t_stack **stack_a, t_stack **stack_b)
{
	lst_delete(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

static int		good_ender(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (*stack_a == NULL && *stack_b == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		lst_delete(stack_a, stack_b);
		return (-1);
	}
	if (ft_checker(*stack_a) == 0 && ft_lstsize(*stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (c > 0)
		ft_printf("Le nombre d'operations est de : %d\n", c - 1);
	lst_delete(stack_a, stack_b);
	return (0);
}

int				main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			v;
	int			c;
	char		*line;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	get_option(av, &v, &c, &line);
	if (create_stack_checker(&stack_a, &stack_b, av, ac) == -1)
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (do_op(line, &stack_a, &stack_b) == -1)
		{
			ft_strdel(&line);
			return (return_bad_op(&stack_a, &stack_b));
		}
		do_option(&v, &c, stack_a, stack_b);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (good_ender(&stack_a, &stack_b, c));
}
