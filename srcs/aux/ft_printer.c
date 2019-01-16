/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:26:19 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/14 19:03:45 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		ft_printer(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
		return ;
	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("          %d\n", tmp->nb);
		tmp = tmp->next;
	}
}

void			ft_printer_stack(t_stack *stack_a, t_stack *stack_b, int c)
{
	system("clear");
	ft_printf("-------------------------\n");
	ft_printf("\n        STACK A \n\n");
	if (stack_a != NULL)
		ft_printer(stack_a);
	ft_printf("\n-------------------------\n");
	ft_printf("\n        STACK B \n\n");
	if (stack_b != NULL)
		ft_printer(stack_b);
	ft_printf("\n-------------------------\n");
	if (c > 0)
		ft_printf("Nombre d'operations : +%d\n", c - 1);
	usleep(100000);
}
