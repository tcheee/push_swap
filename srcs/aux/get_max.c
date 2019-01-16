/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:26:56 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/10 18:28:29 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_max(t_stack *stack, int *i)
{
	int		max;
	int		j;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->nb;
	j = 1;
	while (tmp != NULL)
	{
		if (tmp->nb > max)
		{
			*i = j;
			max = tmp->nb;
		}
		tmp = tmp->next;
		j++;
	}
	return (max);
}
