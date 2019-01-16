/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:21:33 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/10 18:47:43 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		delete_elem_origin(t_stack **stack)
{
	t_stack *elem_to_del;

	elem_to_del = *stack;
	*stack = (*stack)->next;
	free(elem_to_del);
}

static void		ft_push(t_stack **stack_or, t_stack **stack_dest)
{
	t_stack	*new;
	t_stack	*previous_first;

	previous_first = *stack_dest;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	new->nb = (*stack_or)->nb;
	new->next = previous_first;
	*stack_dest = new;
	delete_elem_origin(&(*stack_or));
}

void			op_push(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (*stack_b != NULL && c == 'a')
	{
		ft_push(&(*stack_b), &(*stack_a));
		ft_printf("pa\n");
	}
	if (*stack_a != NULL && c == 'b')
	{
		ft_push(&(*stack_a), &(*stack_b));
		ft_printf("pb\n");
	}
}
