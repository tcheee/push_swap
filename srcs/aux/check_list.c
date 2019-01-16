/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:16:15 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/16 16:40:53 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_list(t_stack *stack)
{
	t_stack *tmp;
	t_stack *tmp1;
	int		check;

	tmp = stack;
	tmp1 = stack;
	tmp1 = tmp1->next;
	while (tmp != NULL)
	{
		check = tmp->nb;
		tmp1 = tmp;
		tmp1 = tmp1->next;
		while (tmp1 != NULL)
		{
			if (tmp1->nb == check)
				return (-1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
