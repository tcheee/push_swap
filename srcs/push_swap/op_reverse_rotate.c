/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:56:14 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/10 16:24:50 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		last_elem;
	int		a;
	int		b;

	tmp = *stack;
	last_elem = get_last_elem(*stack);
	b = tmp->nb;
	while (tmp->next != NULL)
	{
		a = b;
		tmp = tmp->next;
		b = tmp->nb;
		tmp->nb = a;
	}
	tmp->next = NULL;
	(*stack)->nb = last_elem;
}

void			op_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && c == 'a')
	{
		ft_reverse_rotate(&(*stack_a));
		ft_printf("rra\n");
	}
	if (ft_lstsize(*stack_b) > 1 && c == 'b')
	{
		ft_reverse_rotate(&(*stack_b));
		ft_printf("rrb\n");
	}
	if (c == 'c')
	{
		if (ft_lstsize(*stack_a) > 1)
			ft_reverse_rotate(&(*stack_a));
		if (ft_lstsize(*stack_b) > 1)
			ft_reverse_rotate(&(*stack_b));
		if (ft_lstsize(*stack_a) > 1 || ft_lstsize(*stack_b) > 1)
			ft_printf("rrr\n");
	}
}
