/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:19:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/10 16:22:30 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_min(t_stack *stack, int *i)
{
	int		min;
	int		j;
	t_stack	*tmp;

	tmp = stack;
	min = tmp->nb;
	j = 1;
	while (tmp != NULL)
	{
		if (tmp->nb < min)
		{
			*i = j;
			min = tmp->nb;
		}
		tmp = tmp->next;
		j++;
	}
	return (min);
}
