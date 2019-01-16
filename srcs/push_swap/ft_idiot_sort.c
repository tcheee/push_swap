/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:11:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/11 18:50:14 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		give_value(int *a, int *b, int *c, t_stack **stack_a)
{
	t_stack *tmp;

	tmp = *stack_a;
	*a = tmp->nb;
	tmp = tmp->next;
	*b = tmp->nb;
	tmp = tmp->next;
	*c = tmp->nb;
}

static void		ft_three_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	int		c;

	give_value(&a, &b, &c, stack_a);
	if (a < b && b < c)
		return ;
	if (a < b && c < b && a < c)
	{
		op_reverse_rotate(stack_a, stack_b, 'a');
		op_swap(stack_a, stack_b, 'a');
	}
	else if (a < b && c < a && c < b)
		op_reverse_rotate(stack_a, stack_b, 'a');
	else if (a < c && b < c && b < a)
		op_swap(stack_a, stack_b, 'a');
	else if (b < c && c < a && b < a)
		op_rotate(stack_a, stack_b, 'a');
	else if (c < a && b < a && c < b)
	{
		op_swap(stack_a, stack_b, 'a');
		op_reverse_rotate(stack_a, stack_b, 'a');
	}
}

static void		sort_the_rest(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		ft_three_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 2)
		if (ft_checker(*stack_a) != 0)
			op_swap(stack_a, stack_b, 'a');
}

void			ft_idiot_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *tmp1;
	int		val;
	int		i;

	while (ft_lstsize(*stack_a) > 3)
	{
		i = 1;
		tmp = *stack_a;
		tmp1 = *stack_a;
		val = (*stack_a)->nb;
		val = get_min(tmp, &i);
		if (i <= ft_lstsize(*stack_a) / 2)
			while (tmp1->nb != val)
				op_rotate(&(*stack_a), &(*stack_b), 'a');
		else
			while (tmp1->nb != val)
				op_reverse_rotate(&(*stack_a), &(*stack_b), 'a');
		op_push(&(*stack_a), &(*stack_b), 'b');
	}
	sort_the_rest(stack_a, stack_b);
	while (ft_lstsize(*stack_b) != 0)
		op_push(stack_a, stack_b, 'a');
}
