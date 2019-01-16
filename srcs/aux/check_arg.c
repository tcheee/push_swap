/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:53:39 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/16 17:20:30 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		str_is_digit(char *str)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		a = 1;
		i++;
	}
	if (a == 1 && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int				check_arg(char *av, t_stack **stack_a)
{
	t_stack *new;
	t_stack *last;

	if (str_is_digit(av) == -1)
		return (-1);
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	new->nb = ft_atoi(av);
	new->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return (0);
	}
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (0);
}
