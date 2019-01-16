/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:02:58 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 11:56:26 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_med(t_stack *stack, int size)
{
	int		med;
	int		i;
	t_stack *tmp;
	t_stack *tmp1;

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
		if (i == (size / 2) + 1)
			return (med);
		tmp1 = tmp1->next;
	}
	return (med);
}

static int	ft_partition(t_stack **stack_a, t_stack **stack_b,
		int size, int med)
{
	int i;

	i = 0;
	while (size > 0)
	{
		if ((*stack_a)->nb >= med)
		{
			op_rotate(stack_a, stack_b, 'a');
			i++;
		}
		else
			op_push(stack_a, stack_b, 'b');
		size--;
	}
	return (i);
}

void		ft_quick_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		med;
	int		k;
	t_stack	*tmp;

	if (size < 2 || ft_checker_size(*stack_a, size) == 0)
		return ;
	i = 0;
	k = 0;
	tmp = *stack_a;
	med = ft_med(tmp, size);
	i = ft_partition(stack_a, stack_b, size, med);
	while (k < i && tmp != NULL)
	{
		op_reverse_rotate(stack_a, stack_b, 'a');
		k++;
	}
	ft_quick_sort(stack_a, stack_b, i);
	k = size - i;
	while (k > 0)
	{
		op_push(stack_a, stack_b, 'a');
		k--;
	}
	ft_quick_sort(stack_a, stack_b, size - i);
}
