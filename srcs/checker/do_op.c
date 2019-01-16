/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:37:09 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/14 11:02:59 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_valid(char *oper)
{
	if (ft_strcmp(oper, "sa") == 0)
		return (0);
	else if (ft_strcmp(oper, "sb") == 0)
		return (0);
	else if (ft_strcmp(oper, "ss") == 0)
		return (0);
	else if (ft_strcmp(oper, "pa") == 0)
		return (0);
	else if (ft_strcmp(oper, "pb") == 0)
		return (0);
	else if (ft_strcmp(oper, "ra") == 0)
		return (0);
	else if (ft_strcmp(oper, "rb") == 0)
		return (0);
	else if (ft_strcmp(oper, "rr") == 0)
		return (0);
	else if (ft_strcmp(oper, "rra") == 0)
		return (0);
	else if (ft_strcmp(oper, "rrb") == 0)
		return (0);
	else if (ft_strcmp(oper, "rrr") == 0)
		return (0);
	return (-1);
}

int			do_op(char *oper, t_stack **stack_a, t_stack **stack_b)
{
	if (check_valid(oper) == -1)
		return (-1);
	if (ft_strcmp(oper, "sa") == 0)
		do_op_swap(&(*stack_a), &(*stack_b), 'a');
	else if (ft_strcmp(oper, "sb") == 0)
		do_op_swap(&(*stack_a), &(*stack_b), 'b');
	else if (ft_strcmp(oper, "ss") == 0)
		do_op_swap(&(*stack_a), &(*stack_b), 'c');
	else if (ft_strcmp(oper, "pa") == 0)
		do_op_push(&(*stack_a), &(*stack_b), 'a');
	else if (ft_strcmp(oper, "pb") == 0)
		do_op_push(&(*stack_a), &(*stack_b), 'b');
	else if (ft_strcmp(oper, "ra") == 0)
		do_op_rotate(&(*stack_a), &(*stack_b), 'a');
	else if (ft_strcmp(oper, "rb") == 0)
		do_op_rotate(&(*stack_a), &(*stack_b), 'b');
	else if (ft_strcmp(oper, "rr") == 0)
		do_op_rotate(&(*stack_a), &(*stack_b), 'c');
	else if (ft_strcmp(oper, "rra") == 0)
		do_op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
	else if (ft_strcmp(oper, "rrb") == 0)
		do_op_reverse_rotate(&(*stack_a), &(*stack_b), 'b');
	else if (ft_strcmp(oper, "rrr") == 0)
		do_op_reverse_rotate(&(*stack_a), &(*stack_b), 'c');
	return (0);
}
