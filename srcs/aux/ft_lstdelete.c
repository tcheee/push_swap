/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:44:11 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 16:04:52 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		lst_delete(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (*stack_a != NULL)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (*stack_b != NULL)
	{
		while (*stack_b)
		{
			tmp1 = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp1;
		}
	}
}
