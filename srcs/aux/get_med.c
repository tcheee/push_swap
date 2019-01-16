/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_med.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:18:28 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/11 15:31:32 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_med(t_stack *stack)
{
	int		med;
	int		i;
	int		len;
	t_stack *tmp;
	t_stack *tmp1;

	len = ft_lstsize(stack);
	tmp1 = stack;
	while (tmp1 != NULL)
	{
		med = tmp1->nb;
		tmp = stack;
		i = 1;
		while (tmp != NULL)
		{
			if (tmp->nb < med)
				i++;
			tmp = tmp->next;
		}
		if (i == (len / 2) + 1)
			return (med);
		tmp1 = tmp1->next;
	}
	return (med);
}
