/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inf_med.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:36:19 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/11 15:37:14 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_inf_med(t_stack *stack_b, int med)
{
	t_stack *tmp;

	tmp = stack_b;
	while (tmp != NULL)
	{
		if (tmp->nb < med)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
