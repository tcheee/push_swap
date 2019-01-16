/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:31:10 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/09 16:19:54 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		ft_rotate(t_stack **stack)
{
	int			first_elem;
	t_stack		*tmp_mod;
	t_stack		*one_after;

	tmp_mod = *stack;
	first_elem = (*stack)->nb;
	one_after = (*stack)->next;
	while ((tmp_mod)->next != NULL)
	{
		tmp_mod->nb = one_after->nb;
		tmp_mod = tmp_mod->next;
		one_after = one_after->next;
	}
	tmp_mod->nb = first_elem;
	tmp_mod->next = NULL;
}

void			op_rotate(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && c == 'a')
	{
		ft_rotate(&(*stack_a));
		ft_printf("ra\n");
	}
	if (ft_lstsize(*stack_b) > 1 && c == 'b')
	{
		ft_rotate(&(*stack_b));
		ft_printf("rb\n");
	}
	if (c == 'c')
	{
		if (ft_lstsize(*stack_a) > 1)
			ft_rotate(&(*stack_a));
		if (ft_lstsize(*stack_b) > 1)
			ft_rotate(&(*stack_b));
		if (ft_lstsize(*stack_a) > 1 || ft_lstsize(*stack_b) > 1)
			ft_printf("rr\n");
	}
}
