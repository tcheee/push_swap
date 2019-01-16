/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:20:03 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/10 16:22:38 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_last_elem(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->nb);
}
