/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:39:11 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 11:45:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		ft_sort_a(t_stack **stack_a, t_stack **stack_b, int med)
{
	t_stack *tmpa;
	int		last;

	if (check_inf_med(*stack_a, med) == 0)
		return ;
	tmpa = *stack_a;
	last = get_last_elem(tmpa);
	if (last < tmpa->nb)
	{
		op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
		op_push(&(*stack_a), &(*stack_b), 'b');
	}
	else
	{
		op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
		op_swap(&(*stack_a), &(*stack_b), 'a');
	}
	ft_sort_a(stack_a, stack_b, med);
}

void			ft_cut_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		med;
	int		ind;
	t_stack *tmpa;

	tmpa = *stack_a;
	ind = 1;
	med = get_med(*stack_a);
	if (ft_lstsize(*stack_a) <= 2)
		return ;
	while (tmpa != NULL)
	{
		if (ind < ft_lstsize(*stack_a) / 2)
			while ((*stack_a)->nb != med)
				op_rotate(&(*stack_a), &(*stack_b), 'a');
		else
			while ((*stack_a)->nb != med)
				op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
		ind++;
		tmpa = tmpa->next;
	}
	ft_sort_a(stack_a, stack_b, med);
}
