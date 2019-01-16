/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:40:10 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/09 10:42:11 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		the_checker(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	if (stack_b != NULL)
		return (-1);
	tmp = stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->nb > (tmp->next)->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
