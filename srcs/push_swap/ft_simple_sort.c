/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:08:11 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/14 19:08:13 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	int		min;
	int		i;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	i = 0;
	tmp = *stack_a;
	min = get_min(tmp, &i);
	if (i < ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->nb != min)
			op_rotate(&(*stack_a), &(*stack_b), 'a');
	else
		while ((*stack_a)->nb != min)
			op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
	op_push(stack_a, stack_b, 'b');
	sort_stack_a(stack_a, stack_b);
}

static void		finish_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;
	int		i;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	i = 0;
	tmp = *stack_b;
	max = get_max(tmp, &i);
	if (i < ft_lstsize(*stack_b) / 2)
		while ((*stack_b)->nb != max)
			op_rotate(&(*stack_a), &(*stack_b), 'b');
	else
		while ((*stack_b)->nb != max)
			op_reverse_rotate(&(*stack_a), &(*stack_b), 'b');
	op_push(stack_a, stack_b, 'a');
	finish_sort(stack_a, stack_b);
}

void			ft_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_cut_sort_a(stack_a, stack_b);
	sort_stack_a(stack_a, stack_b);
	finish_sort(stack_a, stack_b);
}
