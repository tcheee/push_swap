/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:20:58 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/09 18:11:44 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		get_elem(t_stack *stack, int *tmp0, int *tmp1)
{
	t_stack *new;

	new = stack;
	*tmp0 = new->nb;
	new = new->next;
	*tmp1 = new->nb;
}

static void		ft_swap(t_stack **stack)
{
	int		tmp0;
	int		tmp1;
	t_stack	*first;

	first = *stack;
	get_elem(first, &tmp0, &tmp1);
	(first)->nb = tmp1;
	first = (first)->next;
	(first)->nb = tmp0;
}

void			do_op_swap(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && c == 'a')
	{
		ft_swap(&(*stack_a));
	}
	if (ft_lstsize(*stack_b) > 1 && c == 'b')
	{
		ft_swap(&(*stack_b));
	}
	if (c == 'c')
	{
		if (ft_lstsize(*stack_a) > 1)
			ft_swap(&(*stack_a));
		if (ft_lstsize(*stack_b) > 1)
			ft_swap(&(*stack_b));
	}
}
