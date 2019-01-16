/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:31:29 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/14 17:56:10 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_checker(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
		return (-1);
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->nb > (tmp->next)->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_checker_inv(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
		return (-1);
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->nb < (tmp->next)->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_checker_size(t_stack *stack, int size)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;

	i = 1;
	tmp = stack;
	tmp2 = NULL;
	if (tmp)
	{
		while (i < size && tmp->next)
		{
			tmp2 = tmp->next;
			if (tmp->nb > tmp2->nb)
				return (-1);
			tmp = tmp->next;
			i++;
		}
		return (0);
	}
	return (-1);
}
