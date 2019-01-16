/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:52:03 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/15 16:28:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_stack
{
	int					nb;
	struct s_stack		*next;
}						t_stack;

/*
** PUSH_SWAP
*/

void					ft_idiot_sort(t_stack **stack_a, t_stack **stack_b);
void					ft_simple_sort(t_stack **stack_a, t_stack **stack_b);
void					ft_cut_sort_a(t_stack **stack_a, t_stack **stack_b);
void					ft_cut_sort_b(t_stack **stack_a, t_stack **stack_b);
void					ft_quick_sort(t_stack **stack_a, t_stack **stack_b,
		int size);
void					op_swap(t_stack **stack_a, t_stack **stack_b, char c);
void					op_push(t_stack **stack_a, t_stack **stack_b, char c);
void					op_rotate(t_stack **stack_a,
		t_stack **stack_b, char c);
void					op_reverse_rotate(t_stack **stack_a,
		t_stack **stack_b, char c);

/*
** CHECKER
*/

int						create_stack_checker(t_stack **stack_a,
		t_stack **stack_b, char **av, int ac);
int						the_checker(t_stack *stack_a, t_stack *stack_b);
int						do_op(char *oper, t_stack **stack_a, t_stack **stack_b);
void					do_op_swap(t_stack **stack_a, t_stack **stack_b,
		char c);
void					do_op_push(t_stack **stack_a, t_stack **stack_b,
		char c);
void					do_op_rotate(t_stack **stack_a,
		t_stack **stack_b, char c);
void					do_op_reverse_rotate(t_stack **stack_a,
		t_stack **stack_b, char c);

/*
** AUX
*/

int						check_arg(char *av, t_stack **stack_b);
int						check_list(t_stack *stack);
int						ft_lstsize(t_stack *stack);
void					ft_printer_stack(t_stack *stack_a, t_stack *stack_b,
		int c);
int						ft_checker(t_stack *stack);
int						ft_checker_inv(t_stack *stack);
int						ft_checker_size(t_stack *stack, int size);
void					lst_delete(t_stack **stack_a, t_stack **stack_b);
int						get_last_elem(t_stack *stack);
int						get_med(t_stack *stack);
int						get_min(t_stack *stack, int *i);
int						get_max(t_stack *stack, int *i);
void					put_min_at_the_top(t_stack **stack_a,
		t_stack **stack_b);
int						check_inf_med(t_stack *stack_b, int med);
int						check_sup_med(t_stack *stack_b, int med);

#endif
